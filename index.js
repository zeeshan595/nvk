/// <reference types="./generated/1.1.121/darwin/" />
/// <reference types="./generated/1.1.121/win32/" />
/// <reference types="./generated/1.1.121/linux" />

const fs = require("fs");
const path = require("path");
const pkg = require("./package.json");

function throwInvalidVkVersion() {
  process.stderr.write(`Invalid vulkan version specifier!\n`);
  throw `Exiting..`;
};

function getVkVersionFromArg(arg) {
  let split = arg.split("=");
  if (split.length === 2) {
    let version = split[1];
    if (version.split(".").length !== 3) {
      throwInvalidVkVersion();
    } else {
      return version;
    }
  } else {
    throwInvalidVkVersion();
  }
};

// gather vk version
let vkVersion = process.env.npm_config_vkversion;
// attempt npm version
vkVersion = vkVersion || null;
// attempt node argv
if (!vkVersion) {
  process.argv.map(arg => {
    if (arg.match("vkversion=")) {
      vkVersion = getVkVersionFromArg(arg);
    }
  });
}

if (!vkVersion) vkVersion = pkg.config.POST_DEFAULT_BINDING_VERSION;

// gather disable-validation-checks flag
let disableValidationChecks = process.env.npm_config_disable_validation_checks;
// attempt npm version
disableValidationChecks = disableValidationChecks || null;
// attempt node argv
if (!disableValidationChecks) {
  process.argv.map(arg => {
    if (arg.match("disable-validation-checks")) {
      disableValidationChecks = true;
    }
  });
}

process.stdout.write(`(nvk) Using Vulkan v${vkVersion}\n`);

let {platform} = process;

// strictly dissallow older versions
if (pkg.config.OUTDATED.indexOf(vkVersion) > -1) {
  process.stderr.write(`${vkVersion} is outdated and no longer supported!
Please use v${pkg.config.POST_DEFAULT_BINDING_VERSION} from now on!\n`);
  throw `Exiting..`;
}

const releasePath = `${pkg.config.GEN_OUT_DIR}/${vkVersion}/${platform}/build/Release`;
const bindingsPath = path.join(__dirname, `${pkg.config.GEN_OUT_DIR}/`);
const generatedPath = bindingsPath + `${vkVersion}/${platform}`;

// make sure the bindings exist
if (!fs.existsSync(`${generatedPath}/interfaces.js`)) {
  process.stderr.write(`(nvk) Failed to load interfaces for v${vkVersion} from ${generatedPath}\n`);
  process.stderr.write(`(nvk) Your platform might not be supported\n`);
  throw `Exiting..`;
}

if (platform === "darwin") {
  process.env.VK_ICD_FILENAMES = path.join(__dirname, `${releasePath}/${pkg.config.MAC_ICD_PATH}`);
}

if (disableValidationChecks) {
  process.stdout.write(`(nvk) Validation checks are disabled\n`);
  module.exports = require(`${generatedPath}/interfaces-no-validation.js`);
} else {
  process.stdout.write(`(nvk) Validation checks are enabled\n`);
  module.exports = require(`${generatedPath}/interfaces.js`);
}
