#ifndef EMULATOR101_EMULATOR8080_H
#define EMULATOR101_EMULATOR8080_H

#include <cstdint>

class Emulator8080 {
  public:
    Emulator8080() = delete;
    ~Emulator8080();
    Emulator8080(const Emulator8080 &) = delete;
    Emulator8080 &operator=(const Emulator8080 &) = delete;

  public:
    explicit Emulator8080(const char *);
    void ProcessInstruction();
    void UnimplementedInstruction();

  private:
    struct ConditionCodes {
        uint8_t z : 1;
        uint8_t s : 1;
        uint8_t p : 1;
        uint8_t cy : 1;
        uint8_t ac : 1;
        uint8_t pad : 3;
    };

    struct State8080 {
        uint8_t a{};
        uint8_t b{};
        uint8_t c{};
        uint8_t d{};
        uint8_t e{};
        uint8_t h{};
        uint8_t l{};
        uint8_t *memory{};
        uint8_t int_enable{};
        uint16_t sp{};
        uint16_t pc{};
        struct ConditionCodes cc;
    };

  private:
    State8080 *state8080;
    const char *fname;
};

#endif // EMULATOR101_EMULATOR8080_H
