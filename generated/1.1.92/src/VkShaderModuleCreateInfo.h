/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.5
 */
#ifndef __VK_VKSHADERMODULECREATEINFO_H__
#define __VK_VKSHADERMODULECREATEINFO_H__

#include <nan.h>

#include <vulkan/vulkan_win32.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class _VkShaderModuleCreateInfo: public Nan::ObjectWrap {

  public:
    // #methods
    static NAN_METHOD(New);
    // #accessors
    static NAN_GETTER(GetsType);
    static NAN_SETTER(SetsType);
    
    static NAN_GETTER(Getflags);
    static NAN_SETTER(Setflags);
    
    static NAN_GETTER(GetcodeSize);
    static NAN_SETTER(SetcodeSize);
    
    Nan::Persistent<v8::Array, v8::CopyablePersistentTraits<v8::Array>> pCode;
    static NAN_GETTER(GetpCode);
    static NAN_SETTER(SetpCode);
    

    // real instance
    VkShaderModuleCreateInfo instance = {};

    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static void Initialize(v8::Local<v8::Object> exports);
    bool flush(void);

  private:

    _VkShaderModuleCreateInfo();
    ~_VkShaderModuleCreateInfo();

};

#endif