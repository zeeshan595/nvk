/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.5
 */
#include "utils.h"
#include "index.h"
#include "VkDeviceGroupCommandBufferBeginInfoKHR.h"

Nan::Persistent<v8::FunctionTemplate> _VkDeviceGroupCommandBufferBeginInfoKHR::constructor;

_VkDeviceGroupCommandBufferBeginInfoKHR::_VkDeviceGroupCommandBufferBeginInfoKHR() {
  
  
}

_VkDeviceGroupCommandBufferBeginInfoKHR::~_VkDeviceGroupCommandBufferBeginInfoKHR() {
  //printf("VkDeviceGroupCommandBufferBeginInfoKHR deconstructed!!\n");
  
}

void _VkDeviceGroupCommandBufferBeginInfoKHR::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkDeviceGroupCommandBufferBeginInfoKHR::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkDeviceGroupCommandBufferBeginInfoKHR").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  Nan::Set(target, Nan::New("VkDeviceGroupCommandBufferBeginInfoKHR").ToLocalChecked(), ctor->GetFunction());
}

bool _VkDeviceGroupCommandBufferBeginInfoKHR::flush() {
  _VkDeviceGroupCommandBufferBeginInfoKHR *self = this;
  
  return true;
}

NAN_METHOD(_VkDeviceGroupCommandBufferBeginInfoKHR::New) {
  if (info.IsConstructCall()) {
    _VkDeviceGroupCommandBufferBeginInfoKHR* self = new _VkDeviceGroupCommandBufferBeginInfoKHR();
    self->Wrap(info.Holder());
    
    if (info[0]->IsObject()) {
      v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();
      
    }
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkDeviceGroupCommandBufferBeginInfoKHR constructor cannot be invoked without 'new'");
  }
};
