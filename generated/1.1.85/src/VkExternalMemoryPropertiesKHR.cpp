/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.4
 */
#include "utils.h"
#include "index.h"
#include "VkExternalMemoryPropertiesKHR.h"

Nan::Persistent<v8::FunctionTemplate> _VkExternalMemoryPropertiesKHR::constructor;

_VkExternalMemoryPropertiesKHR::_VkExternalMemoryPropertiesKHR() {
  
  
}

_VkExternalMemoryPropertiesKHR::~_VkExternalMemoryPropertiesKHR() {
  //printf("VkExternalMemoryPropertiesKHR deconstructed!!\n");
  
}

void _VkExternalMemoryPropertiesKHR::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkExternalMemoryPropertiesKHR::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkExternalMemoryPropertiesKHR").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  Nan::Set(target, Nan::New("VkExternalMemoryPropertiesKHR").ToLocalChecked(), ctor->GetFunction());
}

bool _VkExternalMemoryPropertiesKHR::flush() {
  _VkExternalMemoryPropertiesKHR *self = this;
  
  return true;
}

NAN_METHOD(_VkExternalMemoryPropertiesKHR::New) {
  if (info.IsConstructCall()) {
    _VkExternalMemoryPropertiesKHR* self = new _VkExternalMemoryPropertiesKHR();
    self->Wrap(info.Holder());
    
    if (info[0]->IsObject()) {
      v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();
      
    }
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkExternalMemoryPropertiesKHR constructor cannot be invoked without 'new'");
  }
};
