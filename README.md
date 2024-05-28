![GPU Utilization Icon](Source/com.nthompson.ram.sdPlugin/defaultImage.png)


# Stream Deck RAM Utilization Plugin 🧠

A plugin for monitoring the utilization of your RAM sticks on the Elgato Stream Deck. Windows only for now, Mac support coming soon!

# Dependencies

* Stream Deck C++ SDK (must use C++ 20 or above)

# Installation

Download the latest sdPlugin file from the Releases link on GitHub, and double-click it to install.

# Building

## Windows

_I used CLion with CMake 3.26, but you are welcome to use Visual Studio 2022 if required._

Clone the repo as follows:

`
git clone https://github.com/thompsonnoahe/StreamDeckMem
`

Make sure you have the C++ Development workload installed from the VS Installer. No extra dependencies are required (other than CMake of course!)