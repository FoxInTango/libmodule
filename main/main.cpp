#include <libmodule/libmodule.h>
using namespace foxintango;
#include <iostream>
#include <string>
/** module
 *      -c module.json [-p path]
 *      -l pathA pathB pathC
 * */

int main(int argc,char** argv) {

    Module* module = new Module("/usr/local/lib/IOEngineLWS.dylib");

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
