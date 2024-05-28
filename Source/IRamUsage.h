//
// Created by Noah Thompson on 5/27/2024.
//

#pragma once
#include <cstdint>

class IRamUsage {
public:
    IRamUsage() = default;
    virtual uint32_t GetRamUsage() = 0;
    virtual ~IRamUsage() = default;
};
