#ifndef _MODULE_INTERFACE_H_
#define _MODULE_INTERFACE_H_

#include <libmodel/libmodel.h>
#include <libcpp/libcpp.h>

namespace foxintango {
class foxintangoAPI ModuleInterface {
public:
    ModuleInterface();
    virtual ~ModuleInterface();
public:
    virtual bool  containClass(const unsigned char* name) = 0;
    virtual void* createObject(const unsigned char* name) = 0;
    virtual void* createObject(const unsigned char* name,const Model& model) = 0;

    virtual bool  containFunction(const unsigned char* name) = 0;
    virtual void* exportFunction(const unsigned char* name) = 0;
    
    virtual void* exportVariable(const unsigned char* name) = 0;
};
}
#endif
