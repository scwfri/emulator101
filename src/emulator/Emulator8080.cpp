#include "Emulator8080.h"

#include <cstdio>
#include <cstdlib>

Emulator8080::Emulator8080(const char *fname) : fname(fname) {
    this->state8080 = new State8080();
    this->InitEmulator();
}

Emulator8080::~Emulator8080() { delete this->state8080; }

int Emulator8080::InitEmulator() {
    FILE *f = fopen(this->fname, "rb");
    if (f == nullptr) {
        printf("error: Couldn't open %s\n", this->fname);
        exit(1);
    }

    // Get the file size and read it into a memory buffer
    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    // TODO need to read this into memory for Emulator or store in buffer for
    // Disassembler
    auto buff = static_cast<unsigned char *>(malloc(fsize));
    this->state8080->memory = buff;

    fread(buff, fsize, 1, f);
    fclose(f);

    auto pc = &this->state8080->pc;
    while (*pc < fsize) {
        *pc += this->Process();
    }
    return 0;
}

int Emulator8080::Process() {
    auto state = this->state8080;
    unsigned char *opcode = &state->memory[state->pc];

    switch (*opcode) {
        case 0x00:
            break;
        case 0x01:
            state->c = opcode[1];
            state->b = opcode[2];
            state->pc += 2;
            break;
        case 0x02:
            this->UnimplementedInstruction();
            break;
        case 0x03:
            this->UnimplementedInstruction();
            break;
        case 0x04:
            this->UnimplementedInstruction();
            break;
        case 0x05:
            this->UnimplementedInstruction();
            break;
        case 0x06:
            this->UnimplementedInstruction();
            break;
        case 0x07:
            this->UnimplementedInstruction();
            break;
        case 0x08:
            this->UnimplementedInstruction();
            break;
        case 0x09:
            this->UnimplementedInstruction();
            break;
        case 0x0a:
            this->UnimplementedInstruction();
            break;
        case 0x0b:
            this->UnimplementedInstruction();
            break;
        case 0x0c:
            this->UnimplementedInstruction();
            break;
        case 0x0d:
            this->UnimplementedInstruction();
            break;
        case 0x0e:
            this->UnimplementedInstruction();
            break;
        case 0x0f:
            this->UnimplementedInstruction();
            break;
        case 0x10:
            this->UnimplementedInstruction();
            break;
        case 0x11:
            this->UnimplementedInstruction();
            break;
        case 0x12:
            this->UnimplementedInstruction();
            break;
        case 0x13:
            this->UnimplementedInstruction();
            break;
        case 0x14:
            this->UnimplementedInstruction();
            break;
        case 0x15:
            this->UnimplementedInstruction();
            break;
        case 0x16:
            this->UnimplementedInstruction();
            break;
        case 0x17:
            this->UnimplementedInstruction();
            break;
        case 0x18:
            this->UnimplementedInstruction();
            break;
        case 0x19:
            this->UnimplementedInstruction();
            break;
        case 0x1a:
            this->UnimplementedInstruction();
            break;
        case 0x1b:
            this->UnimplementedInstruction();
            break;
        case 0x1c:
            this->UnimplementedInstruction();
            break;
        case 0x1d:
            this->UnimplementedInstruction();
            break;
        case 0x1e:
            this->UnimplementedInstruction();
            break;
        case 0x1f:
            this->UnimplementedInstruction();
            break;
        case 0x20:
            this->UnimplementedInstruction();
            break;
        case 0x21:
            this->UnimplementedInstruction();
            break;
        case 0x22:
            this->UnimplementedInstruction();
            break;
        case 0x23:
            this->UnimplementedInstruction();
            break;
        case 0x24:
            this->UnimplementedInstruction();
            break;
        case 0x25:
            this->UnimplementedInstruction();
            break;
        case 0x26:
            this->UnimplementedInstruction();
            break;
        case 0x27:
            this->UnimplementedInstruction();
            break;
        case 0x28:
            this->UnimplementedInstruction();
            break;
        case 0x29:
            this->UnimplementedInstruction();
            break;
        case 0x2a:
            this->UnimplementedInstruction();
            break;
        case 0x2b:
            this->UnimplementedInstruction();
            break;
        case 0x2c:
            this->UnimplementedInstruction();
            break;
        case 0x2d:
            this->UnimplementedInstruction();
            break;
        case 0x2e:
            this->UnimplementedInstruction();
            break;
        case 0x2f:
            this->UnimplementedInstruction();
            break;
        case 0x30:
            this->UnimplementedInstruction();
            break;
        case 0x31:
            this->UnimplementedInstruction();
            break;
        case 0x32:
            this->UnimplementedInstruction();
            break;
        case 0x33:
            this->UnimplementedInstruction();
            break;
        case 0x34:
            this->UnimplementedInstruction();
            break;
        case 0x35:
            this->UnimplementedInstruction();
            break;
        case 0x36:
            this->UnimplementedInstruction();
            break;
        case 0x37:
            this->UnimplementedInstruction();
            break;
        case 0x38:
            this->UnimplementedInstruction();
            break;
        case 0x39:
            this->UnimplementedInstruction();
            break;
        case 0x3a:
            this->UnimplementedInstruction();
            break;
        case 0x3b:
            this->UnimplementedInstruction();
            break;
        case 0x3c:
            this->UnimplementedInstruction();
            break;
        case 0x3d:
            this->UnimplementedInstruction();
            break;
        case 0x3e:
            this->UnimplementedInstruction();
            break;
        case 0x3f:
            this->UnimplementedInstruction();
            break;
        case 0x40:
            this->UnimplementedInstruction();
            break;
        case 0x41: // MOV B,C
            state->b = state->c;
            break;
        case 0x42: // MOV B, D
            state->b = state->d;
            break;
        case 0x43: // MOV B,E
            state->b = state->e;
            break;
        case 0x44:
            this->UnimplementedInstruction();
            break;
        case 0x45:
            this->UnimplementedInstruction();
            break;
        case 0x46:
            this->UnimplementedInstruction();
            break;
        case 0x47:
            this->UnimplementedInstruction();
            break;
        case 0x48:
            this->UnimplementedInstruction();
            break;
        case 0x49:
            this->UnimplementedInstruction();
            break;
        case 0x4a:
            this->UnimplementedInstruction();
            break;
        case 0x4b:
            this->UnimplementedInstruction();
            break;
        case 0x4c:
            this->UnimplementedInstruction();
            break;
        case 0x4d:
            this->UnimplementedInstruction();
            break;
        case 0x4e:
            this->UnimplementedInstruction();
            break;
        case 0x4f:
            this->UnimplementedInstruction();
            break;
        case 0x50:
            this->UnimplementedInstruction();
            break;
        case 0x51:
            this->UnimplementedInstruction();
            break;
        case 0x52:
            this->UnimplementedInstruction();
            break;
        case 0x53:
            this->UnimplementedInstruction();
            break;
        case 0x54:
            this->UnimplementedInstruction();
            break;
        case 0x55:
            this->UnimplementedInstruction();
            break;
        case 0x56:
            this->UnimplementedInstruction();
            break;
        case 0x57:
            this->UnimplementedInstruction();
            break;
        case 0x58:
            this->UnimplementedInstruction();
            break;
        case 0x59:
            this->UnimplementedInstruction();
            break;
        case 0x5a:
            this->UnimplementedInstruction();
            break;
        case 0x5b:
            this->UnimplementedInstruction();
            break;
        case 0x5c:
            this->UnimplementedInstruction();
            break;
        case 0x5d:
            this->UnimplementedInstruction();
            break;
        case 0x5e:
            this->UnimplementedInstruction();
            break;
        case 0x5f:
            this->UnimplementedInstruction();
            break;
        case 0x60:
            this->UnimplementedInstruction();
            break;
        case 0x61:
            this->UnimplementedInstruction();
            break;
        case 0x62:
            this->UnimplementedInstruction();
            break;
        case 0x63:
            this->UnimplementedInstruction();
            break;
        case 0x64:
            this->UnimplementedInstruction();
            break;
        case 0x65:
            this->UnimplementedInstruction();
            break;
        case 0x66:
            this->UnimplementedInstruction();
            break;
        case 0x67:
            this->UnimplementedInstruction();
            break;
        case 0x68:
            this->UnimplementedInstruction();
            break;
        case 0x69:
            this->UnimplementedInstruction();
            break;
        case 0x6a:
            this->UnimplementedInstruction();
            break;
        case 0x6b:
            this->UnimplementedInstruction();
            break;
        case 0x6c:
            this->UnimplementedInstruction();
            break;
        case 0x6d:
            this->UnimplementedInstruction();
            break;
        case 0x6e:
            this->UnimplementedInstruction();
            break;
        case 0x6f:
            this->UnimplementedInstruction();
            break;
        case 0x70:
            this->UnimplementedInstruction();
            break;
        case 0x71:
            this->UnimplementedInstruction();
            break;
        case 0x72:
            this->UnimplementedInstruction();
            break;
        case 0x73:
            this->UnimplementedInstruction();
            break;
        case 0x74:
            this->UnimplementedInstruction();
            break;
        case 0x75:
            this->UnimplementedInstruction();
            break;
        case 0x76:
            this->UnimplementedInstruction();
            break;
        case 0x77:
            this->UnimplementedInstruction();
            break;
        case 0x78:
            this->UnimplementedInstruction();
            break;
        case 0x79:
            this->UnimplementedInstruction();
            break;
        case 0x7a:
            this->UnimplementedInstruction();
            break;
        case 0x7b:
            this->UnimplementedInstruction();
            break;
        case 0x7c:
            this->UnimplementedInstruction();
            break;
        case 0x7d:
            this->UnimplementedInstruction();
            break;
        case 0x7e:
            this->UnimplementedInstruction();
            break;
        case 0x7f:
            this->UnimplementedInstruction();
            break;
        case 0x80: // ADD B
            uint16_t res = (uint16_t) state->a + (uint16_t) state->b;
            state->cc.z = ((res & 0xff) == 0); // zero flag if res == 0
            state->cc.s = ((res & 0x08) != 0); // sign flag is bit 7 is set
            state->cc.cy = (res > 0xff); // carry flag
            state->cc.p = 0; // TODO placeholder; fix this
            state->a = res & 0xff; // store our res value
            break;
        case 0x81: // ADD C
            (uint16_t) res = (uint16_t) state->a + (uint16_t) state->c;
            state->cc.z = ((res & 0xff) == 0);
            state->cc.s = ((res & 0x80) != 0);
            state->cc.cy = (res > 0xff);
            // TODO implement parity check
            state->cc.p = 0; // TODO iplement this
            state->a = res & 0xff;
            break;
        case 0x82: // ADD D
            (uint16_t) res = (uint16_t) state->a + (uint16_t) state->d;
            state->cc.z = ((res & 0xff) == 0);
            state->cc.s = ((res & 0x80) != 0);
            state->cc.cy = (res > 0xff);
            // TODO implement parity check
            state->cc.p = 0; // TODO iplement this
            state->a = res & 0xff;
            break;
        case 0x83: // ADD E
            (uint16_t) res = (uint16_t) state->a + (uint16_t) state->e;
            state->cc.z = ((res & 0xff) == 0);
            state->cc.s = ((res & 0x80) != 0);
            state->cc.cy = (res > 0xff);
            // TODO implement parity check
            state->cc.p = 0; // TODO iplement this
            state->a = res & 0xff;
            break;
        case 0x84: // ADD H
            (uint16_t) res = (uint16_t) state->a + (uint16_t) state->h;
            state->cc.z = ((res & 0xff) == 0);
            state->cc.s = ((res & 0x80) != 0);
            state->cc.cy = (res > 0xff);
            // TODO implement parity check
            state->cc.p = 0; // TODO iplement this
            state->a = res & 0xff;
            break;
        case 0x85: // ADD L
            (uint16_t) res = (uint16_t) state->a + (uint16_t) state->l;
            state->cc.z = ((res & 0xff) == 0);
            state->cc.s = ((res & 0x80) != 0);
            state->cc.cy = (res > 0xff);
            // TODO implement parity check
            state->cc.p = 0; // TODO iplement this
            state->a = res & 0xff;
            break;
        case 0x86: // ADD M
            (uint16_t) res = (uint16_t) state->a + (uint16_t) state->m;
            state->cc.z = ((res & 0xff) == 0);
            state->cc.s = ((res & 0x80) != 0);
            state->cc.cy = (res > 0xff);
            // TODO implement parity check
            state->cc.p = 0; // TODO iplement this
            state->a = res & 0xff;
            break;
        case 0x87:
            this->UnimplementedInstruction();
            break;
        case 0x88:
            this->UnimplementedInstruction();
            break;
        case 0x89:
            this->UnimplementedInstruction();
            break;
        case 0x8a:
            this->UnimplementedInstruction();
            break;
        case 0x8b:
            this->UnimplementedInstruction();
            break;
        case 0x8c:
            this->UnimplementedInstruction();
            break;
        case 0x8d:
            this->UnimplementedInstruction();
            break;
        case 0x8e:
            this->UnimplementedInstruction();
            break;
        case 0x8f:
            this->UnimplementedInstruction();
            break;
        case 0x90:
            this->UnimplementedInstruction();
            break;
        case 0x91:
            this->UnimplementedInstruction();
            break;
        case 0x92:
            this->UnimplementedInstruction();
            break;
        case 0x93:
            this->UnimplementedInstruction();
            break;
        case 0x94:
            this->UnimplementedInstruction();
            break;
        case 0x95:
            this->UnimplementedInstruction();
            break;
        case 0x96:
            this->UnimplementedInstruction();
            break;
        case 0x97:
            this->UnimplementedInstruction();
            break;
        case 0x98:
            this->UnimplementedInstruction();
            break;
        case 0x99:
            this->UnimplementedInstruction();
            break;
        case 0x9a:
            this->UnimplementedInstruction();
            break;
        case 0x9b:
            this->UnimplementedInstruction();
            break;
        case 0x9c:
            this->UnimplementedInstruction();
            break;
        case 0x9d:
            this->UnimplementedInstruction();
            break;
        case 0x9e:
            this->UnimplementedInstruction();
            break;
        case 0x9f:
            this->UnimplementedInstruction();
            break;
        case 0xa0:
            this->UnimplementedInstruction();
            break;
        case 0xa1:
            this->UnimplementedInstruction();
            break;
        case 0xa2:
            this->UnimplementedInstruction();
            break;
        case 0xa3:
            this->UnimplementedInstruction();
            break;
        case 0xa4:
            this->UnimplementedInstruction();
            break;
        case 0xa5:
            this->UnimplementedInstruction();
            break;
        case 0xa6:
            this->UnimplementedInstruction();
            break;
        case 0xa7:
            this->UnimplementedInstruction();
            break;
        case 0xa8:
            this->UnimplementedInstruction();
            break;
        case 0xa9:
            this->UnimplementedInstruction();
            break;
        case 0xaa:
            this->UnimplementedInstruction();
            break;
        case 0xab:
            this->UnimplementedInstruction();
            break;
        case 0xac:
            this->UnimplementedInstruction();
            break;
        case 0xad:
            this->UnimplementedInstruction();
            break;
        case 0xae:
            this->UnimplementedInstruction();
            break;
        case 0xaf:
            this->UnimplementedInstruction();
            break;
        case 0xb0:
            this->UnimplementedInstruction();
            break;
        case 0xb1:
            this->UnimplementedInstruction();
            break;
        case 0xb2:
            this->UnimplementedInstruction();
            break;
        case 0xb3:
            this->UnimplementedInstruction();
            break;
        case 0xb4:
            this->UnimplementedInstruction();
            break;
        case 0xb5:
            this->UnimplementedInstruction();
            break;
        case 0xb6:
            this->UnimplementedInstruction();
            break;
        case 0xb7:
            this->UnimplementedInstruction();
            break;
        case 0xb8:
            this->UnimplementedInstruction();
            break;
        case 0xb9:
            this->UnimplementedInstruction();
            break;
        case 0xba:
            this->UnimplementedInstruction();
            break;
        case 0xbb:
            this->UnimplementedInstruction();
            break;
        case 0xbc:
            this->UnimplementedInstruction();
            break;
        case 0xbd:
            this->UnimplementedInstruction();
            break;
        case 0xbe:
            this->UnimplementedInstruction();
            break;
        case 0xbf:
            this->UnimplementedInstruction();
            break;
        case 0xc0:
            this->UnimplementedInstruction();
            break;
        case 0xc1:
            this->UnimplementedInstruction();
            break;
        case 0xc2:
            this->UnimplementedInstruction();
            break;
        case 0xc3:
            this->UnimplementedInstruction();
            break;
        case 0xc4:
            this->UnimplementedInstruction();
            break;
        case 0xc5:
            this->UnimplementedInstruction();
            break;
        case 0xc6:
            this->UnimplementedInstruction();
            break;
        case 0xc7:
            this->UnimplementedInstruction();
            break;
        case 0xc8:
            this->UnimplementedInstruction();
            break;
        case 0xc9:
            this->UnimplementedInstruction();
            break;
        case 0xca:
            this->UnimplementedInstruction();
            break;
        case 0xcb:
            this->UnimplementedInstruction();
            break;
        case 0xcc:
            this->UnimplementedInstruction();
            break;
        case 0xcd:
            this->UnimplementedInstruction();
            break;
        case 0xce:
            this->UnimplementedInstruction();
            break;
        case 0xcf:
            this->UnimplementedInstruction();
            break;
        case 0xd0:
            this->UnimplementedInstruction();
            break;
        case 0xd1:
            this->UnimplementedInstruction();
            break;
        case 0xd2:
            this->UnimplementedInstruction();
            break;
        case 0xd3:
            this->UnimplementedInstruction();
            break;
        case 0xd4:
            this->UnimplementedInstruction();
            break;
        case 0xd5:
            this->UnimplementedInstruction();
            break;
        case 0xd6:
            this->UnimplementedInstruction();
            break;
        case 0xd7:
            this->UnimplementedInstruction();
            break;
        case 0xd8:
            this->UnimplementedInstruction();
            break;
        case 0xd9:
            this->UnimplementedInstruction();
            break;
        case 0xda:
            this->UnimplementedInstruction();
            break;
        case 0xdb:
            this->UnimplementedInstruction();
            break;
        case 0xdc:
            this->UnimplementedInstruction();
            break;
        case 0xdd:
            this->UnimplementedInstruction();
            break;
        case 0xde:
            this->UnimplementedInstruction();
            break;
        case 0xdf:
            this->UnimplementedInstruction();
            break;
        case 0xe0:
            this->UnimplementedInstruction();
            break;
        case 0xe1:
            this->UnimplementedInstruction();
            break;
        case 0xe2:
            this->UnimplementedInstruction();
            break;
        case 0xe3:
            this->UnimplementedInstruction();
            break;
        case 0xe4:
            this->UnimplementedInstruction();
            break;
        case 0xe5:
            this->UnimplementedInstruction();
            break;
        case 0xe6:
            this->UnimplementedInstruction();
            break;
        case 0xe7:
            this->UnimplementedInstruction();
            break;
        case 0xe8:
            this->UnimplementedInstruction();
            break;
        case 0xe9:
            this->UnimplementedInstruction();
            break;
        case 0xea:
            this->UnimplementedInstruction();
            break;
        case 0xeb:
            this->UnimplementedInstruction();
            break;
        case 0xec:
            this->UnimplementedInstruction();
            break;
        case 0xed:
            this->UnimplementedInstruction();
            break;
        case 0xee:
            this->UnimplementedInstruction();
            break;
        case 0xef:
            this->UnimplementedInstruction();
            break;
        case 0xf0:
            this->UnimplementedInstruction();
            break;
        case 0xf1:
            this->UnimplementedInstruction();
            break;
        case 0xf2:
            this->UnimplementedInstruction();
            break;
        case 0xf3:
            this->UnimplementedInstruction();
            break;
        case 0xf4:
            this->UnimplementedInstruction();
            break;
        case 0xf5:
            this->UnimplementedInstruction();
            break;
        case 0xf6:
            this->UnimplementedInstruction();
            break;
        case 0xf7:
            this->UnimplementedInstruction();
            break;
        case 0xf8:
            this->UnimplementedInstruction();
            break;
        case 0xf9:
            this->UnimplementedInstruction();
            break;
        case 0xfa:
            this->UnimplementedInstruction();
            break;
        case 0xfb:
            this->UnimplementedInstruction();
            break;
        case 0xfc:
            this->UnimplementedInstruction();
            break;
        case 0xfd:
            this->UnimplementedInstruction();
            break;
        case 0xfe:
            this->UnimplementedInstruction();
            break;
        case 0xff:
            this->UnimplementedInstruction();
            break;
    }

    return 1;
}

void Emulator8080::UnimplementedInstruction() {
    printf("Error: Unimplemented Instruction\n");
    exit(1);
}
