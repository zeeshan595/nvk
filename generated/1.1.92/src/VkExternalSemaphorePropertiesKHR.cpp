/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.5
 */
#include "utils.h"
#include "index.h"
#include "VkExternalSemaphorePropertiesKHR.h"

Nan::Persistent<v8::FunctionTemplate> _VkExternalSemaphorePropertiesKHR::constructor;

_VkExternalSemaphorePropertiesKHR::_VkExternalSemaphorePropertiesKHR() {
  
  
}

_VkExternalSemaphorePropertiesKHR::~_VkExternalSemaphorePropertiesKHR() {
  //printf("VkExternalSemaphorePropertiesKHR deconstructed!!\n");
  
}

void _VkExternalSemaphorePropertiesKHR::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkExternalSemaphorePropertiesKHR::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkExternalSemaphorePropertiesKHR").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  Nan::Set(target, Nan::New("VkExternalSemaphorePropertiesKHR").ToLocalChecked(), ctor->GetFunction());
}

bool _VkExternalSemaphorePropertiesKHR::flush() {
  _VkExternalSemaphorePropertiesKHR *self = this;
  
  return true;
}

NAN_METHOD(_VkExternalSemaphorePropertiesKHR::New) {
  if (info.IsConstructCall()) {
    _VkExternalSemaphorePropertiesKHR* self = new _VkExternalSemaphorePropertiesKHR();
    self->Wrap(info.Holder());
    
    if (info[0]->IsObject()) {
      v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();
      
    }
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkExternalSemaphorePropertiesKHR constructor cannot be invoked without 'new'");
  }
};
