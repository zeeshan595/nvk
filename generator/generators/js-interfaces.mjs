import fs from "fs";
import nunjucks from "nunjucks";
import Terser from "terser";

import pkg from "../../package.json";

import {
  warn,
  getPlatform,
  isPNextMember,
  getNodeByName,
  getEnumBoundings,
  isFillableMember,
  isIgnoreableType,
  isFlushableMember,
  getAutoStructureType,
  getDataViewInstruction,
  getDataViewInstructionStride,
  stringifyJSONQuoteless,
  getHexaByteOffset
} from "../utils.mjs";

import {
  JavaScriptType,
  getJavaScriptType
} from "../javascript-type.mjs";

let ast = null;
let validate = false;
let currentHandle = null;
let currentStruct = null;

const JS_INDEX_TEMPLATE = fs.readFileSync(`${pkg.config.TEMPLATE_DIR}/js/index-js.njk`, "utf-8");
const JS_HANDLE_TEMPLATE = fs.readFileSync(`${pkg.config.TEMPLATE_DIR}/js/handle-js.njk`, "utf-8");
const JS_STRUCT_TEMPLATE = fs.readFileSync(`${pkg.config.TEMPLATE_DIR}/js/struct-js.njk`, "utf-8");

let enumLayouts = null;
let memoryLayouts = null;

let enumLayoutTable = null;

nunjucks.configure({ autoescape: true });

function getConstructorMemberInitializer(member) {
  let jsType = getJavaScriptType(ast, member);
  let {type, value, isReference} = jsType;
  switch (type) {
    case JavaScriptType.OBJECT: {
      if (isReference) {
        return `this._${member.name} = null;`;
      } else {
        let byteOffset = getStructureMemberByteOffset(member);
        let memoryOffset = getHexaByteOffset(byteOffset);
        return `this._${member.name} = new ${member.type}({ $memoryBuffer: this.memoryBuffer, $memoryOffset: this.$memoryOffset + ${memoryOffset} });`;
      }
    }
    case JavaScriptType.ARRAY_OF_OBJECTS: {
      let length = parseInt(member.length);
      let byteOffset = getStructureMemberByteOffset(member);
      let memoryOffset = getHexaByteOffset(byteOffset);
      let byteLength = getHexaByteOffset(parseInt(getStructureMemberByteLength(member)) / length);
      return `this._${member.name} = [...Array(${length})].map((v, i) => new ${member.type}({ $memoryBuffer: this.memoryBuffer, $memoryOffset: this.$memoryOffset + ${memoryOffset} + (i * ${byteLength}) }));`;
    }
    case JavaScriptType.ARRAY_OF_NUMBERS: {
      if (currentStruct.isUnionType) return `this._${member.name} = null;`;
      let length = parseInt(member.length);
      return `this._${member.name} = [...Array(${length})].fill(0x0);`;
    }
  };
  warn(`Cannot handle instantiation initializer for ${currentStruct.name}.${member.name}, ${jsType.type}`);
  return ``;
};

function getConstructorInitializer(member) {
  let jsType = getJavaScriptType(ast, member);
  if (member.needsInitializationAtInstantiation) {
    return getConstructorMemberInitializer(member);
  }
  if (jsType.isNumeric) return ``; // no reflection needed
  if (jsType.isBoolean) return ``; // no reflection needed
  if (jsType.isString && jsType.isStatic) return ``; // no reference needed
  if (jsType.isJavaScriptArray) {
    if (jsType.isStatic) {
      return `this._${member.name} = null;`;
    } else {
      return `this._${member.name} = null;
  this._${member.name}Native = null;`;
    }
  }
  if (jsType.isNullable) {
    let out = ``;
    out += `this._${member.name} = null;`;
    if (jsType.isFunction) {
      out += `this._${member.name}CallbackProxy = null;`;
    }
    return out;
  }
  warn(`Cannot resolve constructor initializer for ${member.name}`);
  return ``;
};

function getConstructorResetter(member) {
  let jsType = getJavaScriptType(ast, member);
  if (member.needsInitializationAtInstantiation) {
    let {type, value, isReference} = jsType;
    let length = parseInt(member.length);
    switch (type) {
      case JavaScriptType.OBJECT: {
        if (isReference) {
          return `this._${member.name} = null;`;
        } else {
          let byteOffset = getStructureMemberByteOffset(member);
          let memoryOffset = getHexaByteOffset(byteOffset);
          return `if (this._${member.name} !== null) {
    if (this.memoryBuffer !== this._${member.name}.memoryBuffer) this._${member.name} = new ${member.type}({ $memoryBuffer: this.memoryBuffer, $memoryOffset: this.$memoryOffset + ${memoryOffset} });
    else this._${member.name}.reset();
  }`;
        }
      }
      case JavaScriptType.ARRAY_OF_OBJECTS: {
        let byteOffset = getStructureMemberByteOffset(member);
        let memoryOffset = getHexaByteOffset(byteOffset);
        let byteLength = getHexaByteOffset(parseInt(getStructureMemberByteLength(member)) / length);
        return `if (this._${member.name} !== null) {
    let array = this._${member.name};
    for (let ii = 0; ii < array.length; ++ii) {
      array[ii].reset();
    };
  };`;
      }
      case JavaScriptType.ARRAY_OF_NUMBERS: {
        if (currentStruct.isUnionType) return `this._${member.name} = null;`;
        return `if (this._${member.name} !== null) this._${member.name}.fill(0x0);
      else this._${member.name} = [...Array(${length})].fill(0x0);`;
      }
    };
    warn(`Cannot handle instantiation initializer for ${currentStruct.name}.${member.name}, ${jsType.type}`);
  }
  if (jsType.isNumeric) return ``; // no reset needed
  if (jsType.isBoolean) return ``; // no reset needed
  if (jsType.isString && jsType.isStatic) return ``; // no reset needed
  if (jsType.isJavaScriptArray) {
    if (jsType.isStatic) {
      return `this._${member.name} = null;`;
    } else {
      return `this._${member.name} = null;
  this._${member.name}Native = null;`;
    }
  }
  if (jsType.isNullable) return `this._${member.name} = null;`;
  warn(`Cannot resolve constructor initializer for ${member.name}`);
  return ``;
};

function getStructureMemberByteOffset(member) {
  if (!memoryLayouts) return `0x0`;
  let byteOffset = memoryLayouts[currentStruct.name][member.name].byteOffset;
  return getHexaByteOffset(byteOffset);
};

function getStructureMemberByteLength(member) {
  if (!memoryLayouts) return `0x0`;
  let byteLength = memoryLayouts[currentStruct.name][member.name].byteLength;
  return getHexaByteOffset(byteLength);
};

function getStructureByteLength(struct = null) {
  if (!memoryLayouts) return `0x0`;
  let byteLength = memoryLayouts[(struct || currentStruct).name].byteLength;
  return getHexaByteOffset(byteLength);
};

function getHandleByteLength() {
  return getHexaByteOffset(8);
};

function getEnumInlineValue(name) {
  if (!enumLayouts) return ``;
  let value = enumLayouts[name];
  if (value === void 0) {
    let value_KHR = enumLayouts[name + "_KHR"];
    // try different extension names
    if (value_KHR !== void 0) return getHexaByteOffset(value_KHR);
    warn(`Cannot inline enum value of '${name}'`);
    return name;
  }
  return getHexaByteOffset(value);
};

function getEnumInlineStypeValue(name) {
  if (!enumLayouts) return ``;
  let value = getEnumInlineValue(name);
  if (Number.isNaN(parseInt(value))) return `VK_ENUMERATIONS.VkStructureType.${value}`;
  return value;
};

function getEnumRangeValidationFunctions() {
  if (!enumLayouts) return ``;
  let out = ``;
  let table = enumLayoutTable;
  for (let enumName in table) {
    // can be ignored
    if (enumName === `API_Extensions_Strings`) continue;
    let values = [];
    out += `
function $VAL_R_${enumName}(value) {`;
    if (Object.keys(table[enumName]) <= 0) {
      out += `\n  return false;
};\n`;
    continue;
    }
    out += `
  switch (value) {\n    `;
    for (let memberName in table[enumName]) {
      let value = table[enumName][memberName];
      if (values.indexOf(value) > -1) continue;
      values.push(value);
      out += `case ${getHexaByteOffset(value)}: `;
    };
    out += `
      return true;`;
    out += `
  };
  return false;
};\n`;
  };
  return out;
};

function getStructureMemoryViews(passedByReference) {
  let out = ``;
  let struct = currentStruct;
  let viewTypes = [];
  struct.children.map(member => {
    let jsType = getJavaScriptType(ast, member);
    let {type, isReference} = jsType;
    if (
      type === JavaScriptType.NUMBER ||
      type === JavaScriptType.BIGINT ||
      type === JavaScriptType.BOOLEAN
    ) {
      let viewInstr = getDataViewInstruction(member);
      if (viewTypes.indexOf(viewInstr) <= -1) viewTypes.push(viewInstr);
    }
    else if (
      ((type === JavaScriptType.OBJECT && (isReference || member.isHandleType)) ||
      (type === JavaScriptType.STRING && !jsType.isStatic) ||
      type === JavaScriptType.TYPED_ARRAY) &&
      isFillableMember(struct, member)
    ) {
      if (viewTypes.indexOf("BigInt64") <= -1) viewTypes.push("BigInt64");
    }
    else if (
      isPNextMember(member)
    ) {
      if (viewTypes.indexOf("BigInt64") <= -1) viewTypes.push("BigInt64");
    }
    else if (
      type === JavaScriptType.FUNCTION
    ) {
      if (viewTypes.indexOf("BigInt64") <= -1) viewTypes.push("BigInt64");
    }
    else if (
      type === JavaScriptType.ARRAY_OF_NUMBERS
    ) {
      let viewInstr = getDataViewInstruction(member);
      if (viewTypes.indexOf(viewInstr) <= -1) viewTypes.push(viewInstr);
    }
  });
  // always add an Uint8Array base view (e.g. used for struct reset)
  {
    // check if it's necessary to add it
    let addUint8View = !!!viewTypes.filter(type => type === "Uint8")[0];
    if (addUint8View) viewTypes.unshift("Uint8");
  }
  if (passedByReference) {
    viewTypes.map(type => {
      out += `    this.memoryView${type} = new ${type}Array(this.memoryBuffer);\n`;
    });
  // passed by-value, share memoryBuffer of top-structure
  } else {
    viewTypes.map(type => {
      let byteStride = global[type + "Array"].BYTES_PER_ELEMENT;
      let length = getStructureByteLength() / byteStride;
      out += `    this.memoryView${type} = new ${type}Array(this.memoryBuffer, opts.$memoryOffset, ${getHexaByteOffset(length)});\n`;
    });
  }
  return out;
};

function getGetterProcessor(member) {
  let jsType = getJavaScriptType(ast, member);
  let {type, value, isReference} = jsType;
  let byteOffset = getStructureMemberByteOffset(member);
  switch (type) {
    case JavaScriptType.NUMBER:
    case JavaScriptType.BIGINT: {
      let instr = getDataViewInstruction(member);
      let byteStride = getDataViewInstructionStride(instr);
      let offset = getHexaByteOffset(byteOffset / byteStride);
      return `
    return this.memoryView${instr}[${offset}];`;
    }
    case JavaScriptType.BOOLEAN: {
      let instr = getDataViewInstruction(member);
      let byteStride = getDataViewInstructionStride(instr);
      let offset = getHexaByteOffset(byteOffset / byteStride);
      return `
    return this.memoryView${instr}[${offset}] !== 0;`;
    }
    case JavaScriptType.OBJECT: {
      let instr = "BigInt64";
      let byteStride = getDataViewInstructionStride(instr);
      let offset = getHexaByteOffset(byteOffset / byteStride);
      if (isReference) {
        if (member.isHandleType) {
          warn(`Cannot handle handle reference reflection for ${currentStruct.name}.${member.name}`);
        }
        return `
    if (this._${member.name} === null && this.memoryView${instr}[${offset}] !== BI0) {
      let addr = this.memoryView${instr}[${offset}];
      let buffer = getArrayBufferFromAddress(addr, BigInt(${member.type}.byteLength));
      this._${member.name} = new ${member.type}({ $memoryBuffer: buffer, $memoryOffset: 0x0 });
      this.memoryViewBigInt64[${offset}] = this._${member.name}.memoryAddress;
      return this.${member.name};
    } else {
      return this._${member.name};
    }`;
      }
      return `
    return this._${member.name};`;
    }
    case JavaScriptType.STRING: {
      let byteOffsetBegin = getStructureMemberByteOffset(member) | 0;
      let byteOffsetEnd = byteOffsetBegin + (getStructureMemberByteLength(member) | 0);
      let hxByteOffsetBegin = getHexaByteOffset(byteOffsetBegin);
      let hxByteOffsetEnd = getHexaByteOffset(byteOffsetBegin + byteOffsetEnd);
      if (jsType.isStatic) {
        return `
    return decodeNullTerminatedUTF8String(
      new Uint8Array(this.memoryBuffer).subarray(this.$memoryOffset + ${hxByteOffsetBegin}, ${hxByteOffsetEnd})
    ) || null;`;
      } else {
        let instr = "BigInt64";
        let byteStride = getDataViewInstructionStride(instr);
        let offset = getHexaByteOffset(byteOffsetBegin / byteStride);
        return `
    if (this._${member.name} !== null) {
      let str = textDecoder.decode(this._${member.name});
      return str.substr(0, str.length - 1);
    } else {
      // native memory contains a string which we didn't reflect yet
      if (this.memoryViewBigInt64[${offset}] !== BI0) {
        let addr = this.memoryViewBigInt64[${offset}];
        let length = findNullTerminatedUTF8StringLength(addr);
        let buffer = getArrayBufferFromAddress(addr, BigInt(length));
        this._${member.name} = buffer;
        return this.${member.name};
      }
      return null;
    }`;
      }
    }
    case JavaScriptType.ARRAY_OF_STRINGS: {
      if (currentStruct.returnedonly) {
        warn(`Cannot process natively created array of strings for ${currentStruct.name}.${member.name}`);
      }
      return `
    return this._${member.name};`;
    }
    case JavaScriptType.ARRAY_OF_NUMBERS: {
      if (currentStruct.returnedonly) {
        if (!jsType.isStatic) {
          warn(`Cannot process non-static array of numbers for ${currentStruct.name}.${member.name}`);
        }
        if (!member.length) {
          warn(`Cannot resolve length for static array of numbers for ${currentStruct.name}.${member.name}`);
        }
        let length = parseInt(member.length);
        let out = `\n    return [\n`;
        for (let ii = 0; ii < length; ++ii) {
          let instr = getDataViewInstruction(member);
          let byteStride = getDataViewInstructionStride(instr);
          let offset = getHexaByteOffset((byteOffset / byteStride) + ii);
          let comma = ii < length - 1 ? `,\n` : ``;
          out += `      this.memoryView${instr}[${offset}]${comma}`;
        };
        out += `\n    ];`;
        return out;
      }
      return `
    return this._${member.name};`;
    }
    case JavaScriptType.ARRAY_OF_OBJECTS: {
      // dynamic array of references
      if (!jsType.isStatic) {
        let instr = "BigInt64";
        let byteStride = getDataViewInstructionStride(instr);
        let offset = getHexaByteOffset(byteOffset / byteStride);
        if (!member.hasOwnProperty("length")) {
          warn(`Expected member length attribute set for ${currentStruct.name}.${member.name}`);
        }
        return `
    if (this._${member.name} === null && this.memoryView${instr}[${offset}] !== BI0) {
      let addr = this.memoryView${instr}[${offset}];
      let array = decodeNativeArrayOfObjects(addr, this.${member.length}, ${member.type});
      this._${member.name} = array;
      return this.${member.name};
    } else {
      return this._${member.name};
    }`;
      } else {
        return `
    return this._${member.name};`;
      }
    }
    case JavaScriptType.TYPED_ARRAY: {
      // TODO: Handle reflection
      return `
    return this._${member.name};`;
    }
    case JavaScriptType.FUNCTION: {
      return `
    return this._${member.name};`;
    }
  };
  if (isPNextMember(member)) {
    return `
    return this._${member.name};`;
  }
  warn(`Cannot resolve getter processor for ${member.name} of type ${type}`);
  return ``;
};

function getSetterProcessor(member) {
  let jsType = getJavaScriptType(ast, member);
  let {type, value, isReference} = jsType;
  let byteOffset = getStructureMemberByteOffset(member);
  let byteLength = getStructureMemberByteLength(member);
  switch (type) {
    case JavaScriptType.NUMBER: {
      let instr = getDataViewInstruction(member);
      let byteStride = getDataViewInstructionStride(instr);
      let offset = getHexaByteOffset(byteOffset / byteStride);
      let out = ``;
      // validate type
      if (validate) {
        out += `
    if (typeof value !== "number") {
      throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}': Expected 'Number' but got '" + typeToString(value) + "'");
    }`;
      }
      // validate enum boundings
      if (validate && enumLayouts && member.enumType) {
        let enumObject = enumLayouts[member.enumType];
        if (!enumObject) warn(`Cannot resolve bounding check enum for ${currentStruct.name}.${member.name}`);
        else {
          out += `
    if (!$VAL_R_${member.enumType}(value)) {
      throw new RangeError("Invalid value for '${currentStruct.name}.${member.name}': '" + value + "' is not a value of '${member.enumType}'");
    }`;
        }
      }
      out += `
    this.memoryView${instr}[${offset}] = value;`;
      return out;
    }
    case JavaScriptType.BIGINT: {
      let instr = getDataViewInstruction(member);
      let byteStride = getDataViewInstructionStride(instr);
      let offset = getHexaByteOffset(byteOffset / byteStride);
      return `
    ${ validate ? `if (typeof value !== "bigint" && typeof value !== "number") {
      throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}': Expected 'BigInt' or 'Number' but got '" + typeToString(value) + "'");
    }` : `` }
    this.memoryView${instr}[${offset}] = BigInt(value);`;
    }
    case JavaScriptType.BOOLEAN: {
      let instr = getDataViewInstruction(member);
      let byteStride = getDataViewInstructionStride(instr);
      let offset = getHexaByteOffset(byteOffset / byteStride);
      return `
    this.memoryView${instr}[${offset}] = value | 0;`;
    }
    case JavaScriptType.OBJECT: {
      let instr = "BigInt64";
      let byteStride = getDataViewInstructionStride(instr);
      let offset = getHexaByteOffset(byteOffset / byteStride);
      return `
    if (value !== null ${ validate ? `&& value.constructor === ${member.type}` : ``}) {
      ${member.isStructType ? `value.flush();` : ``}
      this._${member.name} = value;
      ${member.isStructType && isReference ? `this.memoryView${instr}[${offset}] = value.memoryAddress;` : ``}
      ${member.isHandleType ? `this.memoryView${instr}[${offset}] = value.memoryViewBigInt64[0];` : ``}
    } else if (value === null) {
      this._${member.name} = null;
      ${((member.isStructType && isReference) || member.isHandleType) ? `this.memoryView${instr}[${offset}] = BI0;` : ``}
    } ${ validate ? `else {
      throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}': Expected '${member.type}' but got '" + typeToString(value) + "'");
    }`: `` }
    `;
    }
    case JavaScriptType.STRING: {
      let instr = "BigInt64";
      let byteStride = getDataViewInstructionStride(instr);
      let offset = getHexaByteOffset(byteOffset / byteStride);
      return `
    if (value !== null ${ validate ? `&& value.constructor === String` : `` }) {
      this._${member.name} = textEncoder.encode(value + NULLT).buffer;
      this.memoryView${instr}[${offset}] = getAddressFromArrayBuffer(this._${member.name});
    } else if (value === null) {
      this._${member.name} = null;
      this.memoryView${instr}[${offset}] = BI0;
    } ${ validate ? `else {
      throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}': Expected 'String' but got '" + typeToString(value) + "'");
    }` : `` }
    `;
    }
    case JavaScriptType.ARRAY_OF_STRINGS: {
      return `
    if (value !== null ${ validate ? `&& value.constructor === Array` : `` }) {
      this._${member.name} = value;
    } else if (value === null) {
      this._${member.name} = null;
    } ${ validate ? `else {
      throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}': Expected 'Array ${member.type}' but got '" + typeToString(value) + "'");
    }`: `` }
    `;
    }
    case JavaScriptType.ARRAY_OF_NUMBERS: {
      return `
    if (value !== null ${ validate ? `&& value.constructor === Array` : `` }) {
      this._${member.name} = value;
    } else if (value === null) {
      this._${member.name} = null;
    } ${ validate ? `else {
      throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}': Expected 'Array ${member.type}' but got '" + typeToString(value) + "'");
    }` : `` }
    `;
    }
    case JavaScriptType.ARRAY_OF_OBJECTS: {
      return `
    if (value !== null ${ validate ? `&& value.constructor === Array` : `` }) {
      this._${member.name} = value;
    } else if (value === null) {
      this._${member.name} = null;
    } ${ validate ? `else {
      throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}': Expected 'Array ${member.type}' but got '" + typeToString(value) + "'");
    } ` : `` }
    `;
    }
    case JavaScriptType.TYPED_ARRAY: {
      let instr = "BigInt64";
      let byteStride = getDataViewInstructionStride(instr);
      let offset = getHexaByteOffset(byteOffset / byteStride);
      let isArrayBufferType = member.jsTypedArrayName === "ArrayBuffer";
      let arrayBufferValue = `value${isArrayBufferType ? "" : ".buffer"}`;
      return `
    if (value !== null ${ validate ? `&& value.constructor === ${member.jsTypedArrayName}` : `` }) {
      this._${member.name} = value;
      this.memoryView${instr}[${offset}] = getAddressFromArrayBuffer(${arrayBufferValue});
    } else if (value === null) {
      this._${member.name} = null;
      this.memoryView${instr}[${offset}] = BI0;
    } ${ validate ? `else {
      throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}': Expected '${member.jsTypedArrayName}' but got '" + typeToString(value) + "'");
    }` : `` }
    `;
    }
    case JavaScriptType.FUNCTION: {
      let instr = "BigInt64";
      let functionPointerAccessor = member.type.substr(4);
      let byteStride = getDataViewInstructionStride(instr);
      let offset = getHexaByteOffset(byteOffset / byteStride);
      let pUserData = ``;
      // resolve member setter code for pUserData
      {
        let pUserDataMember = currentStruct.children.find(child => child.name === "pUserData");
        if (!pUserDataMember) warn(`Cannot resolve 'pUserData' member for '${currentStruct.name}'`);
        let byteOffset = getStructureMemberByteOffset(pUserDataMember);
        let instr = "BigInt64";
        let byteStride = getDataViewInstructionStride(instr);
        let offset = getHexaByteOffset(byteOffset / byteStride);
        pUserData = `this.memoryView${instr}[${offset}] = this._${member.name}CallbackProxy.getAddress();`;
      }
      return `
    if (value !== null ${ validate ? `&& value.constructor === Function` : `` }) {
      this._${member.name} = value;
      this._${member.name}CallbackProxy = new nvk.$CallbackProxy(value, module.exports);
      this.memoryView${instr}[${offset}] = nvk.$vulkanCallbackFunctionPointers["${functionPointerAccessor}"];
      ${pUserData}
    } else if (value === null) {
      this._${member.name} = null;
      this.memoryView${instr}[${offset}] = BI0;
    } ${ validate ? `else {
      throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}': Expected 'Function' but got '" + typeToString(value) + "'");
    }` : `` }
    `;
    }
  };
  if (isPNextMember(member)) {
    let {extensions} = currentStruct;
    let conditions = ``;
    if (!extensions) {
      return `
    if (value !== null) throw new TypeError("'${currentStruct.name}.${member.name}' isn't allowed to be filled");`;
    }
    extensions.map((extensionName, index) => {
      let structExt = getNodeByName(extensionName, ast);
      if (!structExt || !structExt.sType) warn(`Cannot resolve struct by extension name '${extensionName}'`);
      conditions += `
        case ${getEnumInlineStypeValue(structExt.sType)}:`;
    });
    let instr = "BigInt64";
    let byteStride = getDataViewInstructionStride(instr);
    let offset = getHexaByteOffset(byteOffset / byteStride);
    return `
    if (value !== null ${ validate ? `&& (value instanceof Object)` : `` }) {
      let {sType} = value;
      ${ validate ? `if (sType <= -1) throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}'");` : `` }
      switch (sType) {
          ${conditions}
          break;
        default:
          throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}'");
      };
      this._${member.name} = value;
      this.memoryView${instr}[${offset}] = value.memoryAddress;
    } else if (value === null) {
      this._${member.name} = null;
      this.memoryView${instr}[${offset}] = BI0;
    } ${ validate ? `else {
      throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}'");
    }` : `` }
    `;
  }
  warn(`Cannot resolve setter processor for ${member.name} of type ${type}`);
  return ``;
};

function getFlusherProcessor(member) {
  let jsType = getJavaScriptType(ast, member);
  let {type, value, isReference} = jsType;
  let byteOffset = getStructureMemberByteOffset(member);
  let byteLength = getStructureMemberByteLength(member);
  switch (type) {
    case JavaScriptType.NUMBER:
    case JavaScriptType.BIGINT: {
      return ``; // not needed
    }
    case JavaScriptType.BOOLEAN: {
      return ``; // not needed
    }
    case JavaScriptType.OBJECT: {
      if (member.isStructType && !isReference) {
        return `
  if (this._${member.name} !== null) {
    let ${member.name} = this._${member.name};
    ${member.name}.flush();
    if (this.memoryBuffer !== ${member.name}.memoryBuffer) {
      let srcView = new Uint8Array(${member.name}.memoryBuffer, ${member.name}.$memoryOffset, ${byteLength});
      let dstView = new Uint8Array(this.memoryBuffer);
      dstView.set(srcView, ${byteOffset});
      ${ validate ? `if (ENABLE_SHARED_MEMORY_HINTS) console.warn("'${currentStruct.name}.${member.name}' isn't used as shared-memory");` : `` }
    }
  }`;
      } else {
        warn(`Cannot handle member ${member.name}!`);
      }
      return ``;
    }
    case JavaScriptType.STRING: {
      return ``; // not needed
    }
    case JavaScriptType.ARRAY_OF_STRINGS: {
      let {length} = member;
      let isNumber = Number.isInteger(parseInt(length));
      let instr = "BigInt64";
      let byteStride = getDataViewInstructionStride(instr);
      let offset = getHexaByteOffset(byteOffset / byteStride);
      return `
  if (this._${member.name} !== null) {
    let array = this._${member.name};
    ${ validate ? `
    // validate length
    if (array.length !== ${isNumber ? length : `this.${length}`}) {
      throw new RangeError("Invalid array length, expected length of '${length}' for '${currentStruct.name}.${member.name}'");
      return false;
    }
    // validate type
    for (let ii = 0; ii < array.length; ++ii) {
      if (typeof (array[ii]) !== "string") {
        throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}[" + ii + "]': Expected 'String' but got '" + typeToString(array[ii]) + "'");
        return false;
      }
    };` : `` }
    let nativeArray = new NativeStringArray(this._${member.name});
    this._${member.name}Native = nativeArray;
    this.memoryView${instr}[${offset}] = nativeArray.address;
  } else {
    this.memoryView${instr}[${offset}] = BI0;
  }`;
    }
    case JavaScriptType.ARRAY_OF_NUMBERS: {
      let {length} = member;
      let isNumber = Number.isInteger(parseInt(length));
      let instr = getDataViewInstruction(member);
      let byteStride = getDataViewInstructionStride(instr);
      let offset = getHexaByteOffset(byteOffset / byteStride);
      return `
  if (this._${member.name} !== null) {
    let array = this._${member.name};
    ${ validate ? `
    // validate length
    if (array.length !== ${isNumber ? length : `this.${length}`}) {
      throw new RangeError("Invalid array length, expected length of '${length}' for '${currentStruct.name}.${member.name}'");
      return false;
    }
    // validate type
    for (let ii = 0; ii < array.length; ++ii) {
      if (typeof (array[ii]) !== "number") {
        throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}[" + ii + "]': Expected 'Number' but got '" + typeToString(array[ii]) + "'");
        return false;
      }
    };` : `` }
    for (let ii = 0; ii < array.length; ++ii) {
      this.memoryView${instr}[${offset} + ii] = array[ii];
    };
  } else {
    ${!currentStruct.isUnionType ? `this.memoryView${instr}[${offset}] = 0x0;` : ``}
  }`;
    }
    case JavaScriptType.ARRAY_OF_OBJECTS: {
      // TODO: returnedonly
      let {length} = member;
      let isNumber = Number.isInteger(parseInt(length));
      let byteOffset = getStructureMemberByteOffset(member);
      let byteLength = getStructureMemberByteLength(member);
      let write = ``;
      if (!jsType.isStatic) {
        let instr = "BigInt64";
        let byteStride = getDataViewInstructionStride(instr);
        let offset = getHexaByteOffset(byteOffset / byteStride);
        write = `
    if (array.length > 0) {
      let nativeArray = new NativeObjectArray(array);
      this._${member.name}Native = nativeArray;
      this.memoryView${instr}[${offset}] = nativeArray.address;
    } else {
      this._${member.name}Native = null;
      this.memoryView${instr}[${offset}] = BI0;
    }`;
      // do a memcpy for static objects
      } else {
        write = `
    let dstView = new Uint8Array(this.memoryBuffer);
    let byteOffset = ${byteOffset};
    for (let ii = 0; ii < array.length; ++ii) {
      let srcView = new Uint8Array(array[ii].memoryBuffer);
      dstView.set(srcView, byteOffset);
      byteOffset += ${member.type}.byteLength;
    };`;
      }
      return `
  if (this._${member.name} !== null) {
    let array = this._${member.name};
    ${ validate ? `
    if (array.length !== ${isNumber ? length : `this.${length}`}) {
      throw new RangeError("Invalid array length, expected length of '${length}' for '${currentStruct.name}.${member.name}'");
      return false;
    }` : `` }
    for (let ii = 0; ii < array.length; ++ii) {
      ${ validate ? `
      if (!array[ii] || (array[ii].constructor !== ${member.type})) {
        throw new TypeError("Invalid type for '${currentStruct.name}.${member.name}[" + ii + "]': Expected '${member.type}' but got '" + typeToString(array[ii]) + "'");
        return false;
      }` : `` }
      ${member.isStructType ? `if (!array[ii].flush()) return false;` : ``}
    };
    ${write}
  }`;
    }
    case JavaScriptType.TYPED_ARRAY: {
      return ``; // not needed
    }
  };
  if (isPNextMember(member)) {
    return `
  if (this._${member.name} !== null) {
    if (!this._${member.name}.flush()) return false;
  }`;
  }
  warn(`Cannot resolve flusher processor for ${member.name} of type ${type}`);
  return ``;
};

function getStructureAutoSType() {
  let struct = currentStruct;
  let sType = null;
  // these two are to iterate over given sType structs, ignore them
  if (struct.name === `VkBaseInStructure` || struct.name === `VkBaseOutStructure`) {
    return ``;
  }
  let filtered = struct.children.filter(member => member.name === "sType");
  let sTypeMember = null;
  if (filtered.length) sTypeMember = filtered[0];
  if (sTypeMember) sType = struct.sType || getAutoStructureType(struct.name);
  if (sType) return `this.sType = ${getEnumInlineStypeValue(sType)};`;
  return ``;
};

function getEnumLayoutTable() {
  let json = enumLayouts;
  if (!json) return null;
  let out = {};
  for (let key in json) {
    if (typeof json[key] === "object") {
      out[key] = json[key];
    }
  };
  return out;
};

function getEnumLayouts() {
  let enumLayoutsPath = `${pkg.config.GEN_OUT_DIR}/${global.vkVersion}/${getPlatform()}/enumLayouts.json`;
  if (!fs.existsSync(enumLayoutsPath)) {
    if (!global.ENUM_LAYOUT_NEEDS_RECOMPILATION) {
      warn(`Module needs recompilation:
