###########################################################################
# CMakeLists.txt generated for component control
# Product type: executable
###########################################################################
cmake_minimum_required(VERSION 3.12)
project(control)

# Propagate the CMAKE_EXPORT_COMPILE_COMMANDS variable from the 
# environment if it is defined as an environment variable, but not as a 
# CMake variable. This is to work around a bug in CMake 3.19 when the 
# "NMake Makefiles" generator is selected.
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


# Set directory properties.
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT control)

###########################################################################
## Path variables
###########################################################################
# Derive an absolute path to the code generation anchor folder.
get_filename_component(START_DIR .. ABSOLUTE)

# Special directories defined by using CACHE variables can be overridden 
# by setting the variable from the command line, e.g.,
# 
# 	cmake . -DMATLAB_ROOT=/path/to/another/matlab/root
set(MATLAB_ROOT /usr/local/MATLAB/R2024a CACHE PATH "")

# Additional variables that are defined conditionally.
if("${CMAKE_CURRENT_BINARY_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
    set(BINARY_START_DIR "${START_DIR}")
else()
    set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
endif()
if(APPLE)
    if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL x86_64)
        list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/bin/maci64)
    elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL arm64)
        list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/bin/maca64)
    endif()
elseif(UNIX AND ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL x86_64) AND ("${CMAKE_SYSTEM_NAME}" STREQUAL Linux))
    list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/bin/glnxa64)
elseif(WIN32 AND ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL AMD64))
    if(MSVC)
        list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/extern/lib/win64/microsoft)
    elseif(MINGW)
        list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/extern/lib/win64/mingw64)
    endif()
    list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/bin/win64
        ${MATLAB_ROOT}/lib/win64)
endif()


if(DEFINED MATLAB_ROOT_SYSLIB_PATHS)
    list(APPEND CMAKE_LIBRARY_PATH ${MATLAB_ROOT_SYSLIB_PATHS})
    link_directories(${MATLAB_ROOT_SYSLIB_PATHS})
endif()
if(DEFINED MATLAB_ROOT_SYSINCLUDE_PATHS)
    list(APPEND CMAKE_INCLUDE_PATH ${MATLAB_ROOT_SYSINCLUDE_PATHS})
endif()



###########################################################################
## Required packages
###########################################################################
find_package(Threads REQUIRED)
find_package(Boost 1.55 COMPONENTS system thread log REQUIRED)
# find_package(vsomeip3 REQUIRED)
# find_package(vsomeip3 REQUIRED PATHS /home/seame-workstation09/vsomeip_aarch64/vsomeip/build NO_DEFAULT_PATH)
find_package(vsomeip3 REQUIRED)

###########################################################################
## System Libraries
###########################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES} ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

###########################################################################
## Target definition and commands
###########################################################################

file(GLOB ARA_COM_SOURCES "${CMAKE_SOURCE_DIR}/ara/com/*.cpp")
file(GLOB ARA_COM_VSOMEIP_SOURCES "${CMAKE_SOURCE_DIR}/ara/com/vsomeip/*.cpp")
file(GLOB ARA_CORE_SOURCES "${CMAKE_SOURCE_DIR}/ara/core/*.cpp")
# file(GLOB ARA_DIAG_SOURCES "${CMAKE_SOURCE_DIR}/ara/diag/*.cpp")
# file(GLOB ARA_EXEC_SOURCES "${CMAKE_SOURCE_DIR}/ara/exec/*.cpp")
file(GLOB ARA_LOG_SOURCES "${CMAKE_SOURCE_DIR}/ara/log/*.cpp")

# Definition of target "control".
add_executable(control  /home/seame-workstation09/Documents/MATLAB/SupportPackages/R2024a/toolbox/target/supportpackages/shared_linuxservices/src/TCPSendReceive/MW_TCPSendReceive.c
    ${START_DIR}/control_autosar_adaptive/control.cpp
    ${START_DIR}/control_autosar_adaptive/main.cpp
    ${ARA_COM_SOURCES}
    ${ARA_COM_VSOMEIP_SOURCES}
    ${ARA_CORE_SOURCES}
    # ${ARA_DIAG_SOURCES}
    # ${ARA_EXEC_SOURCES}
    ${ARA_LOG_SOURCES})

# Set properties for target "control".
set_target_properties(control PROPERTIES PREFIX ""
    POSITION_INDEPENDENT_CODE ON
    RUNTIME_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    LIBRARY_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    ARCHIVE_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>")

# Specify language features required for target "control".
target_compile_features(control PUBLIC cxx_std_11)

# Specify compiler preprocessor definitions for target "control".
target_compile_definitions(control PRIVATE -DMODEL=control
    -DNUMST=1
    -DNCSTATES=0
    -DHAVESTDIO
    -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=0
    -DTERMFCN=1
    -DONESTEPFCN=1
    -DMAT_FILE=0
    -DMULTI_INSTANCE_CODE=1
    -DINTEGER_CODE=0
    -DMT=0)

# Specify compiler flags for target "control".
target_compile_options(control PRIVATE -std=c++11
    $<$<NOT:$<BOOL:${CMAKE_BUILD_TYPE}>>:-O3 -DNDEBUG>)

# Specify include directories for target "control".
target_include_directories(control PRIVATE ${START_DIR}
    /home/seame-workstation09/Documents/MATLAB/SupportPackages/R2024a/toolbox/target/supportpackages/shared_linuxservices/include
    ${START_DIR}/control_autosar_adaptive
    ${MATLAB_ROOT}/toolbox/coder/simulinkcoder/src/executor
    ${START_DIR}/control_autosar_adaptive/stub/aragen
    ${MATLAB_ROOT}/sys/FastDDS/glnxa64/include
    ${MATLAB_ROOT}/extern/include
    ${MATLAB_ROOT}/simulink/include
    ${MATLAB_ROOT}/rtw/c/src
    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common
    ${MATLAB_ROOT}/rtw/c/ert
    ${START_DIR}/slprj/autosar_adaptive/_sharedutils
    ${Boost_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/ara/com
    ${CMAKE_SOURCE_DIR}/ara/core
    # ${CMAKE_SOURCE_DIR}/ara/diag
    # ${CMAKE_SOURCE_DIR}/ara/exec
    ${CMAKE_SOURCE_DIR}/ara/log)

# Specify library link dependencies for target "control". CMake generator 
# expressions are used to create a CMakeLists.txt file that supports 
# multiple platforms with differently named system library dependencies.
target_link_libraries(control PRIVATE Threads::Threads
    $<$<BOOL:${FOUND_LIBM}>:m>
    $<$<BOOL:${WIN32}>:kernel32>
    $<$<BOOL:${WIN32}>:ws2_32>
    $<$<BOOL:${WIN32}>:mswsock>
    $<$<BOOL:${WIN32}>:advapi32>
    Threads::Threads
    ${Boost_LIBRARIES}
    vsomeip3)

# Extract DWARF debug symbols into a separate file when building 
# executable programs for Apple platforms.
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    string(APPEND _dsymutilcmd "$<IF:$<CONFIG:DEBUG,RELWITHDEBINFO>,"
                "xcrun;dsymutil;$<TARGET_FILE:control>;--flat,"
                "true"
        >)
    add_custom_command(TARGET control
            POST_BUILD
            COMMAND "${_dsymutilcmd}"
            COMMAND_EXPAND_LISTS
            BYPRODUCTS control.dwarf)
endif()


###########################################################################
## Build success message
###########################################################################
add_custom_command(TARGET control POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:control>")

###########################################################################
## Call toolchain hook function if defined
###########################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(control)
endif()
