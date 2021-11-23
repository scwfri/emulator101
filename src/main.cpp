#include "disas/Disassemble8080.h"
#include "emulator/Emulator8080.h"

#include <cstdio>
#include <string>

#include "processor8080/FileProcessor.h"

int main(int argc, char **argv) {
    std::string arg = argv[1];
    const char *fname = argv[2];
    auto fp_ = new FileProcessor(fname);
    if (arg == "-D") {
        auto *disas = new Disassemble8080(argv[2]);
        auto rval = disas->Process();
        if (rval != 0) {
            printf("Error disassembling");
        }
        delete disas;
    } else if (arg == "-E") {
        auto *emulator = new Emulator8080(argv[2]);
        auto rval = emulator->InitEmulator();
        if (rval != 0) {
            printf("Error process instructions");
        }
        delete emulator;
    }
}
