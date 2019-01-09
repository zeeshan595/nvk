/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.5
 */
#include "utils.h"
#include "index.h"
#include "VkPipelineRasterizationConservativeStateCreateInfoEXT.h"

Nan::Persistent<v8::FunctionTemplate> _VkPipelineRasterizationConservativeStateCreateInfoEXT::constructor;

_VkPipelineRasterizationConservativeStateCreateInfoEXT::_VkPipelineRasterizationConservativeStateCreateInfoEXT() {
  instance.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT;
  
}

_VkPipelineRasterizationConservativeStateCreateInfoEXT::~_VkPipelineRasterizationConservativeStateCreateInfoEXT() {
  //printf("VkPipelineRasterizationConservativeStateCreateInfoEXT deconstructed!!\n");
  
  
  
  
  
}

void _VkPipelineRasterizationConservativeStateCreateInfoEXT::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkPipelineRasterizationConservativeStateCreateInfoEXT::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkPipelineRasterizationConservativeStateCreateInfoEXT").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  SetPrototypeAccessor(proto, Nan::New("sType").ToLocalChecked(), GetsType, SetsType, ctor);
  SetPrototypeAccessor(proto, Nan::New("flags").ToLocalChecked(), Getflags, Setflags, ctor);
  SetPrototypeAccessor(proto, Nan::New("conservativeRasterizationMode").ToLocalChecked(), GetconservativeRasterizationMode, SetconservativeRasterizationMode, ctor);
  SetPrototypeAccessor(proto, Nan::New("extraPrimitiveOverestimationSize").ToLocalChecked(), GetextraPrimitiveOverestimationSize, SetextraPrimitiveOverestimationSize, ctor);
  Nan::Set(target, Nan::New("VkPipelineRasterizationConservativeStateCreateInfoEXT").ToLocalChecked(), ctor->GetFunction());
}

bool _VkPipelineRasterizationConservativeStateCreateInfoEXT::flush() {
  _VkPipelineRasterizationConservativeStateCreateInfoEXT *self = this;
  
  return true;
}

NAN_METHOD(_VkPipelineRasterizationConservativeStateCreateInfoEXT::New) {
  if (info.IsConstructCall()) {
    _VkPipelineRasterizationConservativeStateCreateInfoEXT* self = new _VkPipelineRasterizationConservativeStateCreateInfoEXT();
    self->Wrap(info.Holder());
    
    if (info[0]->IsObject()) {
      v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();
      v8::Local<v8::String> sAccess0 = Nan::New("sType").ToLocalChecked();
      v8::Local<v8::String> sAccess2 = Nan::New("flags").ToLocalChecked();
      v8::Local<v8::String> sAccess3 = Nan::New("conservativeRasterizationMode").ToLocalChecked();
      v8::Local<v8::String> sAccess4 = Nan::New("extraPrimitiveOverestimationSize").ToLocalChecked();
      if (obj->Has(sAccess0)) info.This()->Set(sAccess0, obj->Get(sAccess0));
      if (obj->Has(sAccess2)) info.This()->Set(sAccess2, obj->Get(sAccess2));
      if (obj->Has(sAccess3)) info.This()->Set(sAccess3, obj->Get(sAccess3));
      if (obj->Has(sAccess4)) info.This()->Set(sAccess4, obj->Get(sAccess4));
      
    }
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkPipelineRasterizationConservativeStateCreateInfoEXT constructor cannot be invoked without 'new'");
  }
};

// sType
NAN_GETTER(_VkPipelineRasterizationConservativeStateCreateInfoEXT::GetsType) {
  _VkPipelineRasterizationConservativeStateCreateInfoEXT *self = Nan::ObjectWrap::Unwrap<_VkPipelineRasterizationConservativeStateCreateInfoEXT>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.sType));
}NAN_SETTER(_VkPipelineRasterizationConservativeStateCreateInfoEXT::SetsType) {
  _VkPipelineRasterizationConservativeStateCreateInfoEXT *self = Nan::ObjectWrap::Unwrap<_VkPipelineRasterizationConservativeStateCreateInfoEXT>(info.This());
  if (value->IsNumber()) {
    self->instance.sType = static_cast<VkStructureType>(Nan::To<int32_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkPipelineRasterizationConservativeStateCreateInfoEXT.sType' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// flags
NAN_GETTER(_VkPipelineRasterizationConservativeStateCreateInfoEXT::Getflags) {
  _VkPipelineRasterizationConservativeStateCreateInfoEXT *self = Nan::ObjectWrap::Unwrap<_VkPipelineRasterizationConservativeStateCreateInfoEXT>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.flags));
}NAN_SETTER(_VkPipelineRasterizationConservativeStateCreateInfoEXT::Setflags) {
  _VkPipelineRasterizationConservativeStateCreateInfoEXT *self = Nan::ObjectWrap::Unwrap<_VkPipelineRasterizationConservativeStateCreateInfoEXT>(info.This());
  if (value->IsNumber()) {
    self->instance.flags = static_cast<VkPipelineRasterizationConservativeStateCreateFlagsEXT>(Nan::To<int32_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkPipelineRasterizationConservativeStateCreateInfoEXT.flags' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// conservativeRasterizationMode
NAN_GETTER(_VkPipelineRasterizationConservativeStateCreateInfoEXT::GetconservativeRasterizationMode) {
  _VkPipelineRasterizationConservativeStateCreateInfoEXT *self = Nan::ObjectWrap::Unwrap<_VkPipelineRasterizationConservativeStateCreateInfoEXT>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.conservativeRasterizationMode));
}NAN_SETTER(_VkPipelineRasterizationConservativeStateCreateInfoEXT::SetconservativeRasterizationMode) {
  _VkPipelineRasterizationConservativeStateCreateInfoEXT *self = Nan::ObjectWrap::Unwrap<_VkPipelineRasterizationConservativeStateCreateInfoEXT>(info.This());
  if (value->IsNumber()) {
    self->instance.conservativeRasterizationMode = static_cast<VkConservativeRasterizationModeEXT>(Nan::To<int32_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkPipelineRasterizationConservativeStateCreateInfoEXT.conservativeRasterizationMode' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// extraPrimitiveOverestimationSize
NAN_GETTER(_VkPipelineRasterizationConservativeStateCreateInfoEXT::GetextraPrimitiveOverestimationSize) {
  _VkPipelineRasterizationConservativeStateCreateInfoEXT *self = Nan::ObjectWrap::Unwrap<_VkPipelineRasterizationConservativeStateCreateInfoEXT>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.extraPrimitiveOverestimationSize));
}NAN_SETTER(_VkPipelineRasterizationConservativeStateCreateInfoEXT::SetextraPrimitiveOverestimationSize) {
  _VkPipelineRasterizationConservativeStateCreateInfoEXT *self = Nan::ObjectWrap::Unwrap<_VkPipelineRasterizationConservativeStateCreateInfoEXT>(info.This());
  if (value->IsNumber()) {
    self->instance.extraPrimitiveOverestimationSize = static_cast<float>(Nan::To<int64_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkPipelineRasterizationConservativeStateCreateInfoEXT.extraPrimitiveOverestimationSize' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}