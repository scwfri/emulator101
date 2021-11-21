cmake_minimum_required(VERSION 3.13)
project(emulator101)

add_executable(emulator101 src/main.cpp src/main.cpp disas/Disassemble8080.h disas/Disassemble8080.cpp)