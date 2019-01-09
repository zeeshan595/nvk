/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.5
 */
#include "utils.h"
#include "index.h"
#include "VkImageFormatProperties2.h"

Nan::Persistent<v8::FunctionTemplate> _VkImageFormatProperties2::constructor;

_VkImageFormatProperties2::_VkImageFormatProperties2() {
  instance.sType = VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2;
  
}

_VkImageFormatProperties2::~_VkImageFormatProperties2() {
  //printf("VkImageFormatProperties2 deconstructed!!\n");
  
  
  
}

void _VkImageFormatProperties2::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkImageFormatProperties2::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkImageFormatProperties2").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  SetPrototypeAccessor(proto, Nan::New("sType").ToLocalChecked(), GetsType, nullptr, ctor);
  SetPrototypeAccessor(proto, Nan::New("imageFormatProperties").ToLocalChecked(), GetimageFormatProperties, nullptr, ctor);
  Nan::Set(target, Nan::New("VkImageFormatProperties2").ToLocalChecked(), ctor->GetFunction());
}

bool _VkImageFormatProperties2::flush() {
  _VkImageFormatProperties2 *self = this;
  if (!(self->imageFormatProperties.IsEmpty())) {
    v8::Local<v8::Value> value = Nan::New(self->imageFormatProperties);
    
  }
  return true;
}

NAN_METHOD(_VkImageFormatProperties2::New) {
  if (info.IsConstructCall()) {
    _VkImageFormatProperties2* self = new _VkImageFormatProperties2();
    self->Wrap(info.Holder());
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkImageFormatProperties2 constructor cannot be invoked without 'new'");
  }
};

// sType
NAN_GETTER(_VkImageFormatProperties2::GetsType) {
  _VkImageFormatProperties2 *self = Nan::ObjectWrap::Unwrap<_VkImageFormatProperties2>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.sType));
}// imageFormatProperties
NAN_GETTER(_VkImageFormatProperties2::GetimageFormatProperties) {
  _VkImageFormatProperties2 *self = Nan::ObjectWrap::Unwrap<_VkImageFormatProperties2>(info.This());
  if (self->imageFormatProperties.IsEmpty()) {
    info.GetReturnValue().SetNull();
  } else {
    v8::Local<v8::Object> obj = Nan::New(self->imageFormatProperties);
    info.GetReturnValue().Set(obj);
  }
}