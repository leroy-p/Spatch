cmake_minimum_required(VERSION 3.6)
project(Spatch)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        lib/libssh.h)

LINK_DIRECTORIES(lib/)

INCLUDE_DIRECTORIES(lib/)

add_executable(Spatch ${SOURCE_FILES})