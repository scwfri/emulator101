#ifndef EMULATOR101_DISASSEMBLE8080_H
#define EMULATOR101_DISASSEMBLE8080_H

#include "../../processor8080/Processor8080.h"

class Disassemble8080 {
  public:
    Disassemble8080() = delete;
    ~Disassemble8080() = default;
    Disassemble8080(const Disassemble8080 &) = delete;
    Disassemble8080 &operator=(const Disassemble8080 &) = delete;

  public:
    int DisassembleFile();
    explicit Disassemble8080(const char *);

  private:
    const char *fname;
    int ProcessInstruction(unsigned char *buffer, int pc);
};

#endif // EMULATOR101_DISASSEMBLE8080_H
