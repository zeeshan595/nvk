/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.5
 */
#include "utils.h"
#include "index.h"
#include "VkCmdReserveSpaceForCommandsInfoNVX.h"

Nan::Persistent<v8::FunctionTemplate> _VkCmdReserveSpaceForCommandsInfoNVX::constructor;

_VkCmdReserveSpaceForCommandsInfoNVX::_VkCmdReserveSpaceForCommandsInfoNVX() {
  instance.sType = VK_STRUCTURE_TYPE_CMD_RESERVE_SPACE_FOR_COMMANDS_INFO_NVX;
  
}

_VkCmdReserveSpaceForCommandsInfoNVX::~_VkCmdReserveSpaceForCommandsInfoNVX() {
  //printf("VkCmdReserveSpaceForCommandsInfoNVX deconstructed!!\n");
  
  
  
  
  
}

void _VkCmdReserveSpaceForCommandsInfoNVX::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkCmdReserveSpaceForCommandsInfoNVX::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkCmdReserveSpaceForCommandsInfoNVX").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  SetPrototypeAccessor(proto, Nan::New("sType").ToLocalChecked(), GetsType, SetsType, ctor);
  SetPrototypeAccessor(proto, Nan::New("objectTable").ToLocalChecked(), GetobjectTable, SetobjectTable, ctor);
  SetPrototypeAccessor(proto, Nan::New("indirectCommandsLayout").ToLocalChecked(), GetindirectCommandsLayout, SetindirectCommandsLayout, ctor);
  SetPrototypeAccessor(proto, Nan::New("maxSequencesCount").ToLocalChecked(), GetmaxSequencesCount, SetmaxSequencesCount, ctor);
  Nan::Set(target, Nan::New("VkCmdReserveSpaceForCommandsInfoNVX").ToLocalChecked(), ctor->GetFunction());
}

bool _VkCmdReserveSpaceForCommandsInfoNVX::flush() {
  _VkCmdReserveSpaceForCommandsInfoNVX *self = this;
  
  return true;
}

NAN_METHOD(_VkCmdReserveSpaceForCommandsInfoNVX::New) {
  if (info.IsConstructCall()) {
    _VkCmdReserveSpaceForCommandsInfoNVX* self = new _VkCmdReserveSpaceForCommandsInfoNVX();
    self->Wrap(info.Holder());
    
    if (info[0]->IsObject()) {
      v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();
      v8::Local<v8::String> sAccess0 = Nan::New("sType").ToLocalChecked();
      v8::Local<v8::String> sAccess2 = Nan::New("objectTable").ToLocalChecked();
      v8::Local<v8::String> sAccess3 = Nan::New("indirectCommandsLayout").ToLocalChecked();
      v8::Local<v8::String> sAccess4 = Nan::New("maxSequencesCount").ToLocalChecked();
      if (obj->Has(sAccess0)) info.This()->Set(sAccess0, obj->Get(sAccess0));
      if (obj->Has(sAccess2)) info.This()->Set(sAccess2, obj->Get(sAccess2));
      if (obj->Has(sAccess3)) info.This()->Set(sAccess3, obj->Get(sAccess3));
      if (obj->Has(sAccess4)) info.This()->Set(sAccess4, obj->Get(sAccess4));
      
    }
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkCmdReserveSpaceForCommandsInfoNVX constructor cannot be invoked without 'new'");
  }
};

// sType
NAN_GETTER(_VkCmdReserveSpaceForCommandsInfoNVX::GetsType) {
  _VkCmdReserveSpaceForCommandsInfoNVX *self = Nan::ObjectWrap::Unwrap<_VkCmdReserveSpaceForCommandsInfoNVX>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.sType));
}NAN_SETTER(_VkCmdReserveSpaceForCommandsInfoNVX::SetsType) {
  _VkCmdReserveSpaceForCommandsInfoNVX *self = Nan::ObjectWrap::Unwrap<_VkCmdReserveSpaceForCommandsInfoNVX>(info.This());
  if (value->IsNumber()) {
    self->instance.sType = static_cast<VkStructureType>(Nan::To<int32_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkCmdReserveSpaceForCommandsInfoNVX.sType' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// objectTable
NAN_GETTER(_VkCmdReserveSpaceForCommandsInfoNVX::GetobjectTable) {
  _VkCmdReserveSpaceForCommandsInfoNVX *self = Nan::ObjectWrap::Unwrap<_VkCmdReserveSpaceForCommandsInfoNVX>(info.This());
  if (self->objectTable.IsEmpty()) {
    info.GetReturnValue().SetNull();
  } else {
    v8::Local<v8::Object> obj = Nan::New(self->objectTable);
    info.GetReturnValue().Set(obj);
  }
}NAN_SETTER(_VkCmdReserveSpaceForCommandsInfoNVX::SetobjectTable) {
  _VkCmdReserveSpaceForCommandsInfoNVX *self = Nan::ObjectWrap::Unwrap<_VkCmdReserveSpaceForCommandsInfoNVX>(info.This());
  // js
  if (!value->IsNull()) {
    v8::Local<v8::Object> obj = Nan::To<v8::Object>(value).ToLocalChecked();
    if (Nan::New(_VkObjectTableNVX::constructor)->HasInstance(obj)) {
      self->objectTable.Reset<v8::Object>(value.As<v8::Object>());
      _VkObjectTableNVX* inst = Nan::ObjectWrap::Unwrap<_VkObjectTableNVX>(obj);
      ;
      self->instance.objectTable = inst->instance;
    } else {
      
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected '[object VkObjectTableNVX]' for 'VkCmdReserveSpaceForCommandsInfoNVX.objectTable' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
      return;
    }
  } else if (value->IsNull()) {
    self->objectTable.Reset();
    self->instance.objectTable = VK_NULL_HANDLE;
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected '[object VkObjectTableNVX]' for 'VkCmdReserveSpaceForCommandsInfoNVX.objectTable' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// indirectCommandsLayout
NAN_GETTER(_VkCmdReserveSpaceForCommandsInfoNVX::GetindirectCommandsLayout) {
  _VkCmdReserveSpaceForCommandsInfoNVX *self = Nan::ObjectWrap::Unwrap<_VkCmdReserveSpaceForCommandsInfoNVX>(info.This());
  if (self->indirectCommandsLayout.IsEmpty()) {
    info.GetReturnValue().SetNull();
  } else {
    v8::Local<v8::Object> obj = Nan::New(self->indirectCommandsLayout);
    info.GetReturnValue().Set(obj);
  }
}NAN_SETTER(_VkCmdReserveSpaceForCommandsInfoNVX::SetindirectCommandsLayout) {
  _VkCmdReserveSpaceForCommandsInfoNVX *self = Nan::ObjectWrap::Unwrap<_VkCmdReserveSpaceForCommandsInfoNVX>(info.This());
  // js
  if (!value->IsNull()) {
    v8::Local<v8::Object> obj = Nan::To<v8::Object>(value).ToLocalChecked();
    if (Nan::New(_VkIndirectCommandsLayoutNVX::constructor)->HasInstance(obj)) {
      self->indirectCommandsLayout.Reset<v8::Object>(value.As<v8::Object>());
      _VkIndirectCommandsLayoutNVX* inst = Nan::ObjectWrap::Unwrap<_VkIndirectCommandsLayoutNVX>(obj);
      ;
      self->instance.indirectCommandsLayout = inst->instance;
    } else {
      
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected '[object VkIndirectCommandsLayoutNVX]' for 'VkCmdReserveSpaceForCommandsInfoNVX.indirectCommandsLayout' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
      return;
    }
  } else if (value->IsNull()) {
    self->indirectCommandsLayout.Reset();
    self->instance.indirectCommandsLayout = VK_NULL_HANDLE;
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected '[object VkIndirectCommandsLayoutNVX]' for 'VkCmdReserveSpaceForCommandsInfoNVX.indirectCommandsLayout' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// maxSequencesCount
NAN_GETTER(_VkCmdReserveSpaceForCommandsInfoNVX::GetmaxSequencesCount) {
  _VkCmdReserveSpaceForCommandsInfoNVX *self = Nan::ObjectWrap::Unwrap<_VkCmdReserveSpaceForCommandsInfoNVX>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.maxSequencesCount));
}NAN_SETTER(_VkCmdReserveSpaceForCommandsInfoNVX::SetmaxSequencesCount) {
  _VkCmdReserveSpaceForCommandsInfoNVX *self = Nan::ObjectWrap::Unwrap<_VkCmdReserveSpaceForCommandsInfoNVX>(info.This());
  if (value->IsNumber()) {
    self->instance.maxSequencesCount = static_cast<uint32_t>(Nan::To<int64_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkCmdReserveSpaceForCommandsInfoNVX.maxSequencesCount' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}