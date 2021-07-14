#include <libmodule/libmodule.h>
using namespace foxintango;
#include <iostream>

int main(int argc,char** argv) {
    Module* module = new Module("/usr/local/lib/IOEngineLWS.so");

    ModuleInterface* interface = module->interface();
    if(interface) {
        std::cout << "Module - IOEngineLWS loaded." << std::endl;

        if(interface->containClass((unsigned char*)"IOEngineLWS")){
            std::cout << "IOEngineLWS Exists." << std::endl;
        } else {
            std::cout << "IOEngineLWS NOT Exists." << std::endl;
        }
    }
    return 0;
}
