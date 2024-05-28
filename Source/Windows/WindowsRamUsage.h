//
// Created by Noah Thompson on 5/27/2024.
//

#pragma once
#ifdef _WIN32
#include <windows.h>
#endif
#include "../IRamUsage.h"

namespace nthompson {
    class WindowsRamUsage : public IRamUsage {
    public:
        WindowsRamUsage();
        uint32_t GetRamUsage() override;
        ~WindowsRamUsage() override;
    private:
#ifdef _WIN32
        MEMORYSTATUSEX state {};
#endif
    };

}