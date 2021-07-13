#ifndef _LIB_MODULE_H_
#define _LIB_MODULE_H_

#include "Module.h"
#include <libcpp/libcpp.h>

namespace foxintango {
typedef Module* (*EXPORT_MODULE_INSTANCE)(const char* module_path);
}
#endif
