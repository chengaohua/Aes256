project(encrypt&&merge)

cmake_minimum_required(VERSION 2.6)

set(compiler_common_flags "-ggdb -Wall -Wsign-compare -Wformat-security -Wpointer-arith")
set(compiler_common_flags "${compiler_common_flags} -fPIC -fdiagnostics-show-option")
set(compiler_common_flags "${compiler_common_flags} -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_REENTRANT")

set(CMAKE_C_FLAGS "${compiler_common_flags} -Wmissing-prototypes ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${compiler_common_flags} -Wnon-virtual-dtor -Woverloaded-virtual ${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(src)

add_subdirectory(src)

add_subdirectory(samples)
