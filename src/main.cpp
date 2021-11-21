#include <cstdio>
#include <cstdlib>

#include "../disas/Disassemble8080.h"

// forward declaration
int Disassemble8080p(unsigned char *, int);

int main(int argc, char **argv) {
    auto *disas = new Disassemble8080(argv[1]);
    auto rval = disas->DisassembleFile();
    if (rval != 0) {
        printf("Error disassembling");
    }
    delete disas;
}