Enum layouts aren't resolved yet, module needs to be re-compiled this time
The code generater can only inline required enum layouts after second compilation
      `);
      global.ENUM_LAYOUT_NEEDS_RECOMPILATION = true;
    }
  } else {
    return JSON.parse(fs.readFileSync(enumLayoutsPath, "utf-8"));
  }
  return null;
};

function getMemoryLayouts() {
  let memoryLayoutsPath = `${pkg.config.GEN_OUT_DIR}/${global.vkVersion}/${getPlatform()}/memoryLayouts.json`;
  if (!fs.existsSync(memoryLayoutsPath)) {
    if (!global.MEMORY_LAYOUT_NEEDS_RECOMPILATION) {
      warn(`Module needs recompilation:
Memory layouts aren't resolved yet, module needs to be re-compiled this time
The code generater can only inline required memory layout offets after second compilation
      `);
      global.MEMORY_LAYOUT_NEEDS_RECOMPILATION = true;
    }
  } else {
    return JSON.parse(fs.readFileSync(memoryLayoutsPath, "utf-8"));
  }
  return null;
};

export default function(astReference, includeValidations, disableMinification, calls, handles, structs) {
  ast = astReference;
  validate = includeValidations;
  enumLayouts = getEnumLayouts();
  enumLayoutTable = getEnumLayoutTable();
  memoryLayouts = getMemoryLayouts();
  let output = ``;
  // header
  output += nunjucks.renderString(JS_INDEX_TEMPLATE, {});
  // struct reset cache
  {
    output += `\n`;
    let structCache = {};
    // collect all individual struct sizes
    structs.map(struct => {
      let byteLength = getStructureByteLength(struct);
      structCache[byteLength] = parseInt(byteLength);
    });
    // generate struct reset cache
    output += `const STRUCT_RESET_CACHE = {\n`;
    for (let key in structCache) {
      if (!structCache.hasOwnProperty(key)) continue;
      output += `  "${key}": new Uint8Array(${key}),\n`;
    };
    output += `};\n`;
  }
  // enum range checks
  if (validate) {
    output += getEnumRangeValidationFunctions();
  }
  // handles
  handles.map(handle => {
    currentHandle = handle;
    output += nunjucks.renderString(JS_HANDLE_TEMPLATE, {
      handle,
      getHandleByteLength
    });
  });
  // structs
  structs.map(struct => {
    currentStruct = struct;
    output += nunjucks.renderString(JS_STRUCT_TEMPLATE, {
      struct,
      isFillableMember,
      isIgnoreableType,
      isFlushableMember,
      getGetterProcessor,
      getSetterProcessor,
      getFlusherProcessor,
      getStructureAutoSType,
      getConstructorResetter,
      getStructureByteLength,
      getStructureMemoryViews,
      getConstructorInitializer,
      getStructureMemberByteOffset,
      getStructureMemberByteLength
    });
  });
  // struct cache
  {
    output += `\n`;
    structs.map(struct => {
      output += `let _${struct.name} = new ${struct.name}();\n`;
    });
    output += `\n`;
  }
  // exports
  output += `\nmodule.exports = {\n`;
  // add c++ stuff
  output += `  ...VK_ENUMERATIONS,\n`;
  output += `  VK_MAKE_VERSION: nvk.VK_MAKE_VERSION,\n`;
  output += `  VK_VERSION_MAJOR: nvk.VK_VERSION_MAJOR,\n`;
  output += `  VK_VERSION_MINOR: nvk.VK_VERSION_MINOR,\n`;
  output += `  VK_VERSION_PATCH: nvk.VK_VERSION_PATCH,\n`;
  output += `  VK_API_VERSION_1_0: nvk.VK_API_VERSION_1_0,\n`;
  output += `  VK_API_VERSION_1_1: nvk.VK_API_VERSION_1_1,\n`;
  output += `  vkUseDevice: nvk.vkUseDevice,\n`;
  output += `  vkUseInstance: nvk.vkUseInstance,\n`;
  // add VulkanWindow
  output += `  VulkanWindow: nvk.VulkanWindow,\n`;
  calls.map(call => {
    output += `  ${call.name}: nvk.${call.name},\n`;
  });
  handles.map(handle => {
    output += `  ${handle.name},\n`;
  });
  structs.map((struct, index) => {
    let comma = index < structs.length - 1 ? `,\n` : ``;
    output += `  ${struct.name}${comma}`;
  });
  output += `\n};\n`;
  if (disableMinification) return output;
  // minify output
  let minified = Terser.minify(output);
  if (minified.error) {
    warn(`Failed to minify code: ${minified.error.toString()}`);
    return output;
  }
  return minified.code;
};
