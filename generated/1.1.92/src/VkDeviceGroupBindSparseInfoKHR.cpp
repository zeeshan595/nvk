/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.5
 */
#include "utils.h"
#include "index.h"
#include "VkDeviceGroupBindSparseInfoKHR.h"

Nan::Persistent<v8::FunctionTemplate> _VkDeviceGroupBindSparseInfoKHR::constructor;

_VkDeviceGroupBindSparseInfoKHR::_VkDeviceGroupBindSparseInfoKHR() {
  
  
}

_VkDeviceGroupBindSparseInfoKHR::~_VkDeviceGroupBindSparseInfoKHR() {
  //printf("VkDeviceGroupBindSparseInfoKHR deconstructed!!\n");
  
}

void _VkDeviceGroupBindSparseInfoKHR::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkDeviceGroupBindSparseInfoKHR::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkDeviceGroupBindSparseInfoKHR").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  Nan::Set(target, Nan::New("VkDeviceGroupBindSparseInfoKHR").ToLocalChecked(), ctor->GetFunction());
}

bool _VkDeviceGroupBindSparseInfoKHR::flush() {
  _VkDeviceGroupBindSparseInfoKHR *self = this;
  
  return true;
}

NAN_METHOD(_VkDeviceGroupBindSparseInfoKHR::New) {
  if (info.IsConstructCall()) {
    _VkDeviceGroupBindSparseInfoKHR* self = new _VkDeviceGroupBindSparseInfoKHR();
    self->Wrap(info.Holder());
    
    if (info[0]->IsObject()) {
      v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();
      
    }
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkDeviceGroupBindSparseInfoKHR constructor cannot be invoked without 'new'");
  }
};
