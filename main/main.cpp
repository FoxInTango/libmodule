#include <libmodule/libmodule.h>
using namespace foxintango;

int main(int argc,char** argv) {
    Module* module = new Module("IOEngineLWS.so");

    ModuleInterface* interface = module->interface();
    return 0;
}
