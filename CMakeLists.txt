project(cpp_study_case)
cmake_minimum_required(VERSION 2.8.3)

#build in c++11
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
     message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

#set release
if (NOT CMAKE_BUILD_TYPE)
    message("not defined Build Type:auto define it to Debug" )
    set (CMAKE_BUILD_TYPE Debug)
endif (NOT CMAKE_BUILD_TYPE)
 
if (CMAKE_BUILD_TYPE MATCHES "Debug" )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g ")
elseif (CMAKE_BUILD_TYPE MATCHES "Release" )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 ")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 ")
elseif (CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 ")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O2 ")
else()
    message("unkown defined Build Type:same handle with Debug" )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g ")
endif (CMAKE_BUILD_TYPE MATCHES "Debug")

find_package(Boost REQUIRED COMPONENTS system)

include_directories(
    include
)

#set bin file directory

SET(BIN_DESTINATION ${PROJECT_SOURCE_DIR}/bin)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DESTINATION})

add_executable(overload src/overload.cpp)

add_executable(std_unique_ptr src/std_unique_ptr.cpp)

add_executable(test_multi_inheritance src/test_multi_inheritance.cpp)

add_executable(test_single_inheritance src/test_single_inheritance.cpp)

add_executable(test_virtual src/test_virtual.cpp)

