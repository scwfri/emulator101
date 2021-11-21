#include "RomProcessor.h"
#include "../processor8080/Processor8080.h"

#include <cstdio>
#include <cstdlib>

RomProcessor::RomProcessor(Processor8080 processor) : processor(processor) {}

RomProcessor::process() {
    FILE *f = fopen(this->fname, "rb");
    if (f == NULL) {
        printf("error: Couldn't open %s\n", this->fname);
        exit(1);
    }

    // Get the file size and read it into a memory buffer
    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    auto buffer = static_cast<unsigned char *>(malloc(fsize));

    fread(buffer, fsize, 1, f);
    fclose(f);

    int pc = 0;

    while (pc < fsize) {
        pc += this->ProcessInstruction(buffer, pc);
    }
    return 0;
}