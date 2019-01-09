/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.4
 */
#include "utils.h"
#include "index.h"
#include "VkPhysicalDeviceFragmentDensityMapPropertiesEXT.h"

Nan::Persistent<v8::FunctionTemplate> _VkPhysicalDeviceFragmentDensityMapPropertiesEXT::constructor;

_VkPhysicalDeviceFragmentDensityMapPropertiesEXT::_VkPhysicalDeviceFragmentDensityMapPropertiesEXT() {
  instance.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT;
  
}

_VkPhysicalDeviceFragmentDensityMapPropertiesEXT::~_VkPhysicalDeviceFragmentDensityMapPropertiesEXT() {
  //printf("VkPhysicalDeviceFragmentDensityMapPropertiesEXT deconstructed!!\n");
  
  
  
  
  
}

void _VkPhysicalDeviceFragmentDensityMapPropertiesEXT::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkPhysicalDeviceFragmentDensityMapPropertiesEXT::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkPhysicalDeviceFragmentDensityMapPropertiesEXT").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  SetPrototypeAccessor(proto, Nan::New("sType").ToLocalChecked(), GetsType, nullptr, ctor);
  SetPrototypeAccessor(proto, Nan::New("minFragmentDensityTexelSize").ToLocalChecked(), GetminFragmentDensityTexelSize, nullptr, ctor);
  SetPrototypeAccessor(proto, Nan::New("maxFragmentDensityTexelSize").ToLocalChecked(), GetmaxFragmentDensityTexelSize, nullptr, ctor);
  SetPrototypeAccessor(proto, Nan::New("fragmentDensityInvocations").ToLocalChecked(), GetfragmentDensityInvocations, nullptr, ctor);
  Nan::Set(target, Nan::New("VkPhysicalDeviceFragmentDensityMapPropertiesEXT").ToLocalChecked(), ctor->GetFunction());
}

bool _VkPhysicalDeviceFragmentDensityMapPropertiesEXT::flush() {
  _VkPhysicalDeviceFragmentDensityMapPropertiesEXT *self = this;
  if (!(self->minFragmentDensityTexelSize.IsEmpty())) {
    v8::Local<v8::Value> value = Nan::New(self->minFragmentDensityTexelSize);
    
  }if (!(self->maxFragmentDensityTexelSize.IsEmpty())) {
    v8::Local<v8::Value> value = Nan::New(self->maxFragmentDensityTexelSize);
    
  }
  return true;
}

NAN_METHOD(_VkPhysicalDeviceFragmentDensityMapPropertiesEXT::New) {
  if (info.IsConstructCall()) {
    _VkPhysicalDeviceFragmentDensityMapPropertiesEXT* self = new _VkPhysicalDeviceFragmentDensityMapPropertiesEXT();
    self->Wrap(info.Holder());
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkPhysicalDeviceFragmentDensityMapPropertiesEXT constructor cannot be invoked without 'new'");
  }
};

// sType
NAN_GETTER(_VkPhysicalDeviceFragmentDensityMapPropertiesEXT::GetsType) {
  _VkPhysicalDeviceFragmentDensityMapPropertiesEXT *self = Nan::ObjectWrap::Unwrap<_VkPhysicalDeviceFragmentDensityMapPropertiesEXT>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.sType));
}// minFragmentDensityTexelSize
NAN_GETTER(_VkPhysicalDeviceFragmentDensityMapPropertiesEXT::GetminFragmentDensityTexelSize) {
  _VkPhysicalDeviceFragmentDensityMapPropertiesEXT *self = Nan::ObjectWrap::Unwrap<_VkPhysicalDeviceFragmentDensityMapPropertiesEXT>(info.This());
  if (self->minFragmentDensityTexelSize.IsEmpty()) {
    info.GetReturnValue().SetNull();
  } else {
    v8::Local<v8::Object> obj = Nan::New(self->minFragmentDensityTexelSize);
    info.GetReturnValue().Set(obj);
  }
}// maxFragmentDensityTexelSize
NAN_GETTER(_VkPhysicalDeviceFragmentDensityMapPropertiesEXT::GetmaxFragmentDensityTexelSize) {
  _VkPhysicalDeviceFragmentDensityMapPropertiesEXT *self = Nan::ObjectWrap::Unwrap<_VkPhysicalDeviceFragmentDensityMapPropertiesEXT>(info.This());
  if (self->maxFragmentDensityTexelSize.IsEmpty()) {
    info.GetReturnValue().SetNull();
  } else {
    v8::Local<v8::Object> obj = Nan::New(self->maxFragmentDensityTexelSize);
    info.GetReturnValue().Set(obj);
  }
}// fragmentDensityInvocations
NAN_GETTER(_VkPhysicalDeviceFragmentDensityMapPropertiesEXT::GetfragmentDensityInvocations) {
  _VkPhysicalDeviceFragmentDensityMapPropertiesEXT *self = Nan::ObjectWrap::Unwrap<_VkPhysicalDeviceFragmentDensityMapPropertiesEXT>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.fragmentDensityInvocations));
}