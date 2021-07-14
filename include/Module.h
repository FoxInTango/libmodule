#ifndef _MODULE_H_
#define _MODULE_H_

#include "ModuleInterface.h"
#include <libcpp/libcpp.h>

namespace foxintango {
class ModuleIMPL;
class foxintangoAPI Module {
public:
    ModuleIMPL* impl;
public:
    typedef enum _MODULE_STATUS
    {
        MS_OK
    } MODULE_STATUS;
public:
    Module();
    Module(const char* path);
   ~Module();
public:
   MODULE_STATUS status();
   MODULE_STATUS load(const char* path);
   ModuleInterface* interface();
};
}
#endif
