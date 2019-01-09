/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.4
 */
#include "utils.h"
#include "index.h"
#include "VkShadingRatePaletteNV.h"

Nan::Persistent<v8::FunctionTemplate> _VkShadingRatePaletteNV::constructor;

_VkShadingRatePaletteNV::_VkShadingRatePaletteNV() {
  
  
}

_VkShadingRatePaletteNV::~_VkShadingRatePaletteNV() {
  //printf("VkShadingRatePaletteNV deconstructed!!\n");
  
  
  pShadingRatePaletteEntries.Reset();
  
}

void _VkShadingRatePaletteNV::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkShadingRatePaletteNV::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkShadingRatePaletteNV").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  SetPrototypeAccessor(proto, Nan::New("shadingRatePaletteEntryCount").ToLocalChecked(), GetshadingRatePaletteEntryCount, SetshadingRatePaletteEntryCount, ctor);
  SetPrototypeAccessor(proto, Nan::New("pShadingRatePaletteEntries").ToLocalChecked(), GetpShadingRatePaletteEntries, SetpShadingRatePaletteEntries, ctor);
  Nan::Set(target, Nan::New("VkShadingRatePaletteNV").ToLocalChecked(), ctor->GetFunction());
}

bool _VkShadingRatePaletteNV::flush() {
  _VkShadingRatePaletteNV *self = this;
  
  return true;
}

NAN_METHOD(_VkShadingRatePaletteNV::New) {
  if (info.IsConstructCall()) {
    _VkShadingRatePaletteNV* self = new _VkShadingRatePaletteNV();
    self->Wrap(info.Holder());
    
    if (info[0]->IsObject()) {
      v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();
      v8::Local<v8::String> sAccess0 = Nan::New("shadingRatePaletteEntryCount").ToLocalChecked();
      v8::Local<v8::String> sAccess1 = Nan::New("pShadingRatePaletteEntries").ToLocalChecked();
      if (obj->Has(sAccess0)) info.This()->Set(sAccess0, obj->Get(sAccess0));
      if (obj->Has(sAccess1)) info.This()->Set(sAccess1, obj->Get(sAccess1));
      
    }
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkShadingRatePaletteNV constructor cannot be invoked without 'new'");
  }
};

// shadingRatePaletteEntryCount
NAN_GETTER(_VkShadingRatePaletteNV::GetshadingRatePaletteEntryCount) {
  _VkShadingRatePaletteNV *self = Nan::ObjectWrap::Unwrap<_VkShadingRatePaletteNV>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.shadingRatePaletteEntryCount));
}NAN_SETTER(_VkShadingRatePaletteNV::SetshadingRatePaletteEntryCount) {
  _VkShadingRatePaletteNV *self = Nan::ObjectWrap::Unwrap<_VkShadingRatePaletteNV>(info.This());
  if (value->IsNumber()) {
    self->instance.shadingRatePaletteEntryCount = static_cast<uint32_t>(Nan::To<int64_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkShadingRatePaletteNV.shadingRatePaletteEntryCount' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// pShadingRatePaletteEntries
NAN_GETTER(_VkShadingRatePaletteNV::GetpShadingRatePaletteEntries) {
  _VkShadingRatePaletteNV *self = Nan::ObjectWrap::Unwrap<_VkShadingRatePaletteNV>(info.This());
  if (self->pShadingRatePaletteEntries.IsEmpty()) {
    info.GetReturnValue().SetNull();
  } else {
    v8::Local<v8::Object> obj = Nan::New(self->pShadingRatePaletteEntries);
    info.GetReturnValue().Set(obj);
  }
}NAN_SETTER(_VkShadingRatePaletteNV::SetpShadingRatePaletteEntries) {
  _VkShadingRatePaletteNV *self = Nan::ObjectWrap::Unwrap<_VkShadingRatePaletteNV>(info.This());
  
    // js
    if (value->IsArrayBufferView()) {
      if (value->IsInt32Array()) {
        self->pShadingRatePaletteEntries.Reset<v8::Array>(value.As<v8::Array>());
      } else {
        
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Int32Array' for 'VkShadingRatePaletteNV.pShadingRatePaletteEntries' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
        return;
      }
    } else if (value->IsNull()) {
      self->pShadingRatePaletteEntries.Reset();
    } else {
      
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Int32Array' for 'VkShadingRatePaletteNV.pShadingRatePaletteEntries' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
      return;
    }
  
  
  // vulkan
  if (value->IsArrayBufferView()) {
    self->instance.pShadingRatePaletteEntries = reinterpret_cast<const VkShadingRatePaletteEntryNV *>(getTypedArrayData<int32_t>(Nan::To<v8::Object>(value).ToLocalChecked(), nullptr));
  } else {
    self->instance.pShadingRatePaletteEntries = nullptr;
  }
}