#include <libmodule/libmodule.h>
using namespace foxintango;
#include <iostream>

int main(int argc,char** argv) {
    Module* module = new Module("IOEngineLWS.so");

    ModuleInterface* interface = module->interface();
    if(interface) {
        std::cout << "module IOEngineLWS loaded " << std::endl;
    }
    return 0;
}
