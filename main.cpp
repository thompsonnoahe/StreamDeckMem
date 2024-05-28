#include <iostream>
#include <StreamDeckSDK/ESDMain.h>
#include "Source/MemPlugin.h"

int main(int argc, const char** argv) {
    return esd_main(argc, argv, new nthompson::MemPlugin());
}
