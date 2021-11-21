cmake_minimum_required(VERSION 3.13)
project(emulator101)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/disas/Disassemble8080.h
        src/disas/Disassemble8080.cpp
        src/emulator/Emulator8080.h
        src/emulator/Emulator8080.cpp
        src/processor8080/FileProcessor.h
        src/processor8080/FileProcessor.cpp)

add_library(libemulator101 ${SOURCE_FILES})
add_executable(emulator101 src/main.cpp)
target_link_libraries(emulator101 libemulator101)
