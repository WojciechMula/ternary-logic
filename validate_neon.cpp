#include <cstdlib>
#include <cstdio>
#include <cstdint>

#include "ternary_neon.cpp"

template <unsigned K>
void validate() {
    const int32x4_t A = vreinterpretq_s32_s16(vdupq_n_s16(0xf0)); // 0b1111_0000
    const int32x4_t B = vreinterpretq_s32_s16(vdupq_n_s16(0xcc)); // 0b1100_1100
    const int32x4_t C = vreinterpretq_s32_s16(vdupq_n_s16(0xaa)); // 0b1010_1010

    const int32x4_t R = ternarylogic::neon::ternary<K>(A, B, C);

    const uint8_t expected = K;
    const uint8_t result   = static_cast<uint8_t>(vgetq_lane_s16(vreinterpretq_s16_s32(R), 0));

    if (result != expected) {
        printf("result = %02x, expected = %02x\n", result, expected);
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
