cmake_minimum_required(VERSION 3.13)
project(emulator101)

set(CMAKE_CXX_STANDARD 14)

add_executable(emulator101 src/main.cpp src/main.cpp src/disas/Disassemble8080.h src/emulator/Emulator8080.h src/emulator/Emulator8080.cpp src/RomProcessor.h src/RomProcessor.cpp src/processor8080/FileProcessor.h src/processor8080/FileProcessor.cpp)