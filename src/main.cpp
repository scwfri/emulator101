#include "disas/Disassemble8080.h"
#include "emulator/Emulator8080.h"

#include <cstdio>
#include <cstdlib>
#include <string>


int main(int argc, char **argv) {
    std::string arg = argv[1];
    if (arg == "-D") {
        auto *disas = new Disassemble8080(argv[2]);
        auto rval = disas->DisassembleFile();
        if (rval != 0) {
            printf("Error disassembling");
        }
        delete disas;
    } else if (arg == "-E") {
        auto *emulator = new Emulator8080(argv[2]);
        //auto rval = emulator->ProcessInstruction();
    }
}
