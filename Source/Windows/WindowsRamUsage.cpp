//
// Created by Noah Thompson on 5/27/2024.
//

#include "WindowsRamUsage.h"



namespace nthompson {
    WindowsRamUsage::WindowsRamUsage() {
#ifdef _WIN32
        state.dwLength = sizeof(state);
#endif
    }

    uint32_t WindowsRamUsage::GetRamUsage() {
#ifdef _WIN32
        GlobalMemoryStatusEx(&state);
        return state.dwMemoryLoad;
#endif
        return 0;
    }

    WindowsRamUsage::~WindowsRamUsage() = default;
}
