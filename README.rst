================================================================================
               Ternary functions for SSE and AVX2
================================================================================


Introduction
--------------------------------------------------

AVX512F introduced instruction ``vpternlog`` (intrinsic__
``_mm512_ternarylogic_epi{32,64}``), which evaluates a three-argument
boolean function for each bit of operands.  The function is given as
**an integer number** from 0 to 255.

__ https://software.intel.com/sites/landingpage/IntrinsicsGuide/#

This repository contains a kind of library which allows a programmer to
use ternary functions in SSE, XOP__, AVX2 and x86 in similar manner, by
choosing the function by its number.

__ https://en.wikipedia.org/wiki/XOP_instruction_set

In native AVX512F code you would write::

    // 0x96 = A xor B xor C
    const __m512i res = _mm512_ternarylogic_epi32(A, B, C, 0x96);

With help of the library you can write an AVX2 program::

    const __m256i res = ternarylogic::avx2::ternary<0x96>(A, B, C);

or a SSE program::

    const __m128i res = ternarylogic::sse::ternary<0x96>(A, B, C);


Details
--------------------------------------------------

The function number comes from the result column of the function's truth
table.  The number is formed from bits a, b, ... h. You can find more
details and examples in `my article`__.

__ http://0x80.pl/articles/avx512-ternary-functions.html

+---+---+---+----------+
| A | B | C | function |
+---+---+---+----------+
| 0 | 0 | 0 |    a     |
+---+---+---+----------+
| 0 | 0 | 1 |    b     |
+---+---+---+----------+
| 0 | 1 | 0 |    c     |
+---+---+---+----------+
| 0 | 1 | 1 |    d     |
+---+---+---+----------+
| 1 | 0 | 0 |    e     |
+---+---+---+----------+
| 1 | 0 | 1 |    f     |
+---+---+---+----------+
| 1 | 1 | 0 |    g     |
+---+---+---+----------+
| 1 | 1 | 1 |    h     |
+---+---+---+----------+


Intel has published list of all functions in form of logical expression
in their `monumental document`__ "Intel® 64 and IA-32 Architectures
Software Developer’s Manual Volume 2 (2A, 2B, 2C & 2D): Instruction Set
Reference, A-Z".

__ http://www.intel.com/content/www/us/en/processors/architectures-software-developer-manuals.html

I extracted these functions and created application which generates SSE
and AVX2 code. List of function is in the file ``py/data/intel.txt``,
I also put there more details. Later I manually optimized some of these
function. And in the end I developed a program which found many better
representations of functions for both Intel and AMD flavours of SIMD
ISA.


Usage
-----------------------------------------------------------

You need ``python`` and ``make``.

Type ``make``, then following files will be generated:

* ``ternary_sse.cpp``,
* ``ternary_avx2.cpp``,
* ``ternary_avx512.cpp`` (use only two-argument logic instructions),
* ``ternary_xop.cpp``,
* ``ternary_x86_32.cpp``,
* ``ternary_x86_64.cpp``.

You can include them directly into your application.

Programs ``validate_sse``, ``validate_avx2`` and ``validate_xop``
test if all generated functions are correct.


See also
-----------------------------------------------------------

* **Samuel Neves** (@sneves) published cool C++ library for
  dealing with function numbers using constexpr. Check it out.
  https://github.com/sneves/avx512-utils
