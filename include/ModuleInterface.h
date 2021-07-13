#ifndef _MODULE_INTERFACE_H_
#define _MODULE_INTERFACE_H_

#include <libcpp/libcpp.h>

namespace foxintango {
class Model;
class foxintangoAPI ModuleInterface {
public:
    ModuleInterface();
    virtual ~ModuleInterface();
public:
    virtual bool  containClass(const unsigned char* name) = 0;
    virtual void* createObject(const unsigned char* name) = 0;
    virtual bool  containFunction(const unsigned char* name) = 0;
    virtual void* exportFunction(const unsigned char* name) = 0;
};
}
#endif
