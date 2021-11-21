#ifndef EMULATOR101_ROMPROCESSOR_H
#define EMULATOR101_ROMPROCESSOR_H

#include "../processor8080/Processor8080.h"

class RomProcessor {
  public:
    RomProcessor() = delete;
    RomProcessor(Processor8080 processor);
    ~RomProcessor() = default;
    RomProcessor(const RomProcessor &) = delete;
    RomProcessor &operator=(const RomProcessor &) = delete;

  private:
    Processor8080 processor;

};

#endif // EMULATOR101_ROMPROCESSOR_H
