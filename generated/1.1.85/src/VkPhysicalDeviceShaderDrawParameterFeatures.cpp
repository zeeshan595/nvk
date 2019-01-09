/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.4
 */
#include "utils.h"
#include "index.h"
#include "VkPhysicalDeviceShaderDrawParameterFeatures.h"

Nan::Persistent<v8::FunctionTemplate> _VkPhysicalDeviceShaderDrawParameterFeatures::constructor;

_VkPhysicalDeviceShaderDrawParameterFeatures::_VkPhysicalDeviceShaderDrawParameterFeatures() {
  instance.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES;
  
}

_VkPhysicalDeviceShaderDrawParameterFeatures::~_VkPhysicalDeviceShaderDrawParameterFeatures() {
  //printf("VkPhysicalDeviceShaderDrawParameterFeatures deconstructed!!\n");
  
  
  
}

void _VkPhysicalDeviceShaderDrawParameterFeatures::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkPhysicalDeviceShaderDrawParameterFeatures::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkPhysicalDeviceShaderDrawParameterFeatures").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  SetPrototypeAccessor(proto, Nan::New("sType").ToLocalChecked(), GetsType, SetsType, ctor);
  SetPrototypeAccessor(proto, Nan::New("shaderDrawParameters").ToLocalChecked(), GetshaderDrawParameters, SetshaderDrawParameters, ctor);
  Nan::Set(target, Nan::New("VkPhysicalDeviceShaderDrawParameterFeatures").ToLocalChecked(), ctor->GetFunction());
}

bool _VkPhysicalDeviceShaderDrawParameterFeatures::flush() {
  _VkPhysicalDeviceShaderDrawParameterFeatures *self = this;
  
  return true;
}

NAN_METHOD(_VkPhysicalDeviceShaderDrawParameterFeatures::New) {
  if (info.IsConstructCall()) {
    _VkPhysicalDeviceShaderDrawParameterFeatures* self = new _VkPhysicalDeviceShaderDrawParameterFeatures();
    self->Wrap(info.Holder());
    
    if (info[0]->IsObject()) {
      v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();
      v8::Local<v8::String> sAccess0 = Nan::New("sType").ToLocalChecked();
      v8::Local<v8::String> sAccess2 = Nan::New("shaderDrawParameters").ToLocalChecked();
      if (obj->Has(sAccess0)) info.This()->Set(sAccess0, obj->Get(sAccess0));
      if (obj->Has(sAccess2)) info.This()->Set(sAccess2, obj->Get(sAccess2));
      
    }
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkPhysicalDeviceShaderDrawParameterFeatures constructor cannot be invoked without 'new'");
  }
};

// sType
NAN_GETTER(_VkPhysicalDeviceShaderDrawParameterFeatures::GetsType) {
  _VkPhysicalDeviceShaderDrawParameterFeatures *self = Nan::ObjectWrap::Unwrap<_VkPhysicalDeviceShaderDrawParameterFeatures>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.sType));
}NAN_SETTER(_VkPhysicalDeviceShaderDrawParameterFeatures::SetsType) {
  _VkPhysicalDeviceShaderDrawParameterFeatures *self = Nan::ObjectWrap::Unwrap<_VkPhysicalDeviceShaderDrawParameterFeatures>(info.This());
  if (value->IsNumber()) {
    self->instance.sType = static_cast<VkStructureType>(Nan::To<int32_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkPhysicalDeviceShaderDrawParameterFeatures.sType' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// shaderDrawParameters
NAN_GETTER(_VkPhysicalDeviceShaderDrawParameterFeatures::GetshaderDrawParameters) {
  _VkPhysicalDeviceShaderDrawParameterFeatures *self = Nan::ObjectWrap::Unwrap<_VkPhysicalDeviceShaderDrawParameterFeatures>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.shaderDrawParameters));
}NAN_SETTER(_VkPhysicalDeviceShaderDrawParameterFeatures::SetshaderDrawParameters) {
  _VkPhysicalDeviceShaderDrawParameterFeatures *self = Nan::ObjectWrap::Unwrap<_VkPhysicalDeviceShaderDrawParameterFeatures>(info.This());
  if (value->IsBoolean() || value->IsNumber()) {
    self->instance.shaderDrawParameters = static_cast<uint32_t>(Nan::To<bool>(value).FromMaybe(false)) ? VK_TRUE : VK_FALSE;
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkPhysicalDeviceShaderDrawParameterFeatures.shaderDrawParameters' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}