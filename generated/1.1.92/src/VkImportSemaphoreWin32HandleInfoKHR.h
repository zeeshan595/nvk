/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY nvk v0.1.5
 */
#ifndef __VK_VKIMPORTSEMAPHOREWIN32HANDLEINFOKHR_H__
#define __VK_VKIMPORTSEMAPHOREWIN32HANDLEINFOKHR_H__

#include <nan.h>

#include <vulkan/vulkan_win32.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class _VkImportSemaphoreWin32HandleInfoKHR: public Nan::ObjectWrap {

  public:
    // #methods
    static NAN_METHOD(New);
    // #accessors
    static NAN_GETTER(GetsType);
    static NAN_SETTER(SetsType);
    
      Nan::Persistent<v8::Object, v8::CopyablePersistentTraits<v8::Object>> semaphore;
      static NAN_GETTER(Getsemaphore);
    static NAN_SETTER(Setsemaphore);
    
    static NAN_GETTER(Getflags);
    static NAN_SETTER(Setflags);
    
    static NAN_GETTER(GethandleType);
    static NAN_SETTER(SethandleType);
    

    // real instance
    VkImportSemaphoreWin32HandleInfoKHR instance = {};

    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static void Initialize(v8::Local<v8::Object> exports);
    bool flush(void);

  private:

    _VkImportSemaphoreWin32HandleInfoKHR();
    ~_VkImportSemaphoreWin32HandleInfoKHR();

};

#endif