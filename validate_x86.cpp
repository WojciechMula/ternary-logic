#include <cstdlib>
#include <cstdio>
#include <cstdint>

#include "ternary_x86_64.cpp"
#include "ternary_x86_32.cpp"

template <unsigned K>
void validate() {
    const uint64_t A = 0xf0; // 0b1111_0000
    const uint64_t B = 0xcc; // 0b1100_1100
    const uint64_t C = 0xaa; // 0b1010_1010

    const uint64_t R64 = ternarylogic::x86_64::ternary<K>(A, B, C);
    const uint64_t R32 = ternarylogic::x86_32::ternary<K>(A, B, C);

    const uint8_t expected = K;
    const uint8_t result64 = R64 & 0xff;
    const uint8_t result32 = R32 & 0xff;

    if (result64 != expected) {
        printf("result64 = %02x, expected = %02x\n", result64, expected);
        exit(1);
    }

    if (result32 != expected) {
        printf("result32 = %02x, expected = %02x\n", result32, expected);
        exit(1);
    }
}


void validate_all() {

#define VALIDATE_4(shift) \
    validate<0x00 + shift>(); \
    validate<0x01 + shift>(); \
    validate<0x02 + shift>(); \
    validate<0x03 + shift>();

#define VALIDATE_16(shift) \
    VALIDATE_4(0x00 + shift) \
    VALIDATE_4(0x04 + shift) \
    VALIDATE_4(0x08 + shift) \
    VALIDATE_4(0x0a + shift)

    VALIDATE_16(0x00);
    VALIDATE_16(0x10);
    VALIDATE_16(0x20);
    VALIDATE_16(0x30);
    VALIDATE_16(0x40);
    VALIDATE_16(0x50);
    VALIDATE_16(0x60);
    VALIDATE_16(0x70);
    VALIDATE_16(0x80);
    VALIDATE_16(0x90);
    VALIDATE_16(0xa0);
    VALIDATE_16(0xb0);
    VALIDATE_16(0xc0);
    VALIDATE_16(0xd0);
    VALIDATE_16(0xe0);
    VALIDATE_16(0xf0);
}

int main() {
    validate_all();
    puts("All OK");
}
