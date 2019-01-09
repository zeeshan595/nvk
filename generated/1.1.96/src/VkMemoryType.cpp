/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.4
 */
#include "utils.h"
#include "index.h"
#include "VkMemoryType.h"

Nan::Persistent<v8::FunctionTemplate> _VkMemoryType::constructor;

_VkMemoryType::_VkMemoryType() {
  
  
}

_VkMemoryType::~_VkMemoryType() {
  //printf("VkMemoryType deconstructed!!\n");
  
  
  
}

void _VkMemoryType::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkMemoryType::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkMemoryType").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  SetPrototypeAccessor(proto, Nan::New("propertyFlags").ToLocalChecked(), GetpropertyFlags, nullptr, ctor);
  SetPrototypeAccessor(proto, Nan::New("heapIndex").ToLocalChecked(), GetheapIndex, nullptr, ctor);
  Nan::Set(target, Nan::New("VkMemoryType").ToLocalChecked(), ctor->GetFunction());
}

bool _VkMemoryType::flush() {
  _VkMemoryType *self = this;
  
  return true;
}

NAN_METHOD(_VkMemoryType::New) {
  if (info.IsConstructCall()) {
    _VkMemoryType* self = new _VkMemoryType();
    self->Wrap(info.Holder());
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkMemoryType constructor cannot be invoked without 'new'");
  }
};

// propertyFlags
NAN_GETTER(_VkMemoryType::GetpropertyFlags) {
  _VkMemoryType *self = Nan::ObjectWrap::Unwrap<_VkMemoryType>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.propertyFlags));
}// heapIndex
NAN_GETTER(_VkMemoryType::GetheapIndex) {
  _VkMemoryType *self = Nan::ObjectWrap::Unwrap<_VkMemoryType>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.heapIndex));
}