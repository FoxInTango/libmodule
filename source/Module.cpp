#include "../include/Module.h"
using namespace foxintango;
#include <string.h>
#include <dlfcn.h>
#include <iostream>

#define MODULE_INTERFACE_STRING "MODULE_INTERFACE_INSTANCE"

namespace foxintango {
class ModuleIMPL {
public:
    void* dlHandle;
    ModuleInterface* interface;
public:
    ModuleIMPL() {
        dlHandle  = 0;
        interface = 0;
    }
   ~ModuleIMPL();
public:
    Module::MODULE_STATUS load(const char* path);
};
}

/** Platform
 * */
#if defined(WIN32) || defined(_WIN32) || defined(_WIN32_) || defined(WIN64) || defined(_WIN64) || defined(_WIN64_)
Module::MODULE_STATUS ModuleIMPL::load(const char* path) {
    dlHandle = LoadLibrary(path);
    if(dlHandle) {
        interface = (ModuleInterface*)GetProcAddress(dlHandle,MODULE_INTERFACE_STRING);
    }
}

ModuleIMPL::~ModuleIMPL(){
    if(dlHandle) {
        FreeLibrary(dlHandle);
    }
}

#elif defined(ANDROID) || defined(_ANDROID_)
#elif defined(__linux__)
Module::MODULE_STATUS ModuleIMPL::load(const char* path) {
    dlHandle = dlopen(path,RTLD_LAZY);
    if(dlHandle) {
        std::cout << "Module Loaded." << std::endl;
        interface = (ModuleInterface*)dlsym(dlHandle,MODULE_INTERFACE_STRING);

        if(interface) {
            std::cout << "ModuleInterface Loaded." << std::endl; 
        } else {
            std::cout << "ModuleInterface Load Filed." << std::endl;
        }
    } else {
        std::cout << "Module Load Failed." << std::endl;
    }
}

ModuleIMPL::~ModuleIMPL(){
    if(dlHandle) {
        dlclose(dlHandle);
    }
}
#elif defined(__APPLE__) || defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR) || defined(TARGET_OS_MAC)
Module::MODULE_STATUS ModuleIMPL::load(const char* path) {
    dlHandle = dlopen(path,RTLD_LAZY);
    if(dlHandle) {
        interface = (ModuleInterface*)dlsym(dlHandle,MODULE_INTERFACE_STRING);
    }
}

ModuleIMPL::~ModuleIMPL(){
    if(dlHandle) {
        dlclose(dlHandle);
    }
}
#else
Module::MODULE_STATUS ModuleIMPL::load(const char* path) {
    dlHandle = dlopen(path,RTLD_LAZY);
    if(dlHandle) {
        interface = (ModuleInterface*)dlsym(dlHandle,MODULE_INTERFACE_STRING);
    }
}

ModuleIMPL::~ModuleIMPL(){
    if(dlHandle) {
        dlclose(dlHandle);
    }
}
#endif

Module::Module() {
    this->impl = new ModuleIMPL();
}

Module::Module(const char* path) {
    this->impl = new ModuleIMPL();

    if(this->impl && path && strlen(path)) {
        this->impl->load(path);
    }
}

Module::~Module() {
    if(this->impl) delete this->impl;
}

ModuleInterface* Module::interface() {
    if(this->impl) return this->impl->interface;

    return 0;
}
