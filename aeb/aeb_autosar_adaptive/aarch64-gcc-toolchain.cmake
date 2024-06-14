# arm-gcc-toolchain.cmake
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)

set(BOOST_ROOT "/lib/aarch64-linux-gnu")
set(BOOST_INCLUDEDIR "/lib/aarch64-linux-gnu/include")
set(BOOST_LIBRARYDIR "/lib/aarch64-linux-gnu/lib")