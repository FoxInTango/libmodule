/*
 * libmodule
 *
 * Copyright (C) 2021 FoxInTango <foxintango@yeah.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
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
        /** 错误排查
         *  ldd -r [path]
         *  nm -A [path]
         *  NOTE : 模块依赖项需与模块进行链接
         * */
        std::cout << "libModule : " << "module - " << path << " loaded." << std::endl;

        interface = (ModuleInterface*)dlsym(dlHandle,MODULE_INTERFACE_STRING);

        if(interface) {
            std::cout << "libModule : module interface loaded." << std::endl;
            return Module::MS_OK;
        } else {
            std::cout << "libModule : module interface load filed -- ERROR: " << dlerror() << std::endl;
            return Module::MS_INTERFACE_MISSED;
        }
    } else {
        std::cout << "libModule : module load failed -- ERROR: " << dlerror() << std::endl;
        return Module::MS_LOAD_FAILED;
    }
}

ModuleIMPL::~ModuleIMPL(){
    if(dlHandle) {
        dlclose(dlHandle);
    }
}
#elif defined(__APPLE__) || defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR) || defined(TARGET_OS_MAC)
Module::MODULE_STATUS ModuleIMPL::load(const char* path) {
    dlHandle = dlopen(path,RTLD_LAZY | RTLD_GLOBAL);
    if(dlHandle) {
        /** 错误排查
         *  ldd -r [path]
         *  nm -A [path]
         * */
        std::cout << "Module Loaded." << std::endl;
        interface = (ModuleInterface*)dlsym(dlHandle,"MODULE_INTERFACE_INSTANCE");

        if(interface) {
            std::cout << "ModuleInterface Loaded." << std::endl;
            return Module::MS_OK;
        } else {
            std::cout << "ModuleInterface Load Filed -- ERROR: " << dlerror() << std::endl;
            return Module::MS_INTERFACE_MISSED;
        }
    } else {
        std::cout << "Module Load Failed -- ERROR: " << dlerror() << std::endl;
        return Module::MS_LOAD_FAILED;
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
