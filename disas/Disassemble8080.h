#ifndef EMULATOR101_DISASSEMBLE8080_H
#define EMULATOR101_DISASSEMBLE8080_H

class Disassemble8080 {
  public:
    Disassemble8080() = delete;
    explicit Disassemble8080(const char *);
    ~Disassemble8080() = default;
    Disassemble8080(const Disassemble8080 &) = delete;
    Disassemble8080 &operator=(const Disassemble8080 &) = delete;

    int DisassembleFile();

  private:
    const char *fname;
    int ReadInstruction(unsigned char *buffer, int pc);
};

#endif // EMULATOR101_DISASSEMBLE8080_H
