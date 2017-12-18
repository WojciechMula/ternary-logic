// Generated automatically, please do not edit
#pragma once
#include <cstdint>

namespace ternarylogic {

    namespace x86_64 {

        template<unsigned k> uint64_t ternary(const uint64_t, const uint64_t, const uint64_t) {
            static_assert(k < 256, "Unspecified ternary function");
            return 0;
        } 

        // code=0x00, function=0, lowered=0, set=intel
        template<> uint64_t ternary<0x00>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t c0 = 0;
            return c0;
        }
        // code=0x01, function=(A nor (B or C)), lowered=not ((A or (B or C))), set=intel
        template<> uint64_t ternary<0x01>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = A | t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0x02, function=(C and (B nor A)), lowered=(C and not ((B or A))), set=intel
        template<> uint64_t ternary<0x02>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | A;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = C & t1;
            return t2;
        }
        // code=0x03, function=(B nor A), lowered=not ((B or A)), set=intel
        template<> uint64_t ternary<0x03>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | A;
            const uint64_t t1 = ~t0;
            return t1;
        }
        // code=0x04, function=(B and (A nor C)), lowered=(B and not ((A or C))), set=intel
        template<> uint64_t ternary<0x04>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A | C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = B & t1;
            return t2;
        }
        // code=0x05, function=(C nor A), lowered=not ((C or A)), set=intel
        template<> uint64_t ternary<0x05>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C | A;
            const uint64_t t1 = ~t0;
            return t1;
        }
        // code=0x06, function=(not (A) and (B xor C)), lowered=(not (A) and (B xor C)), set=automat
        template<> uint64_t ternary<0x06>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = B ^ C;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x07, function=(A nor (B and C)), lowered=not ((A or (B and C))), set=intel
        template<> uint64_t ternary<0x07>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t t1 = A | t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0x08, function=((not (A) and B) and C), lowered=((not (A) and B) and C), set=automat
        template<> uint64_t ternary<0x08>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = t0 & B;
            const uint64_t t2 = t1 & C;
            return t2;
        }
        // code=0x09, function=(A nor (B xor C)), lowered=not ((A or (B xor C))), set=intel
        template<> uint64_t ternary<0x09>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = A | t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0x0a, function=(C and not (A)), lowered=(C and not (A)), set=intel
        template<> uint64_t ternary<0x0a>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = C & t0;
            return t1;
        }
        // code=0x0b, function=(not (A) and ((B xor 1) or C)), lowered=(not (A) and ((B xor 1) or C)), set=automat
        template<> uint64_t ternary<0x0b>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = B ^ c1;
            const uint64_t t2 = t1 | C;
            const uint64_t t3 = t0 & t2;
            return t3;
        }
        // code=0x0c, function=(B and not (A)), lowered=(B and not (A)), set=intel
        template<> uint64_t ternary<0x0c>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = B & t0;
            return t1;
        }
        // code=0x0d, function=(not (A) and (B or (C xor 1))), lowered=(not (A) and (B or (C xor 1))), set=automat
        template<> uint64_t ternary<0x0d>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = C ^ c1;
            const uint64_t t2 = B | t1;
            const uint64_t t3 = t0 & t2;
            return t3;
        }
        // code=0x0e, function=(not (A) and (B or C)), lowered=(not (A) and (B or C)), set=automat
        template<> uint64_t ternary<0x0e>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = B | C;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x0f, function=not (A), lowered=not (A), set=intel
        template<> uint64_t ternary<0x0f>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            return t0;
        }
        // code=0x10, function=(A and (B nor C)), lowered=(A and not ((B or C))), set=intel
        template<> uint64_t ternary<0x10>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A & t1;
            return t2;
        }
        // code=0x11, function=(C nor B), lowered=not ((C or B)), set=intel
        template<> uint64_t ternary<0x11>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C | B;
            const uint64_t t1 = ~t0;
            return t1;
        }
        // code=0x12, function=(not (B) and (A xor C)), lowered=(not (B) and (A xor C)), set=automat
        template<> uint64_t ternary<0x12>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = A ^ C;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x13, function=(B nor (A and C)), lowered=not ((B or (A and C))), set=intel
        template<> uint64_t ternary<0x13>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = B | t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0x14, function=(not (C) and (A xor B)), lowered=(not (C) and (A xor B)), set=automat
        template<> uint64_t ternary<0x14>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = A ^ B;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x15, function=(C nor (B and A)), lowered=not ((C or (B and A))), set=intel
        template<> uint64_t ternary<0x15>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & A;
            const uint64_t t1 = C | t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0x16, function=(A ? (B nor C) : (B xor C)), lowered=((A and not ((B or C))) or (not (A) and (B xor C))), set=intel
        template<> uint64_t ternary<0x16>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A & t1;
            const uint64_t t3 = ~A;
            const uint64_t t4 = B ^ C;
            const uint64_t t5 = t3 & t4;
            const uint64_t t6 = t2 | t5;
            return t6;
        }
        // code=0x17, function=not ((A ? (B or C) : (B and C))), lowered=not ((A ? (B or C) : (B and C))), set=intel
        template<> uint64_t ternary<0x17>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = B & C;
            const uint64_t t2 = (A & t0) | (~A & t1);
            const uint64_t t3 = ~t2;
            return t3;
        }
        // code=0x18, function=((A xor B) and (A xor C)), lowered=((A xor B) and (A xor C)), set=automat
        template<> uint64_t ternary<0x18>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ B;
            const uint64_t t1 = A ^ C;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x19, function=not (((B xor C) xor (A and (B and C)))), lowered=not (((B xor C) xor (A and (B and C)))), set=optimized
        template<> uint64_t ternary<0x19>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = B & C;
            const uint64_t t2 = A & t1;
            const uint64_t t3 = t0 ^ t2;
            const uint64_t t4 = ~t3;
            return t4;
        }
        // code=0x1a, function=(not ((A and B)) and (A xor C)), lowered=(not ((A and B)) and (A xor C)), set=automat
        template<> uint64_t ternary<0x1a>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & B;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A ^ C;
            const uint64_t t3 = t1 & t2;
            return t3;
        }
        // code=0x1b, function=(C ? not (A) : not (B)), lowered=((C and not (A)) or (not (C) and not (B))), set=intel
        template<> uint64_t ternary<0x1b>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = C & t0;
            const uint64_t t2 = ~C;
            const uint64_t t3 = ~B;
            const uint64_t t4 = t2 & t3;
            const uint64_t t5 = t1 | t4;
            return t5;
        }
        // code=0x1c, function=(not ((A and C)) and (A xor B)), lowered=(not ((A and C)) and (A xor B)), set=automat
        template<> uint64_t ternary<0x1c>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A ^ B;
            const uint64_t t3 = t1 & t2;
            return t3;
        }
        // code=0x1d, function=(B ? not (A) : not (C)), lowered=((B and not (A)) or (not (B) and not (C))), set=intel
        template<> uint64_t ternary<0x1d>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = B & t0;
            const uint64_t t2 = ~B;
            const uint64_t t3 = ~C;
            const uint64_t t4 = t2 & t3;
            const uint64_t t5 = t1 | t4;
            return t5;
        }
        // code=0x1e, function=(A xor (B or C)), lowered=(A xor (B or C)), set=intel
        template<> uint64_t ternary<0x1e>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = A ^ t0;
            return t1;
        }
        // code=0x1f, function=(A nand (B or C)), lowered=not ((A and (B or C))), set=intel
        template<> uint64_t ternary<0x1f>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = A & t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0x20, function=((not (B) and A) and C), lowered=((not (B) and A) and C), set=automat
        template<> uint64_t ternary<0x20>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = t0 & A;
            const uint64_t t2 = t1 & C;
            return t2;
        }
        // code=0x21, function=(B nor (A xor C)), lowered=not ((B or (A xor C))), set=intel
        template<> uint64_t ternary<0x21>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ C;
            const uint64_t t1 = B | t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0x22, function=(C and not (B)), lowered=(C and not (B)), set=intel
        template<> uint64_t ternary<0x22>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = C & t0;
            return t1;
        }
        // code=0x23, function=(not (B) and ((A xor 1) or C)), lowered=(not (B) and ((A xor 1) or C)), set=automat
        template<> uint64_t ternary<0x23>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = A ^ c1;
            const uint64_t t2 = t1 | C;
            const uint64_t t3 = t0 & t2;
            return t3;
        }
        // code=0x24, function=((A xor B) and (B xor C)), lowered=((A xor B) and (B xor C)), set=automat
        template<> uint64_t ternary<0x24>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ B;
            const uint64_t t1 = B ^ C;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x25, function=(not ((A and B)) and (A xor (C xor 1))), lowered=(not ((A and B)) and (A xor (C xor 1))), set=automat
        template<> uint64_t ternary<0x25>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & B;
            const uint64_t t1 = ~t0;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = C ^ c1;
            const uint64_t t3 = A ^ t2;
            const uint64_t t4 = t1 & t3;
            return t4;
        }
        // code=0x26, function=(not ((A and B)) and (B xor C)), lowered=(not ((A and B)) and (B xor C)), set=automat
        template<> uint64_t ternary<0x26>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & B;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = B ^ C;
            const uint64_t t3 = t1 & t2;
            return t3;
        }
        // code=0x27, function=(C ? not (B) : not (A)), lowered=((C and not (B)) or (not (C) and not (A))), set=intel
        template<> uint64_t ternary<0x27>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = C & t0;
            const uint64_t t2 = ~C;
            const uint64_t t3 = ~A;
            const uint64_t t4 = t2 & t3;
            const uint64_t t5 = t1 | t4;
            return t5;
        }
        // code=0x28, function=(C and (B xor A)), lowered=(C and (B xor A)), set=intel
        template<> uint64_t ternary<0x28>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ A;
            const uint64_t t1 = C & t0;
            return t1;
        }
        // code=0x29, function=(C ? (B xor A) : (B nor A)), lowered=((C and (B xor A)) or (not (C) and not ((B or A)))), set=intel
        template<> uint64_t ternary<0x29>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ A;
            const uint64_t t1 = C & t0;
            const uint64_t t2 = ~C;
            const uint64_t t3 = B | A;
            const uint64_t t4 = ~t3;
            const uint64_t t5 = t2 & t4;
            const uint64_t t6 = t1 | t5;
            return t6;
        }
        // code=0x2a, function=(C and (B nand A)), lowered=(C and not ((B and A))), set=intel
        template<> uint64_t ternary<0x2a>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & A;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = C & t1;
            return t2;
        }
        // code=0x2b, function=(C ? (B nand A) : (B nor A)), lowered=((C and not ((B and A))) or (not (C) and not ((B or A)))), set=intel
        template<> uint64_t ternary<0x2b>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & A;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = C & t1;
            const uint64_t t3 = ~C;
            const uint64_t t4 = B | A;
            const uint64_t t5 = ~t4;
            const uint64_t t6 = t3 & t5;
            const uint64_t t7 = t2 | t6;
            return t7;
        }
        // code=0x2c, function=((B or C) and (A xor B)), lowered=((B or C) and (A xor B)), set=automat
        template<> uint64_t ternary<0x2c>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = A ^ B;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x2d, function=(A xor (B or not (C))), lowered=(A xor (B or not (C))), set=optimized
        template<> uint64_t ternary<0x2d>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = B | t0;
            const uint64_t t2 = A ^ t1;
            return t2;
        }
        // code=0x2e, function=((B or C) xor (A and B)), lowered=((B or C) xor (A and B)), set=optimized
        template<> uint64_t ternary<0x2e>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = A & B;
            const uint64_t t2 = t0 ^ t1;
            return t2;
        }
        // code=0x2f, function=(not (A) or (not (B) and C)), lowered=(not (A) or (not (B) and C)), set=optimized
        template<> uint64_t ternary<0x2f>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = ~B;
            const uint64_t t2 = t1 & C;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0x30, function=(A and not (B)), lowered=(A and not (B)), set=intel
        template<> uint64_t ternary<0x30>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = A & t0;
            return t1;
        }
        // code=0x31, function=(not (B) and (A or (C xor 1))), lowered=(not (B) and (A or (C xor 1))), set=automat
        template<> uint64_t ternary<0x31>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = C ^ c1;
            const uint64_t t2 = A | t1;
            const uint64_t t3 = t0 & t2;
            return t3;
        }
        // code=0x32, function=(not (B) and (A or C)), lowered=(not (B) and (A or C)), set=automat
        template<> uint64_t ternary<0x32>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = A | C;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x33, function=not (B), lowered=not (B), set=intel
        template<> uint64_t ternary<0x33>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            return t0;
        }
        // code=0x34, function=(not ((B and C)) and (A xor B)), lowered=(not ((B and C)) and (A xor B)), set=automat
        template<> uint64_t ternary<0x34>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A ^ B;
            const uint64_t t3 = t1 & t2;
            return t3;
        }
        // code=0x35, function=(A ? not (B) : not (C)), lowered=((A and not (B)) or (not (A) and not (C))), set=intel
        template<> uint64_t ternary<0x35>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = A & t0;
            const uint64_t t2 = ~A;
            const uint64_t t3 = ~C;
            const uint64_t t4 = t2 & t3;
            const uint64_t t5 = t1 | t4;
            return t5;
        }
        // code=0x36, function=(B xor (A or C)), lowered=(B xor (A or C)), set=intel
        template<> uint64_t ternary<0x36>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A | C;
            const uint64_t t1 = B ^ t0;
            return t1;
        }
        // code=0x37, function=(B nand (A or C)), lowered=not ((B and (A or C))), set=intel
        template<> uint64_t ternary<0x37>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A | C;
            const uint64_t t1 = B & t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0x38, function=((A or C) and (A xor B)), lowered=((A or C) and (A xor B)), set=automat
        template<> uint64_t ternary<0x38>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A | C;
            const uint64_t t1 = A ^ B;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x39, function=(B xor (A or (C xor 1))), lowered=(B xor (A or (C xor 1))), set=automat
        template<> uint64_t ternary<0x39>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t0 = C ^ c1;
            const uint64_t t1 = A | t0;
            const uint64_t t2 = B ^ t1;
            return t2;
        }
        // code=0x3a, function=(A ? not (B) : C), lowered=((A and not (B)) or (not (A) and C)), set=intel
        template<> uint64_t ternary<0x3a>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = A & t0;
            const uint64_t t2 = ~A;
            const uint64_t t3 = t2 & C;
            const uint64_t t4 = t1 | t3;
            return t4;
        }
        // code=0x3b, function=((not (A) and C) or (B xor 1)), lowered=((not (A) and C) or (B xor 1)), set=automat
        template<> uint64_t ternary<0x3b>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = t0 & C;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = B ^ c1;
            const uint64_t t3 = t1 | t2;
            return t3;
        }
        // code=0x3c, function=(B xor A), lowered=(B xor A), set=intel
        template<> uint64_t ternary<0x3c>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ A;
            return t0;
        }
        // code=0x3d, function=((A xor B) or (A nor C)), lowered=((A xor B) or not ((A or C))), set=optimized
        template<> uint64_t ternary<0x3d>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ B;
            const uint64_t t1 = A | C;
            const uint64_t t2 = ~t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0x3e, function=((not (A) and C) or (A xor B)), lowered=((not (A) and C) or (A xor B)), set=automat
        template<> uint64_t ternary<0x3e>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = t0 & C;
            const uint64_t t2 = A ^ B;
            const uint64_t t3 = t1 | t2;
            return t3;
        }
        // code=0x3f, function=(B nand A), lowered=not ((B and A)), set=intel
        template<> uint64_t ternary<0x3f>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & A;
            const uint64_t t1 = ~t0;
            return t1;
        }
        // code=0x40, function=((not (C) and A) and B), lowered=((not (C) and A) and B), set=automat
        template<> uint64_t ternary<0x40>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = t0 & A;
            const uint64_t t2 = t1 & B;
            return t2;
        }
        // code=0x41, function=(C nor (B xor A)), lowered=not ((C or (B xor A))), set=intel
        template<> uint64_t ternary<0x41>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ A;
            const uint64_t t1 = C | t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0x42, function=((A xor C) and (B xor C)), lowered=((A xor C) and (B xor C)), set=automat
        template<> uint64_t ternary<0x42>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ C;
            const uint64_t t1 = B ^ C;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x43, function=(not ((A and C)) and (A xor (B xor 1))), lowered=(not ((A and C)) and (A xor (B xor 1))), set=automat
        template<> uint64_t ternary<0x43>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = ~t0;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = B ^ c1;
            const uint64_t t3 = A ^ t2;
            const uint64_t t4 = t1 & t3;
            return t4;
        }
        // code=0x44, function=(B and not (C)), lowered=(B and not (C)), set=intel
        template<> uint64_t ternary<0x44>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = B & t0;
            return t1;
        }
        // code=0x45, function=(not (C) and ((A xor 1) or B)), lowered=(not (C) and ((A xor 1) or B)), set=automat
        template<> uint64_t ternary<0x45>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = A ^ c1;
            const uint64_t t2 = t1 | B;
            const uint64_t t3 = t0 & t2;
            return t3;
        }
        // code=0x46, function=(not ((A and C)) and (B xor C)), lowered=(not ((A and C)) and (B xor C)), set=automat
        template<> uint64_t ternary<0x46>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = B ^ C;
            const uint64_t t3 = t1 & t2;
            return t3;
        }
        // code=0x47, function=(B ? not (C) : not (A)), lowered=((B and not (C)) or (not (B) and not (A))), set=intel
        template<> uint64_t ternary<0x47>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = B & t0;
            const uint64_t t2 = ~B;
            const uint64_t t3 = ~A;
            const uint64_t t4 = t2 & t3;
            const uint64_t t5 = t1 | t4;
            return t5;
        }
        // code=0x48, function=(B and (A xor C)), lowered=(B and (A xor C)), set=intel
        template<> uint64_t ternary<0x48>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ C;
            const uint64_t t1 = B & t0;
            return t1;
        }
        // code=0x49, function=(B ? (A xor C) : (A nor C)), lowered=((B and (A xor C)) or (not (B) and not ((A or C)))), set=intel
        template<> uint64_t ternary<0x49>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ C;
            const uint64_t t1 = B & t0;
            const uint64_t t2 = ~B;
            const uint64_t t3 = A | C;
            const uint64_t t4 = ~t3;
            const uint64_t t5 = t2 & t4;
            const uint64_t t6 = t1 | t5;
            return t6;
        }
        // code=0x4a, function=((B or C) and (A xor C)), lowered=((B or C) and (A xor C)), set=automat
        template<> uint64_t ternary<0x4a>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = A ^ C;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x4b, function=(A xor (not (B) or C)), lowered=(A xor (not (B) or C)), set=optimized
        template<> uint64_t ternary<0x4b>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = t0 | C;
            const uint64_t t2 = A ^ t1;
            return t2;
        }
        // code=0x4c, function=(B and (A nand C)), lowered=(B and not ((A and C))), set=intel
        template<> uint64_t ternary<0x4c>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = B & t1;
            return t2;
        }
        // code=0x4d, function=(B ? (A nand C) : (A nor C)), lowered=((B and not ((A and C))) or (not (B) and not ((A or C)))), set=intel
        template<> uint64_t ternary<0x4d>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = B & t1;
            const uint64_t t3 = ~B;
            const uint64_t t4 = A | C;
            const uint64_t t5 = ~t4;
            const uint64_t t6 = t3 & t5;
            const uint64_t t7 = t2 | t6;
            return t7;
        }
        // code=0x4e, function=(C ? not (A) : B), lowered=((C and not (A)) or (not (C) and B)), set=intel
        template<> uint64_t ternary<0x4e>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = C & t0;
            const uint64_t t2 = ~C;
            const uint64_t t3 = t2 & B;
            const uint64_t t4 = t1 | t3;
            return t4;
        }
        // code=0x4f, function=(not (A) or (B and not (C))), lowered=(not (A) or (B and not (C))), set=optimized
        template<> uint64_t ternary<0x4f>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = ~C;
            const uint64_t t2 = B & t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0x50, function=(A and not (C)), lowered=(A and not (C)), set=intel
        template<> uint64_t ternary<0x50>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = A & t0;
            return t1;
        }
        // code=0x51, function=(not (C) and (A or (B xor 1))), lowered=(not (C) and (A or (B xor 1))), set=automat
        template<> uint64_t ternary<0x51>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = B ^ c1;
            const uint64_t t2 = A | t1;
            const uint64_t t3 = t0 & t2;
            return t3;
        }
        // code=0x52, function=(not ((B and C)) and (A xor C)), lowered=(not ((B and C)) and (A xor C)), set=automat
        template<> uint64_t ternary<0x52>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A ^ C;
            const uint64_t t3 = t1 & t2;
            return t3;
        }
        // code=0x53, function=(A ? not (C) : not (B)), lowered=((A and not (C)) or (not (A) and not (B))), set=intel
        template<> uint64_t ternary<0x53>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = A & t0;
            const uint64_t t2 = ~A;
            const uint64_t t3 = ~B;
            const uint64_t t4 = t2 & t3;
            const uint64_t t5 = t1 | t4;
            return t5;
        }
        // code=0x54, function=(not (C) and (A or B)), lowered=(not (C) and (A or B)), set=automat
        template<> uint64_t ternary<0x54>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = A | B;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x55, function=not (C), lowered=not (C), set=intel
        template<> uint64_t ternary<0x55>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            return t0;
        }
        // code=0x56, function=(C xor (B or A)), lowered=(C xor (B or A)), set=intel
        template<> uint64_t ternary<0x56>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | A;
            const uint64_t t1 = C ^ t0;
            return t1;
        }
        // code=0x57, function=(C nand (B or A)), lowered=not ((C and (B or A))), set=intel
        template<> uint64_t ternary<0x57>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | A;
            const uint64_t t1 = C & t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0x58, function=((A or B) and (A xor C)), lowered=((A or B) and (A xor C)), set=automat
        template<> uint64_t ternary<0x58>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A | B;
            const uint64_t t1 = A ^ C;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x59, function=(C xor (A or (B xor 1))), lowered=(C xor (A or (B xor 1))), set=automat
        template<> uint64_t ternary<0x59>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t0 = B ^ c1;
            const uint64_t t1 = A | t0;
            const uint64_t t2 = C ^ t1;
            return t2;
        }
        // code=0x5a, function=(C xor A), lowered=(C xor A), set=intel
        template<> uint64_t ternary<0x5a>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C ^ A;
            return t0;
        }
        // code=0x5b, function=((A xor C) or ((A or B) xor 1)), lowered=((A xor C) or ((A or B) xor 1)), set=automat
        template<> uint64_t ternary<0x5b>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ C;
            const uint64_t t1 = A | B;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = t1 ^ c1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0x5c, function=(A ? not (C) : B), lowered=((A and not (C)) or (not (A) and B)), set=intel
        template<> uint64_t ternary<0x5c>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = A & t0;
            const uint64_t t2 = ~A;
            const uint64_t t3 = t2 & B;
            const uint64_t t4 = t1 | t3;
            return t4;
        }
        // code=0x5d, function=(not (C) or (not (A) and B)), lowered=(not (C) or (not (A) and B)), set=optimized
        template<> uint64_t ternary<0x5d>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = ~A;
            const uint64_t t2 = t1 & B;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0x5e, function=((not (C) and B) or (A xor C)), lowered=((not (C) and B) or (A xor C)), set=automat
        template<> uint64_t ternary<0x5e>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = t0 & B;
            const uint64_t t2 = A ^ C;
            const uint64_t t3 = t1 | t2;
            return t3;
        }
        // code=0x5f, function=(C nand A), lowered=not ((C and A)), set=intel
        template<> uint64_t ternary<0x5f>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C & A;
            const uint64_t t1 = ~t0;
            return t1;
        }
        // code=0x60, function=(A and (B xor C)), lowered=(A and (B xor C)), set=intel
        template<> uint64_t ternary<0x60>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = A & t0;
            return t1;
        }
        // code=0x61, function=(A ? (B xor C) : (B nor C)), lowered=((A and (B xor C)) or (not (A) and not ((B or C)))), set=intel
        template<> uint64_t ternary<0x61>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = A & t0;
            const uint64_t t2 = ~A;
            const uint64_t t3 = B | C;
            const uint64_t t4 = ~t3;
            const uint64_t t5 = t2 & t4;
            const uint64_t t6 = t1 | t5;
            return t6;
        }
        // code=0x62, function=((A or C) and (B xor C)), lowered=((A or C) and (B xor C)), set=automat
        template<> uint64_t ternary<0x62>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A | C;
            const uint64_t t1 = B ^ C;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x63, function=(B xor ((A xor 1) or C)), lowered=(B xor ((A xor 1) or C)), set=automat
        template<> uint64_t ternary<0x63>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t0 = A ^ c1;
            const uint64_t t1 = t0 | C;
            const uint64_t t2 = B ^ t1;
            return t2;
        }
        // code=0x64, function=((A or B) and (B xor C)), lowered=((A or B) and (B xor C)), set=automat
        template<> uint64_t ternary<0x64>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A | B;
            const uint64_t t1 = B ^ C;
            const uint64_t t2 = t0 & t1;
            return t2;
        }
        // code=0x65, function=(C xor ((A xor 1) or B)), lowered=(C xor ((A xor 1) or B)), set=automat
        template<> uint64_t ternary<0x65>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t0 = A ^ c1;
            const uint64_t t1 = t0 | B;
            const uint64_t t2 = C ^ t1;
            return t2;
        }
        // code=0x66, function=(C xor B), lowered=(C xor B), set=intel
        template<> uint64_t ternary<0x66>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C ^ B;
            return t0;
        }
        // code=0x67, function=((B xor C) or (A nor B)), lowered=((B xor C) or not ((A or B))), set=optimized
        template<> uint64_t ternary<0x67>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = A | B;
            const uint64_t t2 = ~t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0x68, function=(A ? (B xor C) : (B and C)), lowered=((A and (B xor C)) or (not (A) and (B and C))), set=intel
        template<> uint64_t ternary<0x68>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = A & t0;
            const uint64_t t2 = ~A;
            const uint64_t t3 = B & C;
            const uint64_t t4 = t2 & t3;
            const uint64_t t5 = t1 | t4;
            return t5;
        }
        // code=0x69, function=(A xnor (B xor C)), lowered=not ((A xor (B xor C))), set=intel
        template<> uint64_t ternary<0x69>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = A ^ t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0x6a, function=(C xor (B and A)), lowered=(C xor (B and A)), set=intel
        template<> uint64_t ternary<0x6a>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & A;
            const uint64_t t1 = C ^ t0;
            return t1;
        }
        // code=0x6b, function=((not (A) and C) or ((A xor 1) xor (B xor C))), lowered=((not (A) and C) or ((A xor 1) xor (B xor C))), set=automat
        template<> uint64_t ternary<0x6b>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = t0 & C;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = A ^ c1;
            const uint64_t t3 = B ^ C;
            const uint64_t t4 = t2 ^ t3;
            const uint64_t t5 = t1 | t4;
            return t5;
        }
        // code=0x6c, function=(B xor (A and C)), lowered=(B xor (A and C)), set=intel
        template<> uint64_t ternary<0x6c>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = B ^ t0;
            return t1;
        }
        // code=0x6d, function=((not (A) and B) or ((A xor 1) xor (B xor C))), lowered=((not (A) and B) or ((A xor 1) xor (B xor C))), set=automat
        template<> uint64_t ternary<0x6d>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = t0 & B;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = A ^ c1;
            const uint64_t t3 = B ^ C;
            const uint64_t t4 = t2 ^ t3;
            const uint64_t t5 = t1 | t4;
            return t5;
        }
        // code=0x6e, function=((not (A) and B) or (B xor C)), lowered=((not (A) and B) or (B xor C)), set=automat
        template<> uint64_t ternary<0x6e>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = t0 & B;
            const uint64_t t2 = B ^ C;
            const uint64_t t3 = t1 | t2;
            return t3;
        }
        // code=0x6f, function=((B xor C) or (A xor 1)), lowered=((B xor C) or (A xor 1)), set=automat
        template<> uint64_t ternary<0x6f>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = A ^ c1;
            const uint64_t t2 = t0 | t1;
            return t2;
        }
        // code=0x70, function=(A and (B nand C)), lowered=(A and not ((B and C))), set=intel
        template<> uint64_t ternary<0x70>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A & t1;
            return t2;
        }
        // code=0x71, function=((B nor C) or (A and (B xor C))), lowered=(not ((B or C)) or (A and (B xor C))), set=optimized
        template<> uint64_t ternary<0x71>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = B ^ C;
            const uint64_t t3 = A & t2;
            const uint64_t t4 = t1 | t3;
            return t4;
        }
        // code=0x72, function=(C ? not (B) : A), lowered=((C and not (B)) or (not (C) and A)), set=intel
        template<> uint64_t ternary<0x72>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = C & t0;
            const uint64_t t2 = ~C;
            const uint64_t t3 = t2 & A;
            const uint64_t t4 = t1 | t3;
            return t4;
        }
        // code=0x73, function=(not (B) or (A and not (C))), lowered=(not (B) or (A and not (C))), set=optimized
        template<> uint64_t ternary<0x73>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = ~C;
            const uint64_t t2 = A & t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0x74, function=(B ? not (C) : A), lowered=((B and not (C)) or (not (B) and A)), set=intel
        template<> uint64_t ternary<0x74>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = B & t0;
            const uint64_t t2 = ~B;
            const uint64_t t3 = t2 & A;
            const uint64_t t4 = t1 | t3;
            return t4;
        }
        // code=0x75, function=(not (C) or (A and not (B))), lowered=(not (C) or (A and not (B))), set=optimized
        template<> uint64_t ternary<0x75>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = ~B;
            const uint64_t t2 = A & t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0x76, function=((not (B) and A) or (B xor C)), lowered=((not (B) and A) or (B xor C)), set=automat
        template<> uint64_t ternary<0x76>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = t0 & A;
            const uint64_t t2 = B ^ C;
            const uint64_t t3 = t1 | t2;
            return t3;
        }
        // code=0x77, function=(C nand B), lowered=not ((C and B)), set=intel
        template<> uint64_t ternary<0x77>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C & B;
            const uint64_t t1 = ~t0;
            return t1;
        }
        // code=0x78, function=(A xor (B and C)), lowered=(A xor (B and C)), set=intel
        template<> uint64_t ternary<0x78>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t t1 = A ^ t0;
            return t1;
        }
        // code=0x79, function=((not (B) and A) or ((B xor 1) xor (A xor C))), lowered=((not (B) and A) or ((B xor 1) xor (A xor C))), set=automat
        template<> uint64_t ternary<0x79>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = t0 & A;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = B ^ c1;
            const uint64_t t3 = A ^ C;
            const uint64_t t4 = t2 ^ t3;
            const uint64_t t5 = t1 | t4;
            return t5;
        }
        // code=0x7a, function=((not (B) and A) or (A xor C)), lowered=((not (B) and A) or (A xor C)), set=automat
        template<> uint64_t ternary<0x7a>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = t0 & A;
            const uint64_t t2 = A ^ C;
            const uint64_t t3 = t1 | t2;
            return t3;
        }
        // code=0x7b, function=(not (B) or (A xor C)), lowered=(not (B) or (A xor C)), set=optimized
        template<> uint64_t ternary<0x7b>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = A ^ C;
            const uint64_t t2 = t0 | t1;
            return t2;
        }
        // code=0x7c, function=((not (C) and A) or (A xor B)), lowered=((not (C) and A) or (A xor B)), set=automat
        template<> uint64_t ternary<0x7c>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = t0 & A;
            const uint64_t t2 = A ^ B;
            const uint64_t t3 = t1 | t2;
            return t3;
        }
        // code=0x7d, function=((A xor B) or (C xor 1)), lowered=((A xor B) or (C xor 1)), set=automat
        template<> uint64_t ternary<0x7d>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ B;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = C ^ c1;
            const uint64_t t2 = t0 | t1;
            return t2;
        }
        // code=0x7e, function=((A xor B) or (A xor C)), lowered=((A xor B) or (A xor C)), set=automat
        template<> uint64_t ternary<0x7e>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ B;
            const uint64_t t1 = A ^ C;
            const uint64_t t2 = t0 | t1;
            return t2;
        }
        // code=0x7f, function=(((A and B) and C) xor 1), lowered=(((A and B) and C) xor 1), set=automat
        template<> uint64_t ternary<0x7f>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & B;
            const uint64_t t1 = t0 & C;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = t1 ^ c1;
            return t2;
        }
        // code=0x80, function=(A and (B and C)), lowered=(A and (B and C)), set=optimized
        template<> uint64_t ternary<0x80>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t t1 = A & t0;
            return t1;
        }
        // code=0x81, function=(not ((A xor C)) and (A xor (B xor 1))), lowered=(not ((A xor C)) and (A xor (B xor 1))), set=automat
        template<> uint64_t ternary<0x81>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ C;
            const uint64_t t1 = ~t0;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = B ^ c1;
            const uint64_t t3 = A ^ t2;
            const uint64_t t4 = t1 & t3;
            return t4;
        }
        // code=0x82, function=(C and (B xnor A)), lowered=(C and not ((B xor A))), set=intel
        template<> uint64_t ternary<0x82>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ A;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = C & t1;
            return t2;
        }
        // code=0x83, function=(not ((A xor B)) and ((A xor 1) or C)), lowered=(not ((A xor B)) and ((A xor 1) or C)), set=automat
        template<> uint64_t ternary<0x83>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ B;
            const uint64_t t1 = ~t0;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = A ^ c1;
            const uint64_t t3 = t2 | C;
            const uint64_t t4 = t1 & t3;
            return t4;
        }
        // code=0x84, function=(B and (A xnor C)), lowered=(B and not ((A xor C))), set=intel
        template<> uint64_t ternary<0x84>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = B & t1;
            return t2;
        }
        // code=0x85, function=(not ((A xor C)) and (B or (C xor 1))), lowered=(not ((A xor C)) and (B or (C xor 1))), set=automat
        template<> uint64_t ternary<0x85>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ C;
            const uint64_t t1 = ~t0;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = C ^ c1;
            const uint64_t t3 = B | t2;
            const uint64_t t4 = t1 & t3;
            return t4;
        }
        // code=0x86, function=((B or C) and (C xor (A xor B))), lowered=((B or C) and (C xor (A xor B))), set=automat
        template<> uint64_t ternary<0x86>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = A ^ B;
            const uint64_t t2 = C ^ t1;
            const uint64_t t3 = t0 & t2;
            return t3;
        }
        // code=0x87, function=(A xnor (B and C)), lowered=not ((A xor (B and C))), set=intel
        template<> uint64_t ternary<0x87>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t t1 = A ^ t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0x88, function=(C and B), lowered=(C and B), set=intel
        template<> uint64_t ternary<0x88>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C & B;
            return t0;
        }
        // code=0x89, function=(not ((B xor C)) and ((A xor 1) or B)), lowered=(not ((B xor C)) and ((A xor 1) or B)), set=automat
        template<> uint64_t ternary<0x89>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = ~t0;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = A ^ c1;
            const uint64_t t3 = t2 | B;
            const uint64_t t4 = t1 & t3;
            return t4;
        }
        // code=0x8a, function=(not ((not (B) and A)) and C), lowered=(not ((not (B) and A)) and C), set=automat
        template<> uint64_t ternary<0x8a>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = t0 & A;
            const uint64_t t2 = ~t1;
            const uint64_t t3 = t2 & C;
            return t3;
        }
        // code=0x8b, function=(B ? C : not (A)), lowered=((B and C) or (not (B) and not (A))), set=intel
        template<> uint64_t ternary<0x8b>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t t1 = ~B;
            const uint64_t t2 = ~A;
            const uint64_t t3 = t1 & t2;
            const uint64_t t4 = t0 | t3;
            return t4;
        }
        // code=0x8c, function=(not ((not (C) and A)) and B), lowered=(not ((not (C) and A)) and B), set=automat
        template<> uint64_t ternary<0x8c>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = t0 & A;
            const uint64_t t2 = ~t1;
            const uint64_t t3 = t2 & B;
            return t3;
        }
        // code=0x8d, function=(C ? B : not (A)), lowered=((C and B) or (not (C) and not (A))), set=intel
        template<> uint64_t ternary<0x8d>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C & B;
            const uint64_t t1 = ~C;
            const uint64_t t2 = ~A;
            const uint64_t t3 = t1 & t2;
            const uint64_t t4 = t0 | t3;
            return t4;
        }
        // code=0x8e, function=((B and C) or (not (A) and (B xor C))), lowered=((B and C) or (not (A) and (B xor C))), set=optimized
        template<> uint64_t ternary<0x8e>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t t1 = ~A;
            const uint64_t t2 = B ^ C;
            const uint64_t t3 = t1 & t2;
            const uint64_t t4 = t0 | t3;
            return t4;
        }
        // code=0x8f, function=(not (A) or (B and C)), lowered=(not (A) or (B and C)), set=optimized
        template<> uint64_t ternary<0x8f>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = B & C;
            const uint64_t t2 = t0 | t1;
            return t2;
        }
        // code=0x90, function=(A and (B xnor C)), lowered=(A and not ((B xor C))), set=intel
        template<> uint64_t ternary<0x90>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A & t1;
            return t2;
        }
        // code=0x91, function=(not ((B xor C)) and (A or (B xor 1))), lowered=(not ((B xor C)) and (A or (B xor 1))), set=automat
        template<> uint64_t ternary<0x91>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = ~t0;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = B ^ c1;
            const uint64_t t3 = A | t2;
            const uint64_t t4 = t1 & t3;
            return t4;
        }
        // code=0x92, function=((A or C) and (C xor (A xor B))), lowered=((A or C) and (C xor (A xor B))), set=automat
        template<> uint64_t ternary<0x92>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A | C;
            const uint64_t t1 = A ^ B;
            const uint64_t t2 = C ^ t1;
            const uint64_t t3 = t0 & t2;
            return t3;
        }
        // code=0x93, function=(B xnor (A and C)), lowered=not ((B xor (A and C))), set=intel
        template<> uint64_t ternary<0x93>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = B ^ t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0x94, function=((A or B) and (B xor (A xor C))), lowered=((A or B) and (B xor (A xor C))), set=automat
        template<> uint64_t ternary<0x94>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A | B;
            const uint64_t t1 = A ^ C;
            const uint64_t t2 = B ^ t1;
            const uint64_t t3 = t0 & t2;
            return t3;
        }
        // code=0x95, function=(C xnor (B and A)), lowered=not ((C xor (B and A))), set=intel
        template<> uint64_t ternary<0x95>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & A;
            const uint64_t t1 = C ^ t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0x96, function=(A xor (B xor C)), lowered=(A xor (B xor C)), set=intel
        template<> uint64_t ternary<0x96>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = A ^ t0;
            return t1;
        }
        // code=0x97, function=(A ? (B xnor C) : (B nand C)), lowered=((A and not ((B xor C))) or (not (A) and not ((B and C)))), set=intel
        template<> uint64_t ternary<0x97>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A & t1;
            const uint64_t t3 = ~A;
            const uint64_t t4 = B & C;
            const uint64_t t5 = ~t4;
            const uint64_t t6 = t3 & t5;
            const uint64_t t7 = t2 | t6;
            return t7;
        }
        // code=0x98, function=(not ((B xor C)) and (A or B)), lowered=(not ((B xor C)) and (A or B)), set=automat
        template<> uint64_t ternary<0x98>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A | B;
            const uint64_t t3 = t1 & t2;
            return t3;
        }
        // code=0x99, function=(C xnor B), lowered=not ((C xor B)), set=intel
        template<> uint64_t ternary<0x99>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C ^ B;
            const uint64_t t1 = ~t0;
            return t1;
        }
        // code=0x9a, function=((not (B) and A) xor C), lowered=((not (B) and A) xor C), set=automat
        template<> uint64_t ternary<0x9a>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = t0 & A;
            const uint64_t t2 = t1 ^ C;
            return t2;
        }
        // code=0x9b, function=((not (A) and C) or (B xor (C xor 1))), lowered=((not (A) and C) or (B xor (C xor 1))), set=automat
        template<> uint64_t ternary<0x9b>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = t0 & C;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = C ^ c1;
            const uint64_t t3 = B ^ t2;
            const uint64_t t4 = t1 | t3;
            return t4;
        }
        // code=0x9c, function=((not (C) and A) xor B), lowered=((not (C) and A) xor B), set=automat
        template<> uint64_t ternary<0x9c>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = t0 & A;
            const uint64_t t2 = t1 ^ B;
            return t2;
        }
        // code=0x9d, function=((not (A) and B) or (B xor (C xor 1))), lowered=((not (A) and B) or (B xor (C xor 1))), set=automat
        template<> uint64_t ternary<0x9d>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = t0 & B;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = C ^ c1;
            const uint64_t t3 = B ^ t2;
            const uint64_t t4 = t1 | t3;
            return t4;
        }
        // code=0x9e, function=((B and C) or (C xor (A xor B))), lowered=((B and C) or (C xor (A xor B))), set=automat
        template<> uint64_t ternary<0x9e>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t t1 = A ^ B;
            const uint64_t t2 = C ^ t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0x9f, function=(A nand (B xor C)), lowered=not ((A and (B xor C))), set=intel
        template<> uint64_t ternary<0x9f>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = A & t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0xa0, function=(C and A), lowered=(C and A), set=intel
        template<> uint64_t ternary<0xa0>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C & A;
            return t0;
        }
        // code=0xa1, function=(not ((A xor C)) and (A or (B xor 1))), lowered=(not ((A xor C)) and (A or (B xor 1))), set=automat
        template<> uint64_t ternary<0xa1>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ C;
            const uint64_t t1 = ~t0;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = B ^ c1;
            const uint64_t t3 = A | t2;
            const uint64_t t4 = t1 & t3;
            return t4;
        }
        // code=0xa2, function=(C and (A or not (B))), lowered=(C and (A or not (B))), set=optimized
        template<> uint64_t ternary<0xa2>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = A | t0;
            const uint64_t t2 = C & t1;
            return t2;
        }
        // code=0xa3, function=(A ? C : not (B)), lowered=((A and C) or (not (A) and not (B))), set=intel
        template<> uint64_t ternary<0xa3>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = ~A;
            const uint64_t t2 = ~B;
            const uint64_t t3 = t1 & t2;
            const uint64_t t4 = t0 | t3;
            return t4;
        }
        // code=0xa4, function=(not ((A xor C)) and (A or B)), lowered=(not ((A xor C)) and (A or B)), set=automat
        template<> uint64_t ternary<0xa4>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A | B;
            const uint64_t t3 = t1 & t2;
            return t3;
        }
        // code=0xa5, function=(C xnor A), lowered=not ((C xor A)), set=intel
        template<> uint64_t ternary<0xa5>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C ^ A;
            const uint64_t t1 = ~t0;
            return t1;
        }
        // code=0xa6, function=((not (A) and B) xor C), lowered=((not (A) and B) xor C), set=automat
        template<> uint64_t ternary<0xa6>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = t0 & B;
            const uint64_t t2 = t1 ^ C;
            return t2;
        }
        // code=0xa7, function=((not (B) and C) or (A xor (C xor 1))), lowered=((not (B) and C) or (A xor (C xor 1))), set=automat
        template<> uint64_t ternary<0xa7>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = t0 & C;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = C ^ c1;
            const uint64_t t3 = A ^ t2;
            const uint64_t t4 = t1 | t3;
            return t4;
        }
        // code=0xa8, function=(C and (A or B)), lowered=(C and (A or B)), set=intel
        template<> uint64_t ternary<0xa8>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A | B;
            const uint64_t t1 = C & t0;
            return t1;
        }
        // code=0xa9, function=(C xnor (B or A)), lowered=not ((C xor (B or A))), set=intel
        template<> uint64_t ternary<0xa9>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | A;
            const uint64_t t1 = C ^ t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0xaa, function=C, lowered=C, set=intel
        template<> uint64_t ternary<0xaa>(const uint64_t A, const uint64_t B, const uint64_t C) {
            return C;
        }
        // code=0xab, function=(C or (B nor A)), lowered=(C or not ((B or A))), set=intel
        template<> uint64_t ternary<0xab>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | A;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = C | t1;
            return t2;
        }
        // code=0xac, function=(A ? C : B), lowered=((A and C) or (not (A) and B)), set=intel
        template<> uint64_t ternary<0xac>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = ~A;
            const uint64_t t2 = t1 & B;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xad, function=((B and C) or (A xor (C xor 1))), lowered=((B and C) or (A xor (C xor 1))), set=automat
        template<> uint64_t ternary<0xad>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = C ^ c1;
            const uint64_t t2 = A ^ t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xae, function=((not (A) and B) or C), lowered=((not (A) and B) or C), set=automat
        template<> uint64_t ternary<0xae>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = t0 & B;
            const uint64_t t2 = t1 | C;
            return t2;
        }
        // code=0xaf, function=(C or not (A)), lowered=(C or not (A)), set=intel
        template<> uint64_t ternary<0xaf>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = C | t0;
            return t1;
        }
        // code=0xb0, function=(not ((not (C) and B)) and A), lowered=(not ((not (C) and B)) and A), set=automat
        template<> uint64_t ternary<0xb0>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = t0 & B;
            const uint64_t t2 = ~t1;
            const uint64_t t3 = t2 & A;
            return t3;
        }
        // code=0xb1, function=(C ? A : not (B)), lowered=((C and A) or (not (C) and not (B))), set=intel
        template<> uint64_t ternary<0xb1>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C & A;
            const uint64_t t1 = ~C;
            const uint64_t t2 = ~B;
            const uint64_t t3 = t1 & t2;
            const uint64_t t4 = t0 | t3;
            return t4;
        }
        // code=0xb2, function=(B ? (A and C) : (A or C)), lowered=((B and (A and C)) or (not (B) and (A or C))), set=intel
        template<> uint64_t ternary<0xb2>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = B & t0;
            const uint64_t t2 = ~B;
            const uint64_t t3 = A | C;
            const uint64_t t4 = t2 & t3;
            const uint64_t t5 = t1 | t4;
            return t5;
        }
        // code=0xb3, function=(not (B) or (A and C)), lowered=(not (B) or (A and C)), set=optimized
        template<> uint64_t ternary<0xb3>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = A & C;
            const uint64_t t2 = t0 | t1;
            return t2;
        }
        // code=0xb4, function=((not (C) and B) xor A), lowered=((not (C) and B) xor A), set=automat
        template<> uint64_t ternary<0xb4>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = t0 & B;
            const uint64_t t2 = t1 ^ A;
            return t2;
        }
        // code=0xb5, function=((not (B) and A) or (A xor (C xor 1))), lowered=((not (B) and A) or (A xor (C xor 1))), set=automat
        template<> uint64_t ternary<0xb5>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = t0 & A;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = C ^ c1;
            const uint64_t t3 = A ^ t2;
            const uint64_t t4 = t1 | t3;
            return t4;
        }
        // code=0xb6, function=((A and C) or (C xor (A xor B))), lowered=((A and C) or (C xor (A xor B))), set=automat
        template<> uint64_t ternary<0xb6>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = A ^ B;
            const uint64_t t2 = C ^ t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xb7, function=(B nand (A xor C)), lowered=not ((B and (A xor C))), set=intel
        template<> uint64_t ternary<0xb7>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ C;
            const uint64_t t1 = B & t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0xb8, function=(B ? C : A), lowered=((B and C) or (not (B) and A)), set=intel
        template<> uint64_t ternary<0xb8>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t t1 = ~B;
            const uint64_t t2 = t1 & A;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xb9, function=((A and C) or (B xor (C xor 1))), lowered=((A and C) or (B xor (C xor 1))), set=automat
        template<> uint64_t ternary<0xb9>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = C ^ c1;
            const uint64_t t2 = B ^ t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xba, function=((not (B) and A) or C), lowered=((not (B) and A) or C), set=automat
        template<> uint64_t ternary<0xba>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = t0 & A;
            const uint64_t t2 = t1 | C;
            return t2;
        }
        // code=0xbb, function=(C or not (B)), lowered=(C or not (B)), set=intel
        template<> uint64_t ternary<0xbb>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = C | t0;
            return t1;
        }
        // code=0xbc, function=((A and C) or (A xor B)), lowered=((A and C) or (A xor B)), set=automat
        template<> uint64_t ternary<0xbc>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = A ^ B;
            const uint64_t t2 = t0 | t1;
            return t2;
        }
        // code=0xbd, function=((A xor B) or (A xor (C xor 1))), lowered=((A xor B) or (A xor (C xor 1))), set=automat
        template<> uint64_t ternary<0xbd>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ B;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = C ^ c1;
            const uint64_t t2 = A ^ t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xbe, function=(C or (B xor A)), lowered=(C or (B xor A)), set=intel
        template<> uint64_t ternary<0xbe>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ A;
            const uint64_t t1 = C | t0;
            return t1;
        }
        // code=0xbf, function=(C or (B nand A)), lowered=(C or not ((B and A))), set=intel
        template<> uint64_t ternary<0xbf>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & A;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = C | t1;
            return t2;
        }
        // code=0xc0, function=(B and A), lowered=(B and A), set=intel
        template<> uint64_t ternary<0xc0>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & A;
            return t0;
        }
        // code=0xc1, function=(not ((A xor B)) and (A or (C xor 1))), lowered=(not ((A xor B)) and (A or (C xor 1))), set=automat
        template<> uint64_t ternary<0xc1>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ B;
            const uint64_t t1 = ~t0;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = C ^ c1;
            const uint64_t t3 = A | t2;
            const uint64_t t4 = t1 & t3;
            return t4;
        }
        // code=0xc2, function=(not ((A xor B)) and (A or C)), lowered=(not ((A xor B)) and (A or C)), set=automat
        template<> uint64_t ternary<0xc2>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ B;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A | C;
            const uint64_t t3 = t1 & t2;
            return t3;
        }
        // code=0xc3, function=(B xnor A), lowered=not ((B xor A)), set=intel
        template<> uint64_t ternary<0xc3>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ A;
            const uint64_t t1 = ~t0;
            return t1;
        }
        // code=0xc4, function=(not ((not (A) and C)) and B), lowered=(not ((not (A) and C)) and B), set=automat
        template<> uint64_t ternary<0xc4>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = t0 & C;
            const uint64_t t2 = ~t1;
            const uint64_t t3 = t2 & B;
            return t3;
        }
        // code=0xc5, function=(A ? B : not (C)), lowered=((A and B) or (not (A) and not (C))), set=intel
        template<> uint64_t ternary<0xc5>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & B;
            const uint64_t t1 = ~A;
            const uint64_t t2 = ~C;
            const uint64_t t3 = t1 & t2;
            const uint64_t t4 = t0 | t3;
            return t4;
        }
        // code=0xc6, function=((not (A) and C) xor B), lowered=((not (A) and C) xor B), set=automat
        template<> uint64_t ternary<0xc6>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = t0 & C;
            const uint64_t t2 = t1 ^ B;
            return t2;
        }
        // code=0xc7, function=((not (C) and B) or (A xor (B xor 1))), lowered=((not (C) and B) or (A xor (B xor 1))), set=automat
        template<> uint64_t ternary<0xc7>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = t0 & B;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = B ^ c1;
            const uint64_t t3 = A ^ t2;
            const uint64_t t4 = t1 | t3;
            return t4;
        }
        // code=0xc8, function=(B and (A or C)), lowered=(B and (A or C)), set=intel
        template<> uint64_t ternary<0xc8>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A | C;
            const uint64_t t1 = B & t0;
            return t1;
        }
        // code=0xc9, function=(B xnor (A or C)), lowered=not ((B xor (A or C))), set=intel
        template<> uint64_t ternary<0xc9>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A | C;
            const uint64_t t1 = B ^ t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0xca, function=(A ? B : C), lowered=((A and B) or (not (A) and C)), set=intel
        template<> uint64_t ternary<0xca>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & B;
            const uint64_t t1 = ~A;
            const uint64_t t2 = t1 & C;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xcb, function=((B and C) or (A xor (B xor 1))), lowered=((B and C) or (A xor (B xor 1))), set=automat
        template<> uint64_t ternary<0xcb>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = B ^ c1;
            const uint64_t t2 = A ^ t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xcc, function=B, lowered=B, set=intel
        template<> uint64_t ternary<0xcc>(const uint64_t A, const uint64_t B, const uint64_t C) {
            return B;
        }
        // code=0xcd, function=(B or (A nor C)), lowered=(B or not ((A or C))), set=intel
        template<> uint64_t ternary<0xcd>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A | C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = B | t1;
            return t2;
        }
        // code=0xce, function=((not (A) and C) or B), lowered=((not (A) and C) or B), set=automat
        template<> uint64_t ternary<0xce>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = t0 & C;
            const uint64_t t2 = t1 | B;
            return t2;
        }
        // code=0xcf, function=(B or not (A)), lowered=(B or not (A)), set=intel
        template<> uint64_t ternary<0xcf>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = B | t0;
            return t1;
        }
        // code=0xd0, function=(A and (B or not (C))), lowered=(A and (B or not (C))), set=optimized
        template<> uint64_t ternary<0xd0>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = B | t0;
            const uint64_t t2 = A & t1;
            return t2;
        }
        // code=0xd1, function=((B nor C) or (A and B)), lowered=(not ((B or C)) or (A and B)), set=optimized
        template<> uint64_t ternary<0xd1>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A & B;
            const uint64_t t3 = t1 | t2;
            return t3;
        }
        // code=0xd2, function=((not (B) and C) xor A), lowered=((not (B) and C) xor A), set=automat
        template<> uint64_t ternary<0xd2>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = t0 & C;
            const uint64_t t2 = t1 ^ A;
            return t2;
        }
        // code=0xd3, function=((not (C) and A) or (A xor (B xor 1))), lowered=((not (C) and A) or (A xor (B xor 1))), set=automat
        template<> uint64_t ternary<0xd3>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = t0 & A;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t2 = B ^ c1;
            const uint64_t t3 = A ^ t2;
            const uint64_t t4 = t1 | t3;
            return t4;
        }
        // code=0xd4, function=((B and not (C)) or (A and (B xnor C))), lowered=((B and not (C)) or (A and not ((B xor C)))), set=optimized
        template<> uint64_t ternary<0xd4>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = B & t0;
            const uint64_t t2 = B ^ C;
            const uint64_t t3 = ~t2;
            const uint64_t t4 = A & t3;
            const uint64_t t5 = t1 | t4;
            return t5;
        }
        // code=0xd5, function=(not (C) or (A and B)), lowered=(not (C) or (A and B)), set=optimized
        template<> uint64_t ternary<0xd5>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = A & B;
            const uint64_t t2 = t0 | t1;
            return t2;
        }
        // code=0xd6, function=((A and B) or (B xor (A xor C))), lowered=((A and B) or (B xor (A xor C))), set=automat
        template<> uint64_t ternary<0xd6>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & B;
            const uint64_t t1 = A ^ C;
            const uint64_t t2 = B ^ t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xd7, function=(C nand (B xor A)), lowered=not ((C and (B xor A))), set=intel
        template<> uint64_t ternary<0xd7>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ A;
            const uint64_t t1 = C & t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0xd8, function=(C ? B : A), lowered=((C and B) or (not (C) and A)), set=intel
        template<> uint64_t ternary<0xd8>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C & B;
            const uint64_t t1 = ~C;
            const uint64_t t2 = t1 & A;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xd9, function=((B xnor C) or (A and B)), lowered=(not ((B xor C)) or (A and B)), set=optimized
        template<> uint64_t ternary<0xd9>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A & B;
            const uint64_t t3 = t1 | t2;
            return t3;
        }
        // code=0xda, function=((A and B) or (A xor C)), lowered=((A and B) or (A xor C)), set=automat
        template<> uint64_t ternary<0xda>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & B;
            const uint64_t t1 = A ^ C;
            const uint64_t t2 = t0 | t1;
            return t2;
        }
        // code=0xdb, function=((A xor C) or (A xor (B xor 1))), lowered=((A xor C) or (A xor (B xor 1))), set=automat
        template<> uint64_t ternary<0xdb>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ C;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = B ^ c1;
            const uint64_t t2 = A ^ t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xdc, function=((not (C) and A) or B), lowered=((not (C) and A) or B), set=automat
        template<> uint64_t ternary<0xdc>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = t0 & A;
            const uint64_t t2 = t1 | B;
            return t2;
        }
        // code=0xdd, function=(B or not (C)), lowered=(B or not (C)), set=intel
        template<> uint64_t ternary<0xdd>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = B | t0;
            return t1;
        }
        // code=0xde, function=(B or (A xor C)), lowered=(B or (A xor C)), set=intel
        template<> uint64_t ternary<0xde>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ C;
            const uint64_t t1 = B | t0;
            return t1;
        }
        // code=0xdf, function=(B or (A nand C)), lowered=(B or not ((A and C))), set=intel
        template<> uint64_t ternary<0xdf>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = B | t1;
            return t2;
        }
        // code=0xe0, function=(A and (B or C)), lowered=(A and (B or C)), set=intel
        template<> uint64_t ternary<0xe0>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = A & t0;
            return t1;
        }
        // code=0xe1, function=(A xnor (B or C)), lowered=not ((A xor (B or C))), set=intel
        template<> uint64_t ternary<0xe1>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = A ^ t0;
            const uint64_t t2 = ~t1;
            return t2;
        }
        // code=0xe2, function=(B ? A : C), lowered=((B and A) or (not (B) and C)), set=intel
        template<> uint64_t ternary<0xe2>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & A;
            const uint64_t t1 = ~B;
            const uint64_t t2 = t1 & C;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xe3, function=((A and C) or (A xor (B xor 1))), lowered=((A and C) or (A xor (B xor 1))), set=automat
        template<> uint64_t ternary<0xe3>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = B ^ c1;
            const uint64_t t2 = A ^ t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xe4, function=(C ? A : B), lowered=((C and A) or (not (C) and B)), set=intel
        template<> uint64_t ternary<0xe4>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C & A;
            const uint64_t t1 = ~C;
            const uint64_t t2 = t1 & B;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xe5, function=((A and B) or (A xor (C xor 1))), lowered=((A and B) or (A xor (C xor 1))), set=automat
        template<> uint64_t ternary<0xe5>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & B;
            const uint64_t c1 = uint64_t(-1);
            const uint64_t t1 = C ^ c1;
            const uint64_t t2 = A ^ t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xe6, function=((A and B) or (B xor C)), lowered=((A and B) or (B xor C)), set=automat
        template<> uint64_t ternary<0xe6>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & B;
            const uint64_t t1 = B ^ C;
            const uint64_t t2 = t0 | t1;
            return t2;
        }
        // code=0xe7, function=((B xor C) or (not (A) xor C)), lowered=((B xor C) or (not (A) xor C)), set=optimized
        template<> uint64_t ternary<0xe7>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = ~A;
            const uint64_t t2 = t1 ^ C;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xe8, function=((B and C) or (A and (B xor C))), lowered=((B and C) or (A and (B xor C))), set=optimized
        template<> uint64_t ternary<0xe8>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t t1 = B ^ C;
            const uint64_t t2 = A & t1;
            const uint64_t t3 = t0 | t2;
            return t3;
        }
        // code=0xe9, function=((not (A) xor (B xor C)) or (A and B)), lowered=((not (A) xor (B xor C)) or (A and B)), set=optimized
        template<> uint64_t ternary<0xe9>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = B ^ C;
            const uint64_t t2 = t0 ^ t1;
            const uint64_t t3 = A & B;
            const uint64_t t4 = t2 | t3;
            return t4;
        }
        // code=0xea, function=(C or (B and A)), lowered=(C or (B and A)), set=intel
        template<> uint64_t ternary<0xea>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & A;
            const uint64_t t1 = C | t0;
            return t1;
        }
        // code=0xeb, function=(C or (B xnor A)), lowered=(C or not ((B xor A))), set=intel
        template<> uint64_t ternary<0xeb>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ A;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = C | t1;
            return t2;
        }
        // code=0xec, function=(B or (A and C)), lowered=(B or (A and C)), set=intel
        template<> uint64_t ternary<0xec>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A & C;
            const uint64_t t1 = B | t0;
            return t1;
        }
        // code=0xed, function=(B or (A xnor C)), lowered=(B or not ((A xor C))), set=intel
        template<> uint64_t ternary<0xed>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = A ^ C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = B | t1;
            return t2;
        }
        // code=0xee, function=(C or B), lowered=(C or B), set=intel
        template<> uint64_t ternary<0xee>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C | B;
            return t0;
        }
        // code=0xef, function=(not (A) or (B or C)), lowered=(not (A) or (B or C)), set=optimized
        template<> uint64_t ternary<0xef>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~A;
            const uint64_t t1 = B | C;
            const uint64_t t2 = t0 | t1;
            return t2;
        }
        // code=0xf0, function=A, lowered=A, set=intel
        template<> uint64_t ternary<0xf0>(const uint64_t A, const uint64_t B, const uint64_t C) {
            return A;
        }
        // code=0xf1, function=(A or (B nor C)), lowered=(A or not ((B or C))), set=intel
        template<> uint64_t ternary<0xf1>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A | t1;
            return t2;
        }
        // code=0xf2, function=((not (B) and C) or A), lowered=((not (B) and C) or A), set=automat
        template<> uint64_t ternary<0xf2>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = t0 & C;
            const uint64_t t2 = t1 | A;
            return t2;
        }
        // code=0xf3, function=(A or not (B)), lowered=(A or not (B)), set=intel
        template<> uint64_t ternary<0xf3>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = A | t0;
            return t1;
        }
        // code=0xf4, function=((not (C) and B) or A), lowered=((not (C) and B) or A), set=automat
        template<> uint64_t ternary<0xf4>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = t0 & B;
            const uint64_t t2 = t1 | A;
            return t2;
        }
        // code=0xf5, function=(A or not (C)), lowered=(A or not (C)), set=intel
        template<> uint64_t ternary<0xf5>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = A | t0;
            return t1;
        }
        // code=0xf6, function=(A or (B xor C)), lowered=(A or (B xor C)), set=intel
        template<> uint64_t ternary<0xf6>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = A | t0;
            return t1;
        }
        // code=0xf7, function=(A or (B nand C)), lowered=(A or not ((B and C))), set=intel
        template<> uint64_t ternary<0xf7>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A | t1;
            return t2;
        }
        // code=0xf8, function=(A or (B and C)), lowered=(A or (B and C)), set=intel
        template<> uint64_t ternary<0xf8>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B & C;
            const uint64_t t1 = A | t0;
            return t1;
        }
        // code=0xf9, function=(A or (B xnor C)), lowered=(A or not ((B xor C))), set=intel
        template<> uint64_t ternary<0xf9>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B ^ C;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = A | t1;
            return t2;
        }
        // code=0xfa, function=(C or A), lowered=(C or A), set=intel
        template<> uint64_t ternary<0xfa>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = C | A;
            return t0;
        }
        // code=0xfb, function=(A or (not (B) or C)), lowered=(A or (not (B) or C)), set=optimized
        template<> uint64_t ternary<0xfb>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~B;
            const uint64_t t1 = t0 | C;
            const uint64_t t2 = A | t1;
            return t2;
        }
        // code=0xfc, function=(B or A), lowered=(B or A), set=intel
        template<> uint64_t ternary<0xfc>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | A;
            return t0;
        }
        // code=0xfd, function=(not (C) or (A or B)), lowered=(not (C) or (A or B)), set=optimized
        template<> uint64_t ternary<0xfd>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = ~C;
            const uint64_t t1 = A | B;
            const uint64_t t2 = t0 | t1;
            return t2;
        }
        // code=0xfe, function=(A or (B or C)), lowered=(A or (B or C)), set=intel
        template<> uint64_t ternary<0xfe>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t t0 = B | C;
            const uint64_t t1 = A | t0;
            return t1;
        }
        // code=0xff, function=1, lowered=1, set=intel
        template<> uint64_t ternary<0xff>(const uint64_t A, const uint64_t B, const uint64_t C) {
            const uint64_t c1 = uint64_t(-1);
            return c1;
        }

    } // namespace sse

} // namespace ternarylogic

// eof
