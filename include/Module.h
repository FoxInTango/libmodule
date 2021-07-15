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
        MS_INTERFACE_MISSED = -2,
        MS_LOAD_FAILED = -1,
        MS_BAD_PATH = 0,
        MS_OK
    } MODULE_STATUS;
public:
    Module();
    Module(const char* path);
   ~Module();
public:
   MODULE_STATUS status();
   ModuleInterface* interface();
};
}
#endif
