#ifndef _MODULE_H_
#define _MODULE_H_

#include <libcpp/libcpp.h>

namespace foxintango {
class foxintangoAPI Module {
public:
    typedef enum _MODULE_STATUS
    {
        MS_OK
    } MODULE_STATUS;
public:
    Module();
   ~Module();
   MODULE_STATUS load(const char* path);
};
}
#endif
