/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.4
 */
#include "utils.h"
#include "index.h"
#include "VkPhysicalDeviceSparseImageFormatInfo2KHR.h"

Nan::Persistent<v8::FunctionTemplate> _VkPhysicalDeviceSparseImageFormatInfo2KHR::constructor;

_VkPhysicalDeviceSparseImageFormatInfo2KHR::_VkPhysicalDeviceSparseImageFormatInfo2KHR() {
  
  
}

_VkPhysicalDeviceSparseImageFormatInfo2KHR::~_VkPhysicalDeviceSparseImageFormatInfo2KHR() {
  //printf("VkPhysicalDeviceSparseImageFormatInfo2KHR deconstructed!!\n");
  
}

void _VkPhysicalDeviceSparseImageFormatInfo2KHR::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkPhysicalDeviceSparseImageFormatInfo2KHR::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkPhysicalDeviceSparseImageFormatInfo2KHR").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  Nan::Set(target, Nan::New("VkPhysicalDeviceSparseImageFormatInfo2KHR").ToLocalChecked(), ctor->GetFunction());
}

bool _VkPhysicalDeviceSparseImageFormatInfo2KHR::flush() {
  _VkPhysicalDeviceSparseImageFormatInfo2KHR *self = this;
  
  return true;
}

NAN_METHOD(_VkPhysicalDeviceSparseImageFormatInfo2KHR::New) {
  if (info.IsConstructCall()) {
    _VkPhysicalDeviceSparseImageFormatInfo2KHR* self = new _VkPhysicalDeviceSparseImageFormatInfo2KHR();
    self->Wrap(info.Holder());
    
    if (info[0]->IsObject()) {
      v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();
      
    }
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkPhysicalDeviceSparseImageFormatInfo2KHR constructor cannot be invoked without 'new'");
  }
};
