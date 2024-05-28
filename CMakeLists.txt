cmake_minimum_required(VERSION 3.26)

project(com.nthompson.ram VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

include("Source/ThirdParty/StreamDeckSDK.cmake")

add_executable(mem main.cpp
        Source/Windows/WindowsRamUsage.cpp
        Source/Windows/WindowsRamUsage.h
        Source/IRamUsage.h
        Source/MemPlugin.cpp
        Source/MemPlugin.h)

target_link_libraries(mem StreamDeckSDK)
