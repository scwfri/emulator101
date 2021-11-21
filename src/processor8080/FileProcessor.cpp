#include "FileProcessor.h"

#include <cstdio>
#include <cstdlib>

FileProcessor::FileProcessor(const char *fname_) : fname(fname_) {}

int FileProcessor::ProcessFile() {
    FILE *f= fopen(this->fname, "rb");
    if (f==nullptr)
    {
        printf("error: Couldn't open %s\n", this->fname);
        exit(1);
    }

    //Get the file size and read it into a memory buffer
    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    // TODO need to read this into memory for Emulator or store in buffer for Disassembler
    auto buffer = static_cast<unsigned char *>(malloc(fsize));

    fread(buffer, fsize, 1, f);
    fclose(f);

    int pc = 0;
    while (pc < fsize)
    {
        //pc += this->processpc(buffer, pc);
    }
    return 0;
}