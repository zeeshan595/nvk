/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.4
 */
#include "utils.h"
#include "index.h"
#include "VkGeometryTrianglesNVX.h"

Nan::Persistent<v8::FunctionTemplate> _VkGeometryTrianglesNVX::constructor;

_VkGeometryTrianglesNVX::_VkGeometryTrianglesNVX() {
  instance.sType = VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NVX;
  
}

_VkGeometryTrianglesNVX::~_VkGeometryTrianglesNVX() {
  //printf("VkGeometryTrianglesNVX deconstructed!!\n");
  
  
  
  
  
  
  
  
  
  
  
  
  
}

void _VkGeometryTrianglesNVX::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(_VkGeometryTrianglesNVX::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VkGeometryTrianglesNVX").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();
  
  SetPrototypeAccessor(proto, Nan::New("sType").ToLocalChecked(), GetsType, SetsType, ctor);
  SetPrototypeAccessor(proto, Nan::New("vertexData").ToLocalChecked(), GetvertexData, SetvertexData, ctor);
  SetPrototypeAccessor(proto, Nan::New("vertexOffset").ToLocalChecked(), GetvertexOffset, SetvertexOffset, ctor);
  SetPrototypeAccessor(proto, Nan::New("vertexCount").ToLocalChecked(), GetvertexCount, SetvertexCount, ctor);
  SetPrototypeAccessor(proto, Nan::New("vertexStride").ToLocalChecked(), GetvertexStride, SetvertexStride, ctor);
  SetPrototypeAccessor(proto, Nan::New("vertexFormat").ToLocalChecked(), GetvertexFormat, SetvertexFormat, ctor);
  SetPrototypeAccessor(proto, Nan::New("indexData").ToLocalChecked(), GetindexData, SetindexData, ctor);
  SetPrototypeAccessor(proto, Nan::New("indexOffset").ToLocalChecked(), GetindexOffset, SetindexOffset, ctor);
  SetPrototypeAccessor(proto, Nan::New("indexCount").ToLocalChecked(), GetindexCount, SetindexCount, ctor);
  SetPrototypeAccessor(proto, Nan::New("indexType").ToLocalChecked(), GetindexType, SetindexType, ctor);
  SetPrototypeAccessor(proto, Nan::New("transformData").ToLocalChecked(), GettransformData, SettransformData, ctor);
  SetPrototypeAccessor(proto, Nan::New("transformOffset").ToLocalChecked(), GettransformOffset, SettransformOffset, ctor);
  Nan::Set(target, Nan::New("VkGeometryTrianglesNVX").ToLocalChecked(), ctor->GetFunction());
}

bool _VkGeometryTrianglesNVX::flush() {
  _VkGeometryTrianglesNVX *self = this;
  
  return true;
}

NAN_METHOD(_VkGeometryTrianglesNVX::New) {
  if (info.IsConstructCall()) {
    _VkGeometryTrianglesNVX* self = new _VkGeometryTrianglesNVX();
    self->Wrap(info.Holder());
    
    if (info[0]->IsObject()) {
      v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();
      v8::Local<v8::String> sAccess0 = Nan::New("sType").ToLocalChecked();
      v8::Local<v8::String> sAccess2 = Nan::New("vertexData").ToLocalChecked();
      v8::Local<v8::String> sAccess3 = Nan::New("vertexOffset").ToLocalChecked();
      v8::Local<v8::String> sAccess4 = Nan::New("vertexCount").ToLocalChecked();
      v8::Local<v8::String> sAccess5 = Nan::New("vertexStride").ToLocalChecked();
      v8::Local<v8::String> sAccess6 = Nan::New("vertexFormat").ToLocalChecked();
      v8::Local<v8::String> sAccess7 = Nan::New("indexData").ToLocalChecked();
      v8::Local<v8::String> sAccess8 = Nan::New("indexOffset").ToLocalChecked();
      v8::Local<v8::String> sAccess9 = Nan::New("indexCount").ToLocalChecked();
      v8::Local<v8::String> sAccess10 = Nan::New("indexType").ToLocalChecked();
      v8::Local<v8::String> sAccess11 = Nan::New("transformData").ToLocalChecked();
      v8::Local<v8::String> sAccess12 = Nan::New("transformOffset").ToLocalChecked();
      if (obj->Has(sAccess0)) info.This()->Set(sAccess0, obj->Get(sAccess0));
      if (obj->Has(sAccess2)) info.This()->Set(sAccess2, obj->Get(sAccess2));
      if (obj->Has(sAccess3)) info.This()->Set(sAccess3, obj->Get(sAccess3));
      if (obj->Has(sAccess4)) info.This()->Set(sAccess4, obj->Get(sAccess4));
      if (obj->Has(sAccess5)) info.This()->Set(sAccess5, obj->Get(sAccess5));
      if (obj->Has(sAccess6)) info.This()->Set(sAccess6, obj->Get(sAccess6));
      if (obj->Has(sAccess7)) info.This()->Set(sAccess7, obj->Get(sAccess7));
      if (obj->Has(sAccess8)) info.This()->Set(sAccess8, obj->Get(sAccess8));
      if (obj->Has(sAccess9)) info.This()->Set(sAccess9, obj->Get(sAccess9));
      if (obj->Has(sAccess10)) info.This()->Set(sAccess10, obj->Get(sAccess10));
      if (obj->Has(sAccess11)) info.This()->Set(sAccess11, obj->Get(sAccess11));
      if (obj->Has(sAccess12)) info.This()->Set(sAccess12, obj->Get(sAccess12));
      
    }
    
    info.GetReturnValue().Set(info.Holder());
  } else {
    Nan::ThrowError("VkGeometryTrianglesNVX constructor cannot be invoked without 'new'");
  }
};

// sType
NAN_GETTER(_VkGeometryTrianglesNVX::GetsType) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.sType));
}NAN_SETTER(_VkGeometryTrianglesNVX::SetsType) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  if (value->IsNumber()) {
    self->instance.sType = static_cast<VkStructureType>(Nan::To<int32_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkGeometryTrianglesNVX.sType' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// vertexData
NAN_GETTER(_VkGeometryTrianglesNVX::GetvertexData) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  if (self->vertexData.IsEmpty()) {
    info.GetReturnValue().SetNull();
  } else {
    v8::Local<v8::Object> obj = Nan::New(self->vertexData);
    info.GetReturnValue().Set(obj);
  }
}NAN_SETTER(_VkGeometryTrianglesNVX::SetvertexData) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  // js
  if (!value->IsNull()) {
    v8::Local<v8::Object> obj = Nan::To<v8::Object>(value).ToLocalChecked();
    if (Nan::New(_VkBuffer::constructor)->HasInstance(obj)) {
      self->vertexData.Reset<v8::Object>(value.As<v8::Object>());
      _VkBuffer* inst = Nan::ObjectWrap::Unwrap<_VkBuffer>(obj);
      ;
      self->instance.vertexData = inst->instance;
    } else {
      
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected '[object VkBuffer]' for 'VkGeometryTrianglesNVX.vertexData' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
      return;
    }
  } else if (value->IsNull()) {
    self->vertexData.Reset();
    self->instance.vertexData = VK_NULL_HANDLE;
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected '[object VkBuffer]' for 'VkGeometryTrianglesNVX.vertexData' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// vertexOffset
NAN_GETTER(_VkGeometryTrianglesNVX::GetvertexOffset) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.vertexOffset));
}NAN_SETTER(_VkGeometryTrianglesNVX::SetvertexOffset) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  if (value->IsNumber()) {
    self->instance.vertexOffset = static_cast<uint64_t>(Nan::To<int64_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkGeometryTrianglesNVX.vertexOffset' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// vertexCount
NAN_GETTER(_VkGeometryTrianglesNVX::GetvertexCount) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.vertexCount));
}NAN_SETTER(_VkGeometryTrianglesNVX::SetvertexCount) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  if (value->IsNumber()) {
    self->instance.vertexCount = static_cast<uint32_t>(Nan::To<int64_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkGeometryTrianglesNVX.vertexCount' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// vertexStride
NAN_GETTER(_VkGeometryTrianglesNVX::GetvertexStride) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.vertexStride));
}NAN_SETTER(_VkGeometryTrianglesNVX::SetvertexStride) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  if (value->IsNumber()) {
    self->instance.vertexStride = static_cast<uint64_t>(Nan::To<int64_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkGeometryTrianglesNVX.vertexStride' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// vertexFormat
NAN_GETTER(_VkGeometryTrianglesNVX::GetvertexFormat) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.vertexFormat));
}NAN_SETTER(_VkGeometryTrianglesNVX::SetvertexFormat) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  if (value->IsNumber()) {
    self->instance.vertexFormat = static_cast<VkFormat>(Nan::To<int32_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkGeometryTrianglesNVX.vertexFormat' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// indexData
NAN_GETTER(_VkGeometryTrianglesNVX::GetindexData) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  if (self->indexData.IsEmpty()) {
    info.GetReturnValue().SetNull();
  } else {
    v8::Local<v8::Object> obj = Nan::New(self->indexData);
    info.GetReturnValue().Set(obj);
  }
}NAN_SETTER(_VkGeometryTrianglesNVX::SetindexData) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  // js
  if (!value->IsNull()) {
    v8::Local<v8::Object> obj = Nan::To<v8::Object>(value).ToLocalChecked();
    if (Nan::New(_VkBuffer::constructor)->HasInstance(obj)) {
      self->indexData.Reset<v8::Object>(value.As<v8::Object>());
      _VkBuffer* inst = Nan::ObjectWrap::Unwrap<_VkBuffer>(obj);
      ;
      self->instance.indexData = inst->instance;
    } else {
      
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected '[object VkBuffer]' for 'VkGeometryTrianglesNVX.indexData' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
      return;
    }
  } else if (value->IsNull()) {
    self->indexData.Reset();
    self->instance.indexData = VK_NULL_HANDLE;
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected '[object VkBuffer]' for 'VkGeometryTrianglesNVX.indexData' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// indexOffset
NAN_GETTER(_VkGeometryTrianglesNVX::GetindexOffset) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.indexOffset));
}NAN_SETTER(_VkGeometryTrianglesNVX::SetindexOffset) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  if (value->IsNumber()) {
    self->instance.indexOffset = static_cast<uint64_t>(Nan::To<int64_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkGeometryTrianglesNVX.indexOffset' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// indexCount
NAN_GETTER(_VkGeometryTrianglesNVX::GetindexCount) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.indexCount));
}NAN_SETTER(_VkGeometryTrianglesNVX::SetindexCount) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  if (value->IsNumber()) {
    self->instance.indexCount = static_cast<uint32_t>(Nan::To<int64_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkGeometryTrianglesNVX.indexCount' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// indexType
NAN_GETTER(_VkGeometryTrianglesNVX::GetindexType) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.indexType));
}NAN_SETTER(_VkGeometryTrianglesNVX::SetindexType) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  if (value->IsNumber()) {
    self->instance.indexType = static_cast<VkIndexType>(Nan::To<int32_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkGeometryTrianglesNVX.indexType' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// transformData
NAN_GETTER(_VkGeometryTrianglesNVX::GettransformData) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  if (self->transformData.IsEmpty()) {
    info.GetReturnValue().SetNull();
  } else {
    v8::Local<v8::Object> obj = Nan::New(self->transformData);
    info.GetReturnValue().Set(obj);
  }
}NAN_SETTER(_VkGeometryTrianglesNVX::SettransformData) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  // js
  if (!value->IsNull()) {
    v8::Local<v8::Object> obj = Nan::To<v8::Object>(value).ToLocalChecked();
    if (Nan::New(_VkBuffer::constructor)->HasInstance(obj)) {
      self->transformData.Reset<v8::Object>(value.As<v8::Object>());
      _VkBuffer* inst = Nan::ObjectWrap::Unwrap<_VkBuffer>(obj);
      ;
      self->instance.transformData = inst->instance;
    } else {
      
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected '[object VkBuffer]' for 'VkGeometryTrianglesNVX.transformData' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
      return;
    }
  } else if (value->IsNull()) {
    self->transformData.Reset();
    self->instance.transformData = VK_NULL_HANDLE;
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected '[object VkBuffer]' for 'VkGeometryTrianglesNVX.transformData' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}// transformOffset
NAN_GETTER(_VkGeometryTrianglesNVX::GettransformOffset) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->instance.transformOffset));
}NAN_SETTER(_VkGeometryTrianglesNVX::SettransformOffset) {
  _VkGeometryTrianglesNVX *self = Nan::ObjectWrap::Unwrap<_VkGeometryTrianglesNVX>(info.This());
  if (value->IsNumber()) {
    self->instance.transformOffset = static_cast<uint64_t>(Nan::To<int64_t>(value).FromMaybe(0));
  } else {
    
    std::string details = getV8ObjectDetails(value);
    if (details[0] == '#') details = "[object " + (details.substr(2, details.length() - 2 - 1)) + "]";
    std::string msg = "Expected 'Number' for 'VkGeometryTrianglesNVX.transformOffset' but got '" + details + "'";
    Nan::ThrowTypeError(msg.c_str());
    return;
  }
}