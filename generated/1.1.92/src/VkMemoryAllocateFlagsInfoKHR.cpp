/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.5
 */
#include "utils.h"
#include "index.h"
#include "VkMemoryAllocateFlagsInfoKHR.h"

Nan::Persistent<v8::FunctionTemplate> _VkMemoryAllocateFlagsInfoKHR::constructor;

_VkMemoryAllocateFlagsInfoKHR::_VkMemoryAllocateFlagsInfoKHR() {
  
  
}

_VkMemoryAllocateFlagsInfoKHR::~_VkMemoryAllocateFlagsInfoKHR() {
  //printf("VkMemoryAllocateFlagsInfoKHR deconstructed!!\n");
  
}

void _VkMemoryAllocateFlagsInfoKHR::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkMemoryAllocateFlagsInfoKHR::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkMemoryAllocateFlagsInfoKHR").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  Nan::Set(target, Nan::New("VkMemoryAllocateFlagsInfoKHR").ToLocalChecked(), ctor->GetFunction());
}

bool _VkMemoryAllocateFlagsInfoKHR::flush() {
  _VkMemoryAllocateFlagsInfoKHR *self = this;
  
  return true;
}

NAN_METHOD(_VkMemoryAllocateFlagsInfoKHR::New) {
  if (info.IsConstructCall()) {
    _VkMemoryAllocateFlagsInfoKHR* self = new _VkMemoryAllocateFlagsInfoKHR();
    self->Wrap(info.Holder());
    
    if (info[0]->IsObject()) {
      v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();
      
    }
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkMemoryAllocateFlagsInfoKHR constructor cannot be invoked without 'new'");
  }
};
