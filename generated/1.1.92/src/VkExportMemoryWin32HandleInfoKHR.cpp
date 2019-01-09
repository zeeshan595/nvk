/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.5
 */
#include "utils.h"
#include "index.h"
#include "VkExportMemoryWin32HandleInfoKHR.h"

Nan::Persistent<v8::FunctionTemplate> _VkExportMemoryWin32HandleInfoKHR::constructor;

_VkExportMemoryWin32HandleInfoKHR::_VkExportMemoryWin32HandleInfoKHR() {
  instance.sType = VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR;
  
}

_VkExportMemoryWin32HandleInfoKHR::~_VkExportMemoryWin32HandleInfoKHR() {
  //printf("VkExportMemoryWin32HandleInfoKHR deconstructed!!\n");
  
  
}

void _VkExportMemoryWin32HandleInfoKHR::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkExportMemoryWin32HandleInfoKHR::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkExportMemoryWin32HandleInfoKHR").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  SetPrototypeAccessor(proto, Nan::New("sType").ToLocalChecked(), GetsType, SetsType, ctor);
  Nan::Set(target, Nan::New("VkExportMemoryWin32HandleInfoKHR").ToLocalChecked(), ctor->GetFunction());
}

bool _VkExportMemoryWin32HandleInfoKHR::flush() {
  _VkExportMemoryWin32HandleInfoKHR *self = this;
  
  return true;
}

NAN_METHOD(_VkExportMemoryWin32HandleInfoKHR::New) {
  if (info.IsConstructCall()) {
    _VkExportMemoryWin32HandleInfoKHR* self = new _VkExportMemoryWin32HandleInfoKHR();
    self->Wrap(info.Holder());
    
    if (info[0]->IsObject()) {
      v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();
      v8::Local<v8::String> sAccess0 = Nan::New("sType").ToLocalChecked();
      if (obj->Has(sAccess0)) info.This()->Set(sAccess0, obj->Get(sAccess0));
      
    }
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkExportMemoryWin32HandleInfoKHR constructor cannot be invoked without 'new'");
  }
};

// sType
NAN_GETTER(_VkExportMemoryWin32HandleInfoKHR::GetsType) {
  _VkExportMemoryWin32HandleInfoKHR *self = Nan::ObjectWrap::Unwrap<_VkExportMemoryWin32HandleInfoKHR>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.sType));
}NAN_SETTER(_VkExportMemoryWin32HandleInfoKHR::SetsType) {
  _VkExportMemoryWin32HandleInfoKHR *self = Nan::ObjectWrap::Unwrap<_VkExportMemoryWin32HandleInfoKHR>(info.This());
  if (value->IsNumber()) {
    self->instance.sType = static_cast<VkStructureType>(Nan::To<int32_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkExportMemoryWin32HandleInfoKHR.sType' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}