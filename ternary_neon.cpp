// Generated automatically, please do not edit
#pragma once
#include <arm_neon.h>

namespace ternarylogic {

    namespace neon {

        template<unsigned k> int32x4_t ternary(const int32x4_t, const int32x4_t, const int32x4_t) {
            static_assert(k < 256, "Unspecified ternary function");
            return vdupq_n_s32(0);
        }

        // code=0x00, function=0, lowered=0, set=intel
        template<> int32x4_t ternary<0x00>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c0 = vdupq_n_s32(0);
            return c0;
        }
        // code=0x01, function=(A nor (B or C)), lowered=((A or (B or C)) xor 1), set=intel
        template<> int32x4_t ternary<0x01>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t t1 = vorrq_s32(A, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x02, function=(C and (B nor A)), lowered=((B or A) notand C), set=intel
        template<> int32x4_t ternary<0x02>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, A);
            const int32x4_t t1 = vbicq_s32(C, t0);
            return t1;
        }
        // code=0x03, function=(B nor A), lowered=((B or A) xor 1), set=intel
        template<> int32x4_t ternary<0x03>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            return t1;
        }
        // code=0x04, function=(B and (A nor C)), lowered=((A or C) notand B), set=intel
        template<> int32x4_t ternary<0x04>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, C);
            const int32x4_t t1 = vbicq_s32(B, t0);
            return t1;
        }
        // code=0x05, function=(C nor A), lowered=((C or A) xor 1), set=intel
        template<> int32x4_t ternary<0x05>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(C, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            return t1;
        }
        // code=0x06, function=(not (A) and (B xor C)), lowered=(A notand (B xor C)), set=automat
        template<> int32x4_t ternary<0x06>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t t1 = vbicq_s32(t0, A);
            return t1;
        }
        // code=0x07, function=(A nor (B and C)), lowered=((A or (B and C)) xor 1), set=intel
        template<> int32x4_t ternary<0x07>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t t1 = vorrq_s32(A, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x08, function=((not (A) and B) and C), lowered=((A notand B) and C), set=automat
        template<> int32x4_t ternary<0x08>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, A);
            const int32x4_t t1 = vandq_s32(t0, C);
            return t1;
        }
        // code=0x09, function=(A nor (B xor C)), lowered=((A or (B xor C)) xor 1), set=intel
        template<> int32x4_t ternary<0x09>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t t1 = vorrq_s32(A, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x0a, function=(C and not (A)), lowered=(A notand C), set=intel
        template<> int32x4_t ternary<0x0a>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, A);
            return t0;
        }
        // code=0x0b, function=(not (A) and ((B xor 1) or C)), lowered=(A notand ((B xor 1) or C)), set=automat
        template<> int32x4_t ternary<0x0b>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(B, c1);
            const int32x4_t t1 = vorrq_s32(t0, C);
            const int32x4_t t2 = vbicq_s32(t1, A);
            return t2;
        }
        // code=0x0c, function=(B and not (A)), lowered=(A notand B), set=intel
        template<> int32x4_t ternary<0x0c>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, A);
            return t0;
        }
        // code=0x0d, function=(not (A) and (B or (C xor 1))), lowered=(A notand (B or (C xor 1))), set=automat
        template<> int32x4_t ternary<0x0d>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(C, c1);
            const int32x4_t t1 = vorrq_s32(B, t0);
            const int32x4_t t2 = vbicq_s32(t1, A);
            return t2;
        }
        // code=0x0e, function=(not (A) and (B or C)), lowered=(A notand (B or C)), set=automat
        template<> int32x4_t ternary<0x0e>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t t1 = vbicq_s32(t0, A);
            return t1;
        }
        // code=0x0f, function=not (A), lowered=(A xor 1), set=intel
        template<> int32x4_t ternary<0x0f>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(A, c1);
            return t0;
        }
        // code=0x10, function=(A and (B nor C)), lowered=((B or C) notand A), set=intel
        template<> int32x4_t ternary<0x10>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t t1 = vbicq_s32(A, t0);
            return t1;
        }
        // code=0x11, function=(C nor B), lowered=((C or B) xor 1), set=intel
        template<> int32x4_t ternary<0x11>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(C, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            return t1;
        }
        // code=0x12, function=(not (B) and (A xor C)), lowered=(B notand (A xor C)), set=automat
        template<> int32x4_t ternary<0x12>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t t1 = vbicq_s32(t0, B);
            return t1;
        }
        // code=0x13, function=(B nor (A and C)), lowered=((B or (A and C)) xor 1), set=intel
        template<> int32x4_t ternary<0x13>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t t1 = vorrq_s32(B, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x14, function=(not (C) and (A xor B)), lowered=(C notand (A xor B)), set=automat
        template<> int32x4_t ternary<0x14>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, B);
            const int32x4_t t1 = vbicq_s32(t0, C);
            return t1;
        }
        // code=0x15, function=(C nor (B and A)), lowered=((C or (B and A)) xor 1), set=intel
        template<> int32x4_t ternary<0x15>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, A);
            const int32x4_t t1 = vorrq_s32(C, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x16, function=(A ? (B nor C) : (B xor C)), lowered=(((B or C) notand A) or (A notand (B xor C))), set=intel
        template<> int32x4_t ternary<0x16>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t t1 = vbicq_s32(A, t0);
            const int32x4_t t2 = veorq_s32(B, C);
            const int32x4_t t3 = vbicq_s32(t2, A);
            const int32x4_t t4 = vorrq_s32(t1, t3);
            return t4;
        }
        // code=0x17, function=((B nor C) or (not (A) and (B xor C))), lowered=(((B or C) xor 1) or (A notand (B xor C))), set=optimized
        template<> int32x4_t ternary<0x17>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            const int32x4_t t2 = veorq_s32(B, C);
            const int32x4_t t3 = vbicq_s32(t2, A);
            const int32x4_t t4 = vorrq_s32(t1, t3);
            return t4;
        }
        // code=0x18, function=((A xor B) and (A xor C)), lowered=((A xor B) and (A xor C)), set=automat
        template<> int32x4_t ternary<0x18>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, B);
            const int32x4_t t1 = veorq_s32(A, C);
            const int32x4_t t2 = vandq_s32(t0, t1);
            return t2;
        }
        // code=0x19, function=(not ((A and B)) and (B xor (C xor 1))), lowered=((A and B) notand (B xor (C xor 1))), set=automat
        template<> int32x4_t ternary<0x19>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = veorq_s32(B, t1);
            const int32x4_t t3 = vbicq_s32(t2, t0);
            return t3;
        }
        // code=0x1a, function=(not ((A and B)) and (A xor C)), lowered=((A and B) notand (A xor C)), set=automat
        template<> int32x4_t ternary<0x1a>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, B);
            const int32x4_t t1 = veorq_s32(A, C);
            const int32x4_t t2 = vbicq_s32(t1, t0);
            return t2;
        }
        // code=0x1b, function=(C ? not (A) : not (B)), lowered=((A notand C) or (C notand (B xor 1))), set=intel
        template<> int32x4_t ternary<0x1b>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = vbicq_s32(t1, C);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x1c, function=(not ((A and C)) and (A xor B)), lowered=((A and C) notand (A xor B)), set=automat
        template<> int32x4_t ternary<0x1c>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t t1 = veorq_s32(A, B);
            const int32x4_t t2 = vbicq_s32(t1, t0);
            return t2;
        }
        // code=0x1d, function=(B ? not (A) : not (C)), lowered=((A notand B) or (B notand (C xor 1))), set=intel
        template<> int32x4_t ternary<0x1d>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = vbicq_s32(t1, B);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x1e, function=(A xor (B or C)), lowered=(A xor (B or C)), set=intel
        template<> int32x4_t ternary<0x1e>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t t1 = veorq_s32(A, t0);
            return t1;
        }
        // code=0x1f, function=(A nand (B or C)), lowered=((A and (B or C)) xor 1), set=intel
        template<> int32x4_t ternary<0x1f>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t t1 = vandq_s32(A, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x20, function=((not (B) and A) and C), lowered=((B notand A) and C), set=automat
        template<> int32x4_t ternary<0x20>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, B);
            const int32x4_t t1 = vandq_s32(t0, C);
            return t1;
        }
        // code=0x21, function=(B nor (A xor C)), lowered=((B or (A xor C)) xor 1), set=intel
        template<> int32x4_t ternary<0x21>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t t1 = vorrq_s32(B, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x22, function=(C and not (B)), lowered=(B notand C), set=intel
        template<> int32x4_t ternary<0x22>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, B);
            return t0;
        }
        // code=0x23, function=(not (B) and ((A xor 1) or C)), lowered=(B notand ((A xor 1) or C)), set=automat
        template<> int32x4_t ternary<0x23>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(A, c1);
            const int32x4_t t1 = vorrq_s32(t0, C);
            const int32x4_t t2 = vbicq_s32(t1, B);
            return t2;
        }
        // code=0x24, function=((A xor B) and (B xor C)), lowered=((A xor B) and (B xor C)), set=automat
        template<> int32x4_t ternary<0x24>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, B);
            const int32x4_t t1 = veorq_s32(B, C);
            const int32x4_t t2 = vandq_s32(t0, t1);
            return t2;
        }
        // code=0x25, function=(not ((A and B)) and (A xor (C xor 1))), lowered=((A and B) notand (A xor (C xor 1))), set=automat
        template<> int32x4_t ternary<0x25>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = vbicq_s32(t2, t0);
            return t3;
        }
        // code=0x26, function=(not ((A and B)) and (B xor C)), lowered=((A and B) notand (B xor C)), set=automat
        template<> int32x4_t ternary<0x26>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, B);
            const int32x4_t t1 = veorq_s32(B, C);
            const int32x4_t t2 = vbicq_s32(t1, t0);
            return t2;
        }
        // code=0x27, function=(C ? not (B) : not (A)), lowered=((B notand C) or (C notand (A xor 1))), set=intel
        template<> int32x4_t ternary<0x27>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(A, c1);
            const int32x4_t t2 = vbicq_s32(t1, C);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x28, function=(C and (B xor A)), lowered=(C and (B xor A)), set=intel
        template<> int32x4_t ternary<0x28>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, A);
            const int32x4_t t1 = vandq_s32(C, t0);
            return t1;
        }
        // code=0x29, function=(C ? (B xor A) : (B nor A)), lowered=((C and (B xor A)) or (C notand ((B or A) xor 1))), set=intel
        template<> int32x4_t ternary<0x29>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, A);
            const int32x4_t t1 = vandq_s32(C, t0);
            const int32x4_t t2 = vorrq_s32(B, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t3 = veorq_s32(t2, c1);
            const int32x4_t t4 = vbicq_s32(t3, C);
            const int32x4_t t5 = vorrq_s32(t1, t4);
            return t5;
        }
        // code=0x2a, function=(C and (B nand A)), lowered=((B and A) notand C), set=intel
        template<> int32x4_t ternary<0x2a>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, A);
            const int32x4_t t1 = vbicq_s32(C, t0);
            return t1;
        }
        // code=0x2b, function=(C ? (B nand A) : (B nor A)), lowered=(((B and A) notand C) or (C notand ((B or A) xor 1))), set=intel
        template<> int32x4_t ternary<0x2b>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, A);
            const int32x4_t t1 = vbicq_s32(C, t0);
            const int32x4_t t2 = vorrq_s32(B, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t3 = veorq_s32(t2, c1);
            const int32x4_t t4 = vbicq_s32(t3, C);
            const int32x4_t t5 = vorrq_s32(t1, t4);
            return t5;
        }
        // code=0x2c, function=((B or C) and (A xor B)), lowered=((B or C) and (A xor B)), set=automat
        template<> int32x4_t ternary<0x2c>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t t1 = veorq_s32(A, B);
            const int32x4_t t2 = vandq_s32(t0, t1);
            return t2;
        }
        // code=0x2d, function=(A xor (B or (C xor 1))), lowered=(A xor (B or (C xor 1))), set=automat
        template<> int32x4_t ternary<0x2d>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(C, c1);
            const int32x4_t t1 = vorrq_s32(B, t0);
            const int32x4_t t2 = veorq_s32(A, t1);
            return t2;
        }
        // code=0x2e, function=((B or C) xor (A and B)), lowered=((B or C) xor (A and B)), set=optimized
        template<> int32x4_t ternary<0x2e>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t t1 = vandq_s32(A, B);
            const int32x4_t t2 = veorq_s32(t0, t1);
            return t2;
        }
        // code=0x2f, function=((not (B) and C) or (A xor 1)), lowered=((B notand C) or (A xor 1)), set=automat
        template<> int32x4_t ternary<0x2f>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(A, c1);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x30, function=(A and not (B)), lowered=(B notand A), set=intel
        template<> int32x4_t ternary<0x30>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, B);
            return t0;
        }
        // code=0x31, function=(not (B) and (A or (C xor 1))), lowered=(B notand (A or (C xor 1))), set=automat
        template<> int32x4_t ternary<0x31>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(C, c1);
            const int32x4_t t1 = vorrq_s32(A, t0);
            const int32x4_t t2 = vbicq_s32(t1, B);
            return t2;
        }
        // code=0x32, function=(not (B) and (A or C)), lowered=(B notand (A or C)), set=automat
        template<> int32x4_t ternary<0x32>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, C);
            const int32x4_t t1 = vbicq_s32(t0, B);
            return t1;
        }
        // code=0x33, function=not (B), lowered=(B xor 1), set=intel
        template<> int32x4_t ternary<0x33>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(B, c1);
            return t0;
        }
        // code=0x34, function=(not ((B and C)) and (A xor B)), lowered=((B and C) notand (A xor B)), set=automat
        template<> int32x4_t ternary<0x34>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t t1 = veorq_s32(A, B);
            const int32x4_t t2 = vbicq_s32(t1, t0);
            return t2;
        }
        // code=0x35, function=(A ? not (B) : not (C)), lowered=((B notand A) or (A notand (C xor 1))), set=intel
        template<> int32x4_t ternary<0x35>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = vbicq_s32(t1, A);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x36, function=(B xor (A or C)), lowered=(B xor (A or C)), set=intel
        template<> int32x4_t ternary<0x36>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, C);
            const int32x4_t t1 = veorq_s32(B, t0);
            return t1;
        }
        // code=0x37, function=(B nand (A or C)), lowered=((B and (A or C)) xor 1), set=intel
        template<> int32x4_t ternary<0x37>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, C);
            const int32x4_t t1 = vandq_s32(B, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x38, function=((A or C) and (A xor B)), lowered=((A or C) and (A xor B)), set=automat
        template<> int32x4_t ternary<0x38>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, C);
            const int32x4_t t1 = veorq_s32(A, B);
            const int32x4_t t2 = vandq_s32(t0, t1);
            return t2;
        }
        // code=0x39, function=(B xor (A or (C xor 1))), lowered=(B xor (A or (C xor 1))), set=automat
        template<> int32x4_t ternary<0x39>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(C, c1);
            const int32x4_t t1 = vorrq_s32(A, t0);
            const int32x4_t t2 = veorq_s32(B, t1);
            return t2;
        }
        // code=0x3a, function=(A ? not (B) : C), lowered=((B notand A) or (A notand C)), set=intel
        template<> int32x4_t ternary<0x3a>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, B);
            const int32x4_t t1 = vbicq_s32(C, A);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x3b, function=((not (A) and C) or (B xor 1)), lowered=((A notand C) or (B xor 1)), set=automat
        template<> int32x4_t ternary<0x3b>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x3c, function=(B xor A), lowered=(B xor A), set=intel
        template<> int32x4_t ternary<0x3c>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, A);
            return t0;
        }
        // code=0x3d, function=((A xor B) or ((A or C) xor 1)), lowered=((A xor B) or ((A or C) xor 1)), set=automat
        template<> int32x4_t ternary<0x3d>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, B);
            const int32x4_t t1 = vorrq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x3e, function=((not (A) and C) or (A xor B)), lowered=((A notand C) or (A xor B)), set=automat
        template<> int32x4_t ternary<0x3e>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, A);
            const int32x4_t t1 = veorq_s32(A, B);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x3f, function=(B nand A), lowered=((B and A) xor 1), set=intel
        template<> int32x4_t ternary<0x3f>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            return t1;
        }
        // code=0x40, function=((not (C) and A) and B), lowered=((C notand A) and B), set=automat
        template<> int32x4_t ternary<0x40>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, C);
            const int32x4_t t1 = vandq_s32(t0, B);
            return t1;
        }
        // code=0x41, function=(C nor (B xor A)), lowered=((C or (B xor A)) xor 1), set=intel
        template<> int32x4_t ternary<0x41>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, A);
            const int32x4_t t1 = vorrq_s32(C, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x42, function=((A xor C) and (B xor C)), lowered=((A xor C) and (B xor C)), set=automat
        template<> int32x4_t ternary<0x42>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t t1 = veorq_s32(B, C);
            const int32x4_t t2 = vandq_s32(t0, t1);
            return t2;
        }
        // code=0x43, function=(not ((A and C)) and (A xor (B xor 1))), lowered=((A and C) notand (A xor (B xor 1))), set=automat
        template<> int32x4_t ternary<0x43>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = vbicq_s32(t2, t0);
            return t3;
        }
        // code=0x44, function=(B and not (C)), lowered=(C notand B), set=intel
        template<> int32x4_t ternary<0x44>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, C);
            return t0;
        }
        // code=0x45, function=(not (C) and ((A xor 1) or B)), lowered=(C notand ((A xor 1) or B)), set=automat
        template<> int32x4_t ternary<0x45>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(A, c1);
            const int32x4_t t1 = vorrq_s32(t0, B);
            const int32x4_t t2 = vbicq_s32(t1, C);
            return t2;
        }
        // code=0x46, function=(not ((A and C)) and (B xor C)), lowered=((A and C) notand (B xor C)), set=automat
        template<> int32x4_t ternary<0x46>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t t1 = veorq_s32(B, C);
            const int32x4_t t2 = vbicq_s32(t1, t0);
            return t2;
        }
        // code=0x47, function=(B ? not (C) : not (A)), lowered=((C notand B) or (B notand (A xor 1))), set=intel
        template<> int32x4_t ternary<0x47>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(A, c1);
            const int32x4_t t2 = vbicq_s32(t1, B);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x48, function=(B and (A xor C)), lowered=(B and (A xor C)), set=intel
        template<> int32x4_t ternary<0x48>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t t1 = vandq_s32(B, t0);
            return t1;
        }
        // code=0x49, function=(B ? (A xor C) : (A nor C)), lowered=((B and (A xor C)) or (B notand ((A or C) xor 1))), set=intel
        template<> int32x4_t ternary<0x49>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t t1 = vandq_s32(B, t0);
            const int32x4_t t2 = vorrq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t3 = veorq_s32(t2, c1);
            const int32x4_t t4 = vbicq_s32(t3, B);
            const int32x4_t t5 = vorrq_s32(t1, t4);
            return t5;
        }
        // code=0x4a, function=((B or C) and (A xor C)), lowered=((B or C) and (A xor C)), set=automat
        template<> int32x4_t ternary<0x4a>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t t1 = veorq_s32(A, C);
            const int32x4_t t2 = vandq_s32(t0, t1);
            return t2;
        }
        // code=0x4b, function=(A xor ((B xor 1) or C)), lowered=(A xor ((B xor 1) or C)), set=automat
        template<> int32x4_t ternary<0x4b>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(B, c1);
            const int32x4_t t1 = vorrq_s32(t0, C);
            const int32x4_t t2 = veorq_s32(A, t1);
            return t2;
        }
        // code=0x4c, function=(B and (A nand C)), lowered=((A and C) notand B), set=intel
        template<> int32x4_t ternary<0x4c>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t t1 = vbicq_s32(B, t0);
            return t1;
        }
        // code=0x4d, function=(B ? (A nand C) : (A nor C)), lowered=(((A and C) notand B) or (B notand ((A or C) xor 1))), set=intel
        template<> int32x4_t ternary<0x4d>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t t1 = vbicq_s32(B, t0);
            const int32x4_t t2 = vorrq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t3 = veorq_s32(t2, c1);
            const int32x4_t t4 = vbicq_s32(t3, B);
            const int32x4_t t5 = vorrq_s32(t1, t4);
            return t5;
        }
        // code=0x4e, function=(C ? not (A) : B), lowered=((A notand C) or (C notand B)), set=intel
        template<> int32x4_t ternary<0x4e>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, A);
            const int32x4_t t1 = vbicq_s32(B, C);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x4f, function=((not (C) and B) or (A xor 1)), lowered=((C notand B) or (A xor 1)), set=automat
        template<> int32x4_t ternary<0x4f>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(A, c1);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x50, function=(A and not (C)), lowered=(C notand A), set=intel
        template<> int32x4_t ternary<0x50>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, C);
            return t0;
        }
        // code=0x51, function=(not (C) and (A or (B xor 1))), lowered=(C notand (A or (B xor 1))), set=automat
        template<> int32x4_t ternary<0x51>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(B, c1);
            const int32x4_t t1 = vorrq_s32(A, t0);
            const int32x4_t t2 = vbicq_s32(t1, C);
            return t2;
        }
        // code=0x52, function=(not ((B and C)) and (A xor C)), lowered=((B and C) notand (A xor C)), set=automat
        template<> int32x4_t ternary<0x52>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t t1 = veorq_s32(A, C);
            const int32x4_t t2 = vbicq_s32(t1, t0);
            return t2;
        }
        // code=0x53, function=(A ? not (C) : not (B)), lowered=((C notand A) or (A notand (B xor 1))), set=intel
        template<> int32x4_t ternary<0x53>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = vbicq_s32(t1, A);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x54, function=(not (C) and (A or B)), lowered=(C notand (A or B)), set=automat
        template<> int32x4_t ternary<0x54>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, B);
            const int32x4_t t1 = vbicq_s32(t0, C);
            return t1;
        }
        // code=0x55, function=not (C), lowered=(C xor 1), set=intel
        template<> int32x4_t ternary<0x55>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(C, c1);
            return t0;
        }
        // code=0x56, function=(C xor (B or A)), lowered=(C xor (B or A)), set=intel
        template<> int32x4_t ternary<0x56>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, A);
            const int32x4_t t1 = veorq_s32(C, t0);
            return t1;
        }
        // code=0x57, function=(C nand (B or A)), lowered=((C and (B or A)) xor 1), set=intel
        template<> int32x4_t ternary<0x57>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, A);
            const int32x4_t t1 = vandq_s32(C, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x58, function=((A or B) and (A xor C)), lowered=((A or B) and (A xor C)), set=automat
        template<> int32x4_t ternary<0x58>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, B);
            const int32x4_t t1 = veorq_s32(A, C);
            const int32x4_t t2 = vandq_s32(t0, t1);
            return t2;
        }
        // code=0x59, function=(C xor (A or (B xor 1))), lowered=(C xor (A or (B xor 1))), set=automat
        template<> int32x4_t ternary<0x59>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(B, c1);
            const int32x4_t t1 = vorrq_s32(A, t0);
            const int32x4_t t2 = veorq_s32(C, t1);
            return t2;
        }
        // code=0x5a, function=(C xor A), lowered=(C xor A), set=intel
        template<> int32x4_t ternary<0x5a>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(C, A);
            return t0;
        }
        // code=0x5b, function=((A xor C) or ((A or B) xor 1)), lowered=((A xor C) or ((A or B) xor 1)), set=automat
        template<> int32x4_t ternary<0x5b>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t t1 = vorrq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x5c, function=(A ? not (C) : B), lowered=((C notand A) or (A notand B)), set=intel
        template<> int32x4_t ternary<0x5c>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, C);
            const int32x4_t t1 = vbicq_s32(B, A);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x5d, function=((not (A) and B) or (C xor 1)), lowered=((A notand B) or (C xor 1)), set=automat
        template<> int32x4_t ternary<0x5d>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x5e, function=((not (C) and B) or (A xor C)), lowered=((C notand B) or (A xor C)), set=automat
        template<> int32x4_t ternary<0x5e>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, C);
            const int32x4_t t1 = veorq_s32(A, C);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x5f, function=(C nand A), lowered=((C and A) xor 1), set=intel
        template<> int32x4_t ternary<0x5f>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(C, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            return t1;
        }
        // code=0x60, function=(A and (B xor C)), lowered=(A and (B xor C)), set=intel
        template<> int32x4_t ternary<0x60>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t t1 = vandq_s32(A, t0);
            return t1;
        }
        // code=0x61, function=(A ? (B xor C) : (B nor C)), lowered=((A and (B xor C)) or (A notand ((B or C) xor 1))), set=intel
        template<> int32x4_t ternary<0x61>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t t1 = vandq_s32(A, t0);
            const int32x4_t t2 = vorrq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t3 = veorq_s32(t2, c1);
            const int32x4_t t4 = vbicq_s32(t3, A);
            const int32x4_t t5 = vorrq_s32(t1, t4);
            return t5;
        }
        // code=0x62, function=((A or C) and (B xor C)), lowered=((A or C) and (B xor C)), set=automat
        template<> int32x4_t ternary<0x62>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, C);
            const int32x4_t t1 = veorq_s32(B, C);
            const int32x4_t t2 = vandq_s32(t0, t1);
            return t2;
        }
        // code=0x63, function=(B xor ((A xor 1) or C)), lowered=(B xor ((A xor 1) or C)), set=automat
        template<> int32x4_t ternary<0x63>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(A, c1);
            const int32x4_t t1 = vorrq_s32(t0, C);
            const int32x4_t t2 = veorq_s32(B, t1);
            return t2;
        }
        // code=0x64, function=((A or B) and (B xor C)), lowered=((A or B) and (B xor C)), set=automat
        template<> int32x4_t ternary<0x64>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, B);
            const int32x4_t t1 = veorq_s32(B, C);
            const int32x4_t t2 = vandq_s32(t0, t1);
            return t2;
        }
        // code=0x65, function=(C xor ((A xor 1) or B)), lowered=(C xor ((A xor 1) or B)), set=automat
        template<> int32x4_t ternary<0x65>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(A, c1);
            const int32x4_t t1 = vorrq_s32(t0, B);
            const int32x4_t t2 = veorq_s32(C, t1);
            return t2;
        }
        // code=0x66, function=(C xor B), lowered=(C xor B), set=intel
        template<> int32x4_t ternary<0x66>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(C, B);
            return t0;
        }
        // code=0x67, function=((B xor C) or ((A or B) xor 1)), lowered=((B xor C) or ((A or B) xor 1)), set=automat
        template<> int32x4_t ternary<0x67>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t t1 = vorrq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x68, function=(A ? (B xor C) : (B and C)), lowered=((A and (B xor C)) or (A notand (B and C))), set=intel
        template<> int32x4_t ternary<0x68>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t t1 = vandq_s32(A, t0);
            const int32x4_t t2 = vandq_s32(B, C);
            const int32x4_t t3 = vbicq_s32(t2, A);
            const int32x4_t t4 = vorrq_s32(t1, t3);
            return t4;
        }
        // code=0x69, function=(A xnor (B xor C)), lowered=((A xor (B xor C)) xor 1), set=intel
        template<> int32x4_t ternary<0x69>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t t1 = veorq_s32(A, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x6a, function=(C xor (B and A)), lowered=(C xor (B and A)), set=intel
        template<> int32x4_t ternary<0x6a>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, A);
            const int32x4_t t1 = veorq_s32(C, t0);
            return t1;
        }
        // code=0x6b, function=((not (A) and C) or ((A xor 1) xor (B xor C))), lowered=((A notand C) or ((A xor 1) xor (B xor C))), set=automat
        template<> int32x4_t ternary<0x6b>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(A, c1);
            const int32x4_t t2 = veorq_s32(B, C);
            const int32x4_t t3 = veorq_s32(t1, t2);
            const int32x4_t t4 = vorrq_s32(t0, t3);
            return t4;
        }
        // code=0x6c, function=(B xor (A and C)), lowered=(B xor (A and C)), set=intel
        template<> int32x4_t ternary<0x6c>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t t1 = veorq_s32(B, t0);
            return t1;
        }
        // code=0x6d, function=((not (A) and B) or ((A xor 1) xor (B xor C))), lowered=((A notand B) or ((A xor 1) xor (B xor C))), set=automat
        template<> int32x4_t ternary<0x6d>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(A, c1);
            const int32x4_t t2 = veorq_s32(B, C);
            const int32x4_t t3 = veorq_s32(t1, t2);
            const int32x4_t t4 = vorrq_s32(t0, t3);
            return t4;
        }
        // code=0x6e, function=((not (A) and B) or (B xor C)), lowered=((A notand B) or (B xor C)), set=automat
        template<> int32x4_t ternary<0x6e>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, A);
            const int32x4_t t1 = veorq_s32(B, C);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x6f, function=((B xor C) or (A xor 1)), lowered=((B xor C) or (A xor 1)), set=automat
        template<> int32x4_t ternary<0x6f>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(A, c1);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x70, function=(A and (B nand C)), lowered=((B and C) notand A), set=intel
        template<> int32x4_t ternary<0x70>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t t1 = vbicq_s32(A, t0);
            return t1;
        }
        // code=0x71, function=((B nor C) or (A and (B xor C))), lowered=(((B or C) xor 1) or (A and (B xor C))), set=optimized
        template<> int32x4_t ternary<0x71>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            const int32x4_t t2 = veorq_s32(B, C);
            const int32x4_t t3 = vandq_s32(A, t2);
            const int32x4_t t4 = vorrq_s32(t1, t3);
            return t4;
        }
        // code=0x72, function=(C ? not (B) : A), lowered=((B notand C) or (C notand A)), set=intel
        template<> int32x4_t ternary<0x72>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, B);
            const int32x4_t t1 = vbicq_s32(A, C);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x73, function=((not (C) and A) or (B xor 1)), lowered=((C notand A) or (B xor 1)), set=automat
        template<> int32x4_t ternary<0x73>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x74, function=(B ? not (C) : A), lowered=((C notand B) or (B notand A)), set=intel
        template<> int32x4_t ternary<0x74>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, C);
            const int32x4_t t1 = vbicq_s32(A, B);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x75, function=((not (B) and A) or (C xor 1)), lowered=((B notand A) or (C xor 1)), set=automat
        template<> int32x4_t ternary<0x75>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x76, function=((not (B) and A) or (B xor C)), lowered=((B notand A) or (B xor C)), set=automat
        template<> int32x4_t ternary<0x76>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, B);
            const int32x4_t t1 = veorq_s32(B, C);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x77, function=(C nand B), lowered=((C and B) xor 1), set=intel
        template<> int32x4_t ternary<0x77>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(C, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            return t1;
        }
        // code=0x78, function=(A xor (B and C)), lowered=(A xor (B and C)), set=intel
        template<> int32x4_t ternary<0x78>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t t1 = veorq_s32(A, t0);
            return t1;
        }
        // code=0x79, function=((not (B) and A) or ((B xor 1) xor (A xor C))), lowered=((B notand A) or ((B xor 1) xor (A xor C))), set=automat
        template<> int32x4_t ternary<0x79>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = veorq_s32(A, C);
            const int32x4_t t3 = veorq_s32(t1, t2);
            const int32x4_t t4 = vorrq_s32(t0, t3);
            return t4;
        }
        // code=0x7a, function=((not (B) and A) or (A xor C)), lowered=((B notand A) or (A xor C)), set=automat
        template<> int32x4_t ternary<0x7a>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, B);
            const int32x4_t t1 = veorq_s32(A, C);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x7b, function=((A xor C) or (B xor 1)), lowered=((A xor C) or (B xor 1)), set=automat
        template<> int32x4_t ternary<0x7b>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x7c, function=((not (C) and A) or (A xor B)), lowered=((C notand A) or (A xor B)), set=automat
        template<> int32x4_t ternary<0x7c>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, C);
            const int32x4_t t1 = veorq_s32(A, B);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x7d, function=((A xor B) or (C xor 1)), lowered=((A xor B) or (C xor 1)), set=automat
        template<> int32x4_t ternary<0x7d>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x7e, function=((A xor B) or (A xor C)), lowered=((A xor B) or (A xor C)), set=automat
        template<> int32x4_t ternary<0x7e>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, B);
            const int32x4_t t1 = veorq_s32(A, C);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x7f, function=(((A and B) and C) xor 1), lowered=(((A and B) and C) xor 1), set=automat
        template<> int32x4_t ternary<0x7f>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, B);
            const int32x4_t t1 = vandq_s32(t0, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x80, function=(A and (B and C)), lowered=(A and (B and C)), set=optimized
        template<> int32x4_t ternary<0x80>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t t1 = vandq_s32(A, t0);
            return t1;
        }
        // code=0x81, function=(not ((A xor C)) and (A xor (B xor 1))), lowered=((A xor C) notand (A xor (B xor 1))), set=automat
        template<> int32x4_t ternary<0x81>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = vbicq_s32(t2, t0);
            return t3;
        }
        // code=0x82, function=(C and (B xnor A)), lowered=((B xor A) notand C), set=intel
        template<> int32x4_t ternary<0x82>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, A);
            const int32x4_t t1 = vbicq_s32(C, t0);
            return t1;
        }
        // code=0x83, function=(not ((A xor B)) and ((A xor 1) or C)), lowered=((A xor B) notand ((A xor 1) or C)), set=automat
        template<> int32x4_t ternary<0x83>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(A, c1);
            const int32x4_t t2 = vorrq_s32(t1, C);
            const int32x4_t t3 = vbicq_s32(t2, t0);
            return t3;
        }
        // code=0x84, function=(B and (A xnor C)), lowered=((A xor C) notand B), set=intel
        template<> int32x4_t ternary<0x84>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t t1 = vbicq_s32(B, t0);
            return t1;
        }
        // code=0x85, function=(not ((A xor C)) and (B or (C xor 1))), lowered=((A xor C) notand (B or (C xor 1))), set=automat
        template<> int32x4_t ternary<0x85>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = vorrq_s32(B, t1);
            const int32x4_t t3 = vbicq_s32(t2, t0);
            return t3;
        }
        // code=0x86, function=((B or C) and (C xor (A xor B))), lowered=((B or C) and (C xor (A xor B))), set=automat
        template<> int32x4_t ternary<0x86>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t t1 = veorq_s32(A, B);
            const int32x4_t t2 = veorq_s32(C, t1);
            const int32x4_t t3 = vandq_s32(t0, t2);
            return t3;
        }
        // code=0x87, function=(A xnor (B and C)), lowered=((A xor (B and C)) xor 1), set=intel
        template<> int32x4_t ternary<0x87>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t t1 = veorq_s32(A, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x88, function=(C and B), lowered=(C and B), set=intel
        template<> int32x4_t ternary<0x88>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(C, B);
            return t0;
        }
        // code=0x89, function=(not ((B xor C)) and ((A xor 1) or B)), lowered=((B xor C) notand ((A xor 1) or B)), set=automat
        template<> int32x4_t ternary<0x89>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(A, c1);
            const int32x4_t t2 = vorrq_s32(t1, B);
            const int32x4_t t3 = vbicq_s32(t2, t0);
            return t3;
        }
        // code=0x8a, function=(not ((not (B) and A)) and C), lowered=((B notand A) notand C), set=automat
        template<> int32x4_t ternary<0x8a>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, B);
            const int32x4_t t1 = vbicq_s32(C, t0);
            return t1;
        }
        // code=0x8b, function=(B ? C : not (A)), lowered=((B and C) or (B notand (A xor 1))), set=intel
        template<> int32x4_t ternary<0x8b>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(A, c1);
            const int32x4_t t2 = vbicq_s32(t1, B);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x8c, function=(not ((not (C) and A)) and B), lowered=((C notand A) notand B), set=automat
        template<> int32x4_t ternary<0x8c>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, C);
            const int32x4_t t1 = vbicq_s32(B, t0);
            return t1;
        }
        // code=0x8d, function=(C ? B : not (A)), lowered=((C and B) or (C notand (A xor 1))), set=intel
        template<> int32x4_t ternary<0x8d>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(C, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(A, c1);
            const int32x4_t t2 = vbicq_s32(t1, C);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x8e, function=((B and C) or (not (A) and (B xor C))), lowered=((B and C) or (A notand (B xor C))), set=optimized
        template<> int32x4_t ternary<0x8e>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t t1 = veorq_s32(B, C);
            const int32x4_t t2 = vbicq_s32(t1, A);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x8f, function=((B and C) or (A xor 1)), lowered=((B and C) or (A xor 1)), set=automat
        template<> int32x4_t ternary<0x8f>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(A, c1);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0x90, function=(A and (B xnor C)), lowered=((B xor C) notand A), set=intel
        template<> int32x4_t ternary<0x90>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t t1 = vbicq_s32(A, t0);
            return t1;
        }
        // code=0x91, function=(not ((B xor C)) and (A or (B xor 1))), lowered=((B xor C) notand (A or (B xor 1))), set=automat
        template<> int32x4_t ternary<0x91>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = vorrq_s32(A, t1);
            const int32x4_t t3 = vbicq_s32(t2, t0);
            return t3;
        }
        // code=0x92, function=((A or C) and (C xor (A xor B))), lowered=((A or C) and (C xor (A xor B))), set=automat
        template<> int32x4_t ternary<0x92>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, C);
            const int32x4_t t1 = veorq_s32(A, B);
            const int32x4_t t2 = veorq_s32(C, t1);
            const int32x4_t t3 = vandq_s32(t0, t2);
            return t3;
        }
        // code=0x93, function=(B xnor (A and C)), lowered=((B xor (A and C)) xor 1), set=intel
        template<> int32x4_t ternary<0x93>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t t1 = veorq_s32(B, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x94, function=((A or B) and (B xor (A xor C))), lowered=((A or B) and (B xor (A xor C))), set=automat
        template<> int32x4_t ternary<0x94>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, B);
            const int32x4_t t1 = veorq_s32(A, C);
            const int32x4_t t2 = veorq_s32(B, t1);
            const int32x4_t t3 = vandq_s32(t0, t2);
            return t3;
        }
        // code=0x95, function=(C xnor (B and A)), lowered=((C xor (B and A)) xor 1), set=intel
        template<> int32x4_t ternary<0x95>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, A);
            const int32x4_t t1 = veorq_s32(C, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0x96, function=(A xor (B xor C)), lowered=(A xor (B xor C)), set=intel
        template<> int32x4_t ternary<0x96>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t t1 = veorq_s32(A, t0);
            return t1;
        }
        // code=0x97, function=(A ? (B xnor C) : (B nand C)), lowered=(((B xor C) notand A) or (A notand ((B and C) xor 1))), set=intel
        template<> int32x4_t ternary<0x97>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t t1 = vbicq_s32(A, t0);
            const int32x4_t t2 = vandq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t3 = veorq_s32(t2, c1);
            const int32x4_t t4 = vbicq_s32(t3, A);
            const int32x4_t t5 = vorrq_s32(t1, t4);
            return t5;
        }
        // code=0x98, function=(not ((B xor C)) and (A or B)), lowered=((B xor C) notand (A or B)), set=automat
        template<> int32x4_t ternary<0x98>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t t1 = vorrq_s32(A, B);
            const int32x4_t t2 = vbicq_s32(t1, t0);
            return t2;
        }
        // code=0x99, function=(C xnor B), lowered=((C xor B) xor 1), set=intel
        template<> int32x4_t ternary<0x99>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(C, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            return t1;
        }
        // code=0x9a, function=((not (B) and A) xor C), lowered=((B notand A) xor C), set=automat
        template<> int32x4_t ternary<0x9a>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, B);
            const int32x4_t t1 = veorq_s32(t0, C);
            return t1;
        }
        // code=0x9b, function=((not (A) and C) or (B xor (C xor 1))), lowered=((A notand C) or (B xor (C xor 1))), set=automat
        template<> int32x4_t ternary<0x9b>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = veorq_s32(B, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x9c, function=((not (C) and A) xor B), lowered=((C notand A) xor B), set=automat
        template<> int32x4_t ternary<0x9c>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, C);
            const int32x4_t t1 = veorq_s32(t0, B);
            return t1;
        }
        // code=0x9d, function=((not (A) and B) or (B xor (C xor 1))), lowered=((A notand B) or (B xor (C xor 1))), set=automat
        template<> int32x4_t ternary<0x9d>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = veorq_s32(B, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x9e, function=((B and C) or (C xor (A xor B))), lowered=((B and C) or (C xor (A xor B))), set=automat
        template<> int32x4_t ternary<0x9e>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t t1 = veorq_s32(A, B);
            const int32x4_t t2 = veorq_s32(C, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0x9f, function=(A nand (B xor C)), lowered=((A and (B xor C)) xor 1), set=intel
        template<> int32x4_t ternary<0x9f>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t t1 = vandq_s32(A, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0xa0, function=(C and A), lowered=(C and A), set=intel
        template<> int32x4_t ternary<0xa0>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(C, A);
            return t0;
        }
        // code=0xa1, function=(not ((A xor C)) and (A or (B xor 1))), lowered=((A xor C) notand (A or (B xor 1))), set=automat
        template<> int32x4_t ternary<0xa1>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = vorrq_s32(A, t1);
            const int32x4_t t3 = vbicq_s32(t2, t0);
            return t3;
        }
        // code=0xa2, function=(not ((not (A) and B)) and C), lowered=((A notand B) notand C), set=automat
        template<> int32x4_t ternary<0xa2>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, A);
            const int32x4_t t1 = vbicq_s32(C, t0);
            return t1;
        }
        // code=0xa3, function=(A ? C : not (B)), lowered=((A and C) or (A notand (B xor 1))), set=intel
        template<> int32x4_t ternary<0xa3>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = vbicq_s32(t1, A);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xa4, function=(not ((A xor C)) and (A or B)), lowered=((A xor C) notand (A or B)), set=automat
        template<> int32x4_t ternary<0xa4>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t t1 = vorrq_s32(A, B);
            const int32x4_t t2 = vbicq_s32(t1, t0);
            return t2;
        }
        // code=0xa5, function=(C xnor A), lowered=((C xor A) xor 1), set=intel
        template<> int32x4_t ternary<0xa5>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(C, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            return t1;
        }
        // code=0xa6, function=((not (A) and B) xor C), lowered=((A notand B) xor C), set=automat
        template<> int32x4_t ternary<0xa6>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, A);
            const int32x4_t t1 = veorq_s32(t0, C);
            return t1;
        }
        // code=0xa7, function=((not (B) and C) or (A xor (C xor 1))), lowered=((B notand C) or (A xor (C xor 1))), set=automat
        template<> int32x4_t ternary<0xa7>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xa8, function=(C and (A or B)), lowered=(C and (A or B)), set=intel
        template<> int32x4_t ternary<0xa8>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, B);
            const int32x4_t t1 = vandq_s32(C, t0);
            return t1;
        }
        // code=0xa9, function=(C xnor (B or A)), lowered=((C xor (B or A)) xor 1), set=intel
        template<> int32x4_t ternary<0xa9>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, A);
            const int32x4_t t1 = veorq_s32(C, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0xaa, function=C, lowered=C, set=intel
        template<> int32x4_t ternary<0xaa>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            return C;
        }
        // code=0xab, function=(C or (B nor A)), lowered=(C or ((B or A) xor 1)), set=intel
        template<> int32x4_t ternary<0xab>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            const int32x4_t t2 = vorrq_s32(C, t1);
            return t2;
        }
        // code=0xac, function=(A ? C : B), lowered=((A and C) or (A notand B)), set=intel
        template<> int32x4_t ternary<0xac>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t t1 = vbicq_s32(B, A);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0xad, function=((B and C) or (A xor (C xor 1))), lowered=((B and C) or (A xor (C xor 1))), set=automat
        template<> int32x4_t ternary<0xad>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xae, function=((not (A) and B) or C), lowered=((A notand B) or C), set=automat
        template<> int32x4_t ternary<0xae>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, A);
            const int32x4_t t1 = vorrq_s32(t0, C);
            return t1;
        }
        // code=0xaf, function=(C or not (A)), lowered=(C or (A xor 1)), set=intel
        template<> int32x4_t ternary<0xaf>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(A, c1);
            const int32x4_t t1 = vorrq_s32(C, t0);
            return t1;
        }
        // code=0xb0, function=(not ((not (C) and B)) and A), lowered=((C notand B) notand A), set=automat
        template<> int32x4_t ternary<0xb0>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, C);
            const int32x4_t t1 = vbicq_s32(A, t0);
            return t1;
        }
        // code=0xb1, function=(C ? A : not (B)), lowered=((C and A) or (C notand (B xor 1))), set=intel
        template<> int32x4_t ternary<0xb1>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(C, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = vbicq_s32(t1, C);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xb2, function=(B ? (A and C) : (A or C)), lowered=((B and (A and C)) or (B notand (A or C))), set=intel
        template<> int32x4_t ternary<0xb2>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t t1 = vandq_s32(B, t0);
            const int32x4_t t2 = vorrq_s32(A, C);
            const int32x4_t t3 = vbicq_s32(t2, B);
            const int32x4_t t4 = vorrq_s32(t1, t3);
            return t4;
        }
        // code=0xb3, function=((A and C) or (B xor 1)), lowered=((A and C) or (B xor 1)), set=automat
        template<> int32x4_t ternary<0xb3>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0xb4, function=((not (C) and B) xor A), lowered=((C notand B) xor A), set=automat
        template<> int32x4_t ternary<0xb4>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, C);
            const int32x4_t t1 = veorq_s32(t0, A);
            return t1;
        }
        // code=0xb5, function=((not (B) and A) or (A xor (C xor 1))), lowered=((B notand A) or (A xor (C xor 1))), set=automat
        template<> int32x4_t ternary<0xb5>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xb6, function=((A and C) or (C xor (A xor B))), lowered=((A and C) or (C xor (A xor B))), set=automat
        template<> int32x4_t ternary<0xb6>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t t1 = veorq_s32(A, B);
            const int32x4_t t2 = veorq_s32(C, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xb7, function=(B nand (A xor C)), lowered=((B and (A xor C)) xor 1), set=intel
        template<> int32x4_t ternary<0xb7>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t t1 = vandq_s32(B, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0xb8, function=(B ? C : A), lowered=((B and C) or (B notand A)), set=intel
        template<> int32x4_t ternary<0xb8>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t t1 = vbicq_s32(A, B);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0xb9, function=((A and C) or (B xor (C xor 1))), lowered=((A and C) or (B xor (C xor 1))), set=automat
        template<> int32x4_t ternary<0xb9>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = veorq_s32(B, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xba, function=((not (B) and A) or C), lowered=((B notand A) or C), set=automat
        template<> int32x4_t ternary<0xba>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, B);
            const int32x4_t t1 = vorrq_s32(t0, C);
            return t1;
        }
        // code=0xbb, function=(C or not (B)), lowered=(C or (B xor 1)), set=intel
        template<> int32x4_t ternary<0xbb>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(B, c1);
            const int32x4_t t1 = vorrq_s32(C, t0);
            return t1;
        }
        // code=0xbc, function=((A and C) or (A xor B)), lowered=((A and C) or (A xor B)), set=automat
        template<> int32x4_t ternary<0xbc>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t t1 = veorq_s32(A, B);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0xbd, function=((A xor B) or (A xor (C xor 1))), lowered=((A xor B) or (A xor (C xor 1))), set=automat
        template<> int32x4_t ternary<0xbd>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xbe, function=(C or (B xor A)), lowered=(C or (B xor A)), set=intel
        template<> int32x4_t ternary<0xbe>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, A);
            const int32x4_t t1 = vorrq_s32(C, t0);
            return t1;
        }
        // code=0xbf, function=(C or (B nand A)), lowered=(C or ((B and A) xor 1)), set=intel
        template<> int32x4_t ternary<0xbf>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            const int32x4_t t2 = vorrq_s32(C, t1);
            return t2;
        }
        // code=0xc0, function=(B and A), lowered=(B and A), set=intel
        template<> int32x4_t ternary<0xc0>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, A);
            return t0;
        }
        // code=0xc1, function=(not ((A xor B)) and (A or (C xor 1))), lowered=((A xor B) notand (A or (C xor 1))), set=automat
        template<> int32x4_t ternary<0xc1>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = vorrq_s32(A, t1);
            const int32x4_t t3 = vbicq_s32(t2, t0);
            return t3;
        }
        // code=0xc2, function=(not ((A xor B)) and (A or C)), lowered=((A xor B) notand (A or C)), set=automat
        template<> int32x4_t ternary<0xc2>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, B);
            const int32x4_t t1 = vorrq_s32(A, C);
            const int32x4_t t2 = vbicq_s32(t1, t0);
            return t2;
        }
        // code=0xc3, function=(B xnor A), lowered=((B xor A) xor 1), set=intel
        template<> int32x4_t ternary<0xc3>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            return t1;
        }
        // code=0xc4, function=(not ((not (A) and C)) and B), lowered=((A notand C) notand B), set=automat
        template<> int32x4_t ternary<0xc4>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, A);
            const int32x4_t t1 = vbicq_s32(B, t0);
            return t1;
        }
        // code=0xc5, function=(A ? B : not (C)), lowered=((A and B) or (A notand (C xor 1))), set=intel
        template<> int32x4_t ternary<0xc5>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = vbicq_s32(t1, A);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xc6, function=((not (A) and C) xor B), lowered=((A notand C) xor B), set=automat
        template<> int32x4_t ternary<0xc6>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, A);
            const int32x4_t t1 = veorq_s32(t0, B);
            return t1;
        }
        // code=0xc7, function=((not (C) and B) or (A xor (B xor 1))), lowered=((C notand B) or (A xor (B xor 1))), set=automat
        template<> int32x4_t ternary<0xc7>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xc8, function=(B and (A or C)), lowered=(B and (A or C)), set=intel
        template<> int32x4_t ternary<0xc8>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, C);
            const int32x4_t t1 = vandq_s32(B, t0);
            return t1;
        }
        // code=0xc9, function=(B xnor (A or C)), lowered=((B xor (A or C)) xor 1), set=intel
        template<> int32x4_t ternary<0xc9>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, C);
            const int32x4_t t1 = veorq_s32(B, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0xca, function=(A ? B : C), lowered=((A and B) or (A notand C)), set=intel
        template<> int32x4_t ternary<0xca>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, B);
            const int32x4_t t1 = vbicq_s32(C, A);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0xcb, function=((B and C) or (A xor (B xor 1))), lowered=((B and C) or (A xor (B xor 1))), set=automat
        template<> int32x4_t ternary<0xcb>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xcc, function=B, lowered=B, set=intel
        template<> int32x4_t ternary<0xcc>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            return B;
        }
        // code=0xcd, function=(B or (A nor C)), lowered=(B or ((A or C) xor 1)), set=intel
        template<> int32x4_t ternary<0xcd>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            const int32x4_t t2 = vorrq_s32(B, t1);
            return t2;
        }
        // code=0xce, function=((not (A) and C) or B), lowered=((A notand C) or B), set=automat
        template<> int32x4_t ternary<0xce>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, A);
            const int32x4_t t1 = vorrq_s32(t0, B);
            return t1;
        }
        // code=0xcf, function=(B or not (A)), lowered=(B or (A xor 1)), set=intel
        template<> int32x4_t ternary<0xcf>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(A, c1);
            const int32x4_t t1 = vorrq_s32(B, t0);
            return t1;
        }
        // code=0xd0, function=(not ((not (B) and C)) and A), lowered=((B notand C) notand A), set=automat
        template<> int32x4_t ternary<0xd0>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, B);
            const int32x4_t t1 = vbicq_s32(A, t0);
            return t1;
        }
        // code=0xd1, function=((B nor C) or (A and B)), lowered=(((B or C) xor 1) or (A and B)), set=optimized
        template<> int32x4_t ternary<0xd1>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            const int32x4_t t2 = vandq_s32(A, B);
            const int32x4_t t3 = vorrq_s32(t1, t2);
            return t3;
        }
        // code=0xd2, function=((not (B) and C) xor A), lowered=((B notand C) xor A), set=automat
        template<> int32x4_t ternary<0xd2>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, B);
            const int32x4_t t1 = veorq_s32(t0, A);
            return t1;
        }
        // code=0xd3, function=((not (C) and A) or (A xor (B xor 1))), lowered=((C notand A) or (A xor (B xor 1))), set=automat
        template<> int32x4_t ternary<0xd3>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xd4, function=((B and not (C)) or (A and (B xnor C))), lowered=((C notand B) or ((B xor C) notand A)), set=optimized
        template<> int32x4_t ternary<0xd4>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, C);
            const int32x4_t t1 = veorq_s32(B, C);
            const int32x4_t t2 = vbicq_s32(A, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xd5, function=((A and B) or (C xor 1)), lowered=((A and B) or (C xor 1)), set=automat
        template<> int32x4_t ternary<0xd5>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0xd6, function=((A and B) or (B xor (A xor C))), lowered=((A and B) or (B xor (A xor C))), set=automat
        template<> int32x4_t ternary<0xd6>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, B);
            const int32x4_t t1 = veorq_s32(A, C);
            const int32x4_t t2 = veorq_s32(B, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xd7, function=(C nand (B xor A)), lowered=((C and (B xor A)) xor 1), set=intel
        template<> int32x4_t ternary<0xd7>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, A);
            const int32x4_t t1 = vandq_s32(C, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0xd8, function=(C ? B : A), lowered=((C and B) or (C notand A)), set=intel
        template<> int32x4_t ternary<0xd8>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(C, B);
            const int32x4_t t1 = vbicq_s32(A, C);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0xd9, function=((A and B) or (B xor (C xor 1))), lowered=((A and B) or (B xor (C xor 1))), set=automat
        template<> int32x4_t ternary<0xd9>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = veorq_s32(B, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xda, function=((A and B) or (A xor C)), lowered=((A and B) or (A xor C)), set=automat
        template<> int32x4_t ternary<0xda>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, B);
            const int32x4_t t1 = veorq_s32(A, C);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0xdb, function=((A xor C) or (A xor (B xor 1))), lowered=((A xor C) or (A xor (B xor 1))), set=automat
        template<> int32x4_t ternary<0xdb>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xdc, function=((not (C) and A) or B), lowered=((C notand A) or B), set=automat
        template<> int32x4_t ternary<0xdc>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(A, C);
            const int32x4_t t1 = vorrq_s32(t0, B);
            return t1;
        }
        // code=0xdd, function=(B or not (C)), lowered=(B or (C xor 1)), set=intel
        template<> int32x4_t ternary<0xdd>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(C, c1);
            const int32x4_t t1 = vorrq_s32(B, t0);
            return t1;
        }
        // code=0xde, function=(B or (A xor C)), lowered=(B or (A xor C)), set=intel
        template<> int32x4_t ternary<0xde>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t t1 = vorrq_s32(B, t0);
            return t1;
        }
        // code=0xdf, function=(B or (A nand C)), lowered=(B or ((A and C) xor 1)), set=intel
        template<> int32x4_t ternary<0xdf>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            const int32x4_t t2 = vorrq_s32(B, t1);
            return t2;
        }
        // code=0xe0, function=(A and (B or C)), lowered=(A and (B or C)), set=intel
        template<> int32x4_t ternary<0xe0>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t t1 = vandq_s32(A, t0);
            return t1;
        }
        // code=0xe1, function=(A xnor (B or C)), lowered=((A xor (B or C)) xor 1), set=intel
        template<> int32x4_t ternary<0xe1>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t t1 = veorq_s32(A, t0);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t2 = veorq_s32(t1, c1);
            return t2;
        }
        // code=0xe2, function=(B ? A : C), lowered=((B and A) or (B notand C)), set=intel
        template<> int32x4_t ternary<0xe2>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, A);
            const int32x4_t t1 = vbicq_s32(C, B);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0xe3, function=((A and C) or (A xor (B xor 1))), lowered=((A and C) or (A xor (B xor 1))), set=automat
        template<> int32x4_t ternary<0xe3>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xe4, function=(C ? A : B), lowered=((C and A) or (C notand B)), set=intel
        template<> int32x4_t ternary<0xe4>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(C, A);
            const int32x4_t t1 = vbicq_s32(B, C);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0xe5, function=((A and B) or (A xor (C xor 1))), lowered=((A and B) or (A xor (C xor 1))), set=automat
        template<> int32x4_t ternary<0xe5>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xe6, function=((A and B) or (B xor C)), lowered=((A and B) or (B xor C)), set=automat
        template<> int32x4_t ternary<0xe6>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, B);
            const int32x4_t t1 = veorq_s32(B, C);
            const int32x4_t t2 = vorrq_s32(t0, t1);
            return t2;
        }
        // code=0xe7, function=((B xor C) or (A xor (B xor 1))), lowered=((B xor C) or (A xor (B xor 1))), set=automat
        template<> int32x4_t ternary<0xe7>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(B, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xe8, function=((B and C) or (A and (B xor C))), lowered=((B and C) or (A and (B xor C))), set=optimized
        template<> int32x4_t ternary<0xe8>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t t1 = veorq_s32(B, C);
            const int32x4_t t2 = vandq_s32(A, t1);
            const int32x4_t t3 = vorrq_s32(t0, t2);
            return t3;
        }
        // code=0xe9, function=((A and B) or (B xor (A xor (C xor 1)))), lowered=((A and B) or (B xor (A xor (C xor 1)))), set=automat
        template<> int32x4_t ternary<0xe9>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, B);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(C, c1);
            const int32x4_t t2 = veorq_s32(A, t1);
            const int32x4_t t3 = veorq_s32(B, t2);
            const int32x4_t t4 = vorrq_s32(t0, t3);
            return t4;
        }
        // code=0xea, function=(C or (B and A)), lowered=(C or (B and A)), set=intel
        template<> int32x4_t ternary<0xea>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, A);
            const int32x4_t t1 = vorrq_s32(C, t0);
            return t1;
        }
        // code=0xeb, function=(C or (B xnor A)), lowered=(C or ((B xor A) xor 1)), set=intel
        template<> int32x4_t ternary<0xeb>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, A);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            const int32x4_t t2 = vorrq_s32(C, t1);
            return t2;
        }
        // code=0xec, function=(B or (A and C)), lowered=(B or (A and C)), set=intel
        template<> int32x4_t ternary<0xec>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(A, C);
            const int32x4_t t1 = vorrq_s32(B, t0);
            return t1;
        }
        // code=0xed, function=(B or (A xnor C)), lowered=(B or ((A xor C) xor 1)), set=intel
        template<> int32x4_t ternary<0xed>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(A, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            const int32x4_t t2 = vorrq_s32(B, t1);
            return t2;
        }
        // code=0xee, function=(C or B), lowered=(C or B), set=intel
        template<> int32x4_t ternary<0xee>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(C, B);
            return t0;
        }
        // code=0xef, function=(B or ((A xor 1) or C)), lowered=(B or ((A xor 1) or C)), set=automat
        template<> int32x4_t ternary<0xef>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(A, c1);
            const int32x4_t t1 = vorrq_s32(t0, C);
            const int32x4_t t2 = vorrq_s32(B, t1);
            return t2;
        }
        // code=0xf0, function=A, lowered=A, set=intel
        template<> int32x4_t ternary<0xf0>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            return A;
        }
        // code=0xf1, function=(A or (B nor C)), lowered=(A or ((B or C) xor 1)), set=intel
        template<> int32x4_t ternary<0xf1>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            const int32x4_t t2 = vorrq_s32(A, t1);
            return t2;
        }
        // code=0xf2, function=((not (B) and C) or A), lowered=((B notand C) or A), set=automat
        template<> int32x4_t ternary<0xf2>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(C, B);
            const int32x4_t t1 = vorrq_s32(t0, A);
            return t1;
        }
        // code=0xf3, function=(A or not (B)), lowered=(A or (B xor 1)), set=intel
        template<> int32x4_t ternary<0xf3>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(B, c1);
            const int32x4_t t1 = vorrq_s32(A, t0);
            return t1;
        }
        // code=0xf4, function=((not (C) and B) or A), lowered=((C notand B) or A), set=automat
        template<> int32x4_t ternary<0xf4>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vbicq_s32(B, C);
            const int32x4_t t1 = vorrq_s32(t0, A);
            return t1;
        }
        // code=0xf5, function=(A or not (C)), lowered=(A or (C xor 1)), set=intel
        template<> int32x4_t ternary<0xf5>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(C, c1);
            const int32x4_t t1 = vorrq_s32(A, t0);
            return t1;
        }
        // code=0xf6, function=(A or (B xor C)), lowered=(A or (B xor C)), set=intel
        template<> int32x4_t ternary<0xf6>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t t1 = vorrq_s32(A, t0);
            return t1;
        }
        // code=0xf7, function=(A or (B nand C)), lowered=(A or ((B and C) xor 1)), set=intel
        template<> int32x4_t ternary<0xf7>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            const int32x4_t t2 = vorrq_s32(A, t1);
            return t2;
        }
        // code=0xf8, function=(A or (B and C)), lowered=(A or (B and C)), set=intel
        template<> int32x4_t ternary<0xf8>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vandq_s32(B, C);
            const int32x4_t t1 = vorrq_s32(A, t0);
            return t1;
        }
        // code=0xf9, function=(A or (B xnor C)), lowered=(A or ((B xor C) xor 1)), set=intel
        template<> int32x4_t ternary<0xf9>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = veorq_s32(B, C);
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t1 = veorq_s32(t0, c1);
            const int32x4_t t2 = vorrq_s32(A, t1);
            return t2;
        }
        // code=0xfa, function=(C or A), lowered=(C or A), set=intel
        template<> int32x4_t ternary<0xfa>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(C, A);
            return t0;
        }
        // code=0xfb, function=(A or ((B xor 1) or C)), lowered=(A or ((B xor 1) or C)), set=automat
        template<> int32x4_t ternary<0xfb>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(B, c1);
            const int32x4_t t1 = vorrq_s32(t0, C);
            const int32x4_t t2 = vorrq_s32(A, t1);
            return t2;
        }
        // code=0xfc, function=(B or A), lowered=(B or A), set=intel
        template<> int32x4_t ternary<0xfc>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, A);
            return t0;
        }
        // code=0xfd, function=(A or (B or (C xor 1))), lowered=(A or (B or (C xor 1))), set=automat
        template<> int32x4_t ternary<0xfd>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            const int32x4_t t0 = veorq_s32(C, c1);
            const int32x4_t t1 = vorrq_s32(B, t0);
            const int32x4_t t2 = vorrq_s32(A, t1);
            return t2;
        }
        // code=0xfe, function=(A or (B or C)), lowered=(A or (B or C)), set=intel
        template<> int32x4_t ternary<0xfe>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t t0 = vorrq_s32(B, C);
            const int32x4_t t1 = vorrq_s32(A, t0);
            return t1;
        }
        // code=0xff, function=1, lowered=1, set=intel
        template<> int32x4_t ternary<0xff>(const int32x4_t A, const int32x4_t B, const int32x4_t C) {
            const int32x4_t c1 = vdupq_n_s32(-1);
            return c1;
        }

    } // namespace neon

} // namespace ternarylogic

// eof
