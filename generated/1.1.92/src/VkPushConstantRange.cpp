/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.5
 */
#include "utils.h"
#include "index.h"
#include "VkPushConstantRange.h"

Nan::Persistent<v8::FunctionTemplate> _VkPushConstantRange::constructor;

_VkPushConstantRange::_VkPushConstantRange() {
  
  
}

_VkPushConstantRange::~_VkPushConstantRange() {
  //printf("VkPushConstantRange deconstructed!!\n");
  
  
  
  
}

void _VkPushConstantRange::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkPushConstantRange::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkPushConstantRange").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  SetPrototypeAccessor(proto, Nan::New("stageFlags").ToLocalChecked(), GetstageFlags, SetstageFlags, ctor);
  SetPrototypeAccessor(proto, Nan::New("offset").ToLocalChecked(), Getoffset, Setoffset, ctor);
  SetPrototypeAccessor(proto, Nan::New("size").ToLocalChecked(), Getsize, Setsize, ctor);
  Nan::Set(target, Nan::New("VkPushConstantRange").ToLocalChecked(), ctor->GetFunction());
}

bool _VkPushConstantRange::flush() {
  _VkPushConstantRange *self = this;
  
  return true;
}

NAN_METHOD(_VkPushConstantRange::New) {
  if (info.IsConstructCall()) {
    _VkPushConstantRange* self = new _VkPushConstantRange();
    self->Wrap(info.Holder());
    
    if (info[0]->IsObject()) {
      v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();
      v8::Local<v8::String> sAccess0 = Nan::New("stageFlags").ToLocalChecked();
      v8::Local<v8::String> sAccess1 = Nan::New("offset").ToLocalChecked();
      v8::Local<v8::String> sAccess2 = Nan::New("size").ToLocalChecked();
      if (obj->Has(sAccess0)) info.This()->Set(sAccess0, obj->Get(sAccess0));
      if (obj->Has(sAccess1)) info.This()->Set(sAccess1, obj->Get(sAccess1));
      if (obj->Has(sAccess2)) info.This()->Set(sAccess2, obj->Get(sAccess2));
      
    }
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkPushConstantRange constructor cannot be invoked without 'new'");
  }
};

// stageFlags
NAN_GETTER(_VkPushConstantRange::GetstageFlags) {
  _VkPushConstantRange *self = Nan::ObjectWrap::Unwrap<_VkPushConstantRange>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.stageFlags));
}NAN_SETTER(_VkPushConstantRange::SetstageFlags) {
  _VkPushConstantRange *self = Nan::ObjectWrap::Unwrap<_VkPushConstantRange>(info.This());
  if (value->IsNumber()) {
    self->instance.stageFlags = static_cast<VkShaderStageFlags>(Nan::To<int32_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkPushConstantRange.stageFlags' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// offset
NAN_GETTER(_VkPushConstantRange::Getoffset) {
  _VkPushConstantRange *self = Nan::ObjectWrap::Unwrap<_VkPushConstantRange>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.offset));
}NAN_SETTER(_VkPushConstantRange::Setoffset) {
  _VkPushConstantRange *self = Nan::ObjectWrap::Unwrap<_VkPushConstantRange>(info.This());
  if (value->IsNumber()) {
    self->instance.offset = static_cast<uint32_t>(Nan::To<int64_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkPushConstantRange.offset' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// size
NAN_GETTER(_VkPushConstantRange::Getsize) {
  _VkPushConstantRange *self = Nan::ObjectWrap::Unwrap<_VkPushConstantRange>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.size));
}NAN_SETTER(_VkPushConstantRange::Setsize) {
  _VkPushConstantRange *self = Nan::ObjectWrap::Unwrap<_VkPushConstantRange>(info.This());
  if (value->IsNumber()) {
    self->instance.size = static_cast<uint32_t>(Nan::To<int64_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkPushConstantRange.size' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}