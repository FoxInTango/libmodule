#include "../include/Module.h"
using namespace foxintango;

Module::load(const char* path) 

/** Platform
 * */
#if defined(WIN32) || defined(_WIN32) || defined(_WIN32_) || defined(WIN64) || defined(_WIN64) || defined(_WIN64_)
MODULE_STATUS Module::load(const char* path) {

}
#elif defined(ANDROID) || defined(_ANDROID_)
#elif defined(__linux__)
#elif defined(__APPLE__) || defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR) || defined(TARGET_OS_MAC)
#else
    #define foxintangoAPI
#endif
