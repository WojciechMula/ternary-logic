from os.path import dirname, join, realpath
from pathlib import Path
from io import StringIO
import argparse
import pickle
import re

import lib.lowering_sse
import lib.lowering_xop
import lib.lowering_x86
import lib.lowering_neon
import lib.assembler_sse
import lib.assembler_avx2
import lib.assembler_avx512
import lib.assembler_xop
import lib.assembler_x86
import lib.assembler_neon
from lib.bodygen import BodyGenerator
from lib.load import load


def main():
    options = parse_args()
    execute(options)


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "-o",
        required=True,
        type=Path,
        dest="filename",
        help="output file"
    )

    return parser.parse_args()


def get_file(name, mode='rt'):
    dir = dirname(realpath(__file__))

    return open(join(dir, name), mode)


class CodeGenerator:
    def __init__(self, options):
        self.options = options
        self.load()

    def load(self):
        self.data = {}
        with get_file('data/intel.txt', 'rt') as f:
            self.data['intel'] = load(f)

            assert len(self.data['intel']) == 256

        paths = {
            'optimized': 'data/manually_optimized.txt',
            'automat'  : 'data/sse_and_avx2.txt',
            'xop'      : 'data/xop.txt',
        }

        for name, path in paths.items():
            with get_file(path, 'rt') as f:
                self.data[name] = load(f)

    def generate_single(self, lowering, assembler_class, code, expr, source):
        lowered = lowering(expr)

        g = BodyGenerator(lowered, assembler_class())
        body = g.run()

        return (len(body), (body, lowered))

    def parameters(self):
        return [
            ("sse", lib.lowering_sse.transform, lib.assembler_sse.AssemblerSSE),
            ("avx2", lib.lowering_sse.transform, lib.assembler_avx2.AssemblerAVX2),
            ("avx512", lib.lowering_sse.transform, lib.assembler_avx512.AssemblerAVX512),
            ("x86_64", lib.lowering_x86.transform, lib.assembler_x86.AssemblerX86_64),
            ("x86_32", lib.lowering_x86.transform, lib.assembler_x86.AssemblerX86_32),
            ("xop", lib.lowering_xop.transform, lib.assembler_xop.AssemblerXOP),
            ("neon", lib.lowering_neon.transform,  lib.assembler_neon.AssemblerNEON),
        ]

    def generate_code(self):
        cache = Path("/dev/shm/ternary-logic.dat")
        if cache.exists():
            print(f"loading from {cache}")
            with cache.open('rb') as f:
                return pickle.load(f)

        data = self.generate_code_aux()
        with cache.open('wb') as f:
            print(f"storing cache {cache}")
            pickle.dump(data, f)

        return data

    def generate_code_aux(self):
        res = {}
        for (target, lowering, assembler_class) in self.parameters():
            res[target] = []
            for code in range(256):
                # It is rather unlikely that a 3-argument function would be expressed
                # by more than one million instructions. :)
                weight = 1e10
                src    = None

                for name in self.data:
                    if code not in self.data[name]:
                        continue

                    expr = self.data[name][code][1]
                    if not expr:
                        continue

                    w, s = self.generate_single(lowering, assembler_class, code, expr, name)
                    if w < weight:
                        weight = w
                        src    = s

                assert src is not None
                item = Struct()
                item.source = src[0]
                item.lowered = src[1]
                item.expression = expr
                res[target].append(item)

        return res

    def run(self):
        data = self.generate_code()
        f = StringIO()

        write = f.write

        def writeln(s):
            write(s + '\n')

        writeln(HEAD)

        write_menu(f)

        writeln('<div id="content">')
        writeln("<h1>Ternary functions</h1>")

        for code in range(256):
            writeln(f'<a name="fn{code}"></a>')
            writeln('<div class="group">')
            write_details(f, code, data)
            writeln('</div>')

        write_comparison_table(f, data)
        writeln('</div>')

        writeln(TAIL)

        return f.getvalue()


def write_menu(f):
    write = f.write

    def writeln(s):
        write(s + '\n')

    writeln('<div id="menu">')
    writeln('<a name="codes"></a>')
    writeln('<p>1. Ternary function by code</p>')
    for code in range(0, 256):
        write(f' <a href="#fn{code}"><tt>{code:02x}</tt></a>')

    write('<p>')
    write('<input type="checkbox" id="expand-all">Expand all implementations</input>')
    write('<br/>')
    write('<input type="checkbox" id="truth-table">Show truth tables</input>')
    writeln('</p>')

    writeln('<p>2. <a href="#comparison">Number of instructions</a></p>')
    writeln('</div>')


hidden = ' style="display:none"'


def write_details(f, code, data):
    write = f.write

    def writeln(s):
        write(s + '\n')

    all_details = first(data.values())
    details = all_details[code]
    writeln("<h2>0x%02x &mdash; %s</h2>" % (code, details.expression))

    writeln('<table>')
    writeln('<tr><td valign="top">')
    write_truth_table(f, code)
    writeln('</td><td valign="top">')

    for id, (target, all_details) in enumerate(data.items()):
        details = all_details[code]
        label   = target_name[target]

        selected = "";
        if id > 0:
            selected = ' selected'

        writeln(f'<button class="select {target} fn{code}{selected}" id="sel-{target}-fn{code}">{label}</button>')

    for id, (target, all_details) in enumerate(data.items()):
        details = all_details[code]
        label   = target_name[target]
        writeln(f'<h3 class="label"{hidden}>{label}</h3>')
        style = ''
        if id > 0:
            style = hidden

        writeln(f'<div class="data {target} fn{code}"{style}>')
        writeln(f'<p class="lowered">f(A, B, C) = {details.lowered}</p>')
        writeln('<pre>')
        for line in details.source:
            writeln(highlight_code(line))
        writeln('</pre>')
        writeln('</div>')

    writeln('</td></tr>')
    writeln('</table>')


def write_truth_table(f, code):
    write = f.write

    def writeln(s):
        write(s + '\n')

    writeln(f'<table class="truth-table" border="1px" cellspacing="0" cellpadding="3px"{hidden}>')
    writeln('<thead>')
    writeln('<tr><td>A</td><td>B</td><td>C</td><td>f(A, B, C)</td></tr>')
    writeln('</thead>')
    writeln('<tbody>')
    for i in range(8):
        A = (i >> 2) & 0x1
        B = (i >> 1) & 0x1
        C = i & 0x1
        f = (code >> i) & 0x1

        if f:
            cls = "one"
        else:
            cls = "zero"

        writeln(f'<tr class="{cls}"><td>{A}</td><td>{B}</td><td>{C}</td><td>{f}</td></tr>')

    writeln('</tbody>')
    writeln('</table>')


def write_comparison_table(f, data):
    write = f.write

    def writeln(s):
        write(s + '\n')

    writeln('<a name="comparison"></a>')
    writeln('<h2>Number of instructions</h2>')

    writeln('<table id="comparison-table" border="1px" cellspacing="0" cellpadding="5px">')
    writeln('<thead>')
    writeln('<tr>')
    writeln('<td>code</td>')
    writeln('<td>function</td>')
    for label in target_name.values():
        writeln(f'<td>{label}</td>')
    writeln('</tr>')
    writeln('</thead>')
    writeln('<tbody>')
    for code in range(256):
        if code % 2 == 0:
            cls = "even"
        else:
            cls = "odd"

        write(f'<tr class={cls}>')
        write(f'<td><a href="#fn{code}"><tt>{code:02x}</tt></a></td>')
        all_details = first(data.values())
        details = all_details[code]
        write(f'<td>{details.expression}</td>')
        for all_details in data.values():
            details = all_details[code]
            cost    = len(details.source) - 1
            write(f'<td>{cost}</td>')

        writeln('</tr>')

    writeln('</table>')


def first(iterable):
    return next(iter(iterable))


target_name = {
    "sse":      "SSE",
    "avx2":     "AVX2",
    "avx512":   "AVX512",
    "x86_64":   "x86 (64 bit)",
    "x86_32":   "x86 (32 bit)",
    "xop":      "AMD XOP",
    "neon":     "ARM Neon",
}


class Struct:
    pass


HEAD = """<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" type="text/css" href="ternary-logic.css"/>
    <script src="ternary-logic.js"></script>
</head>
<body>"""

TAIL = """</body>
</html>"""


# see: ternary-logic.css
KEYWORD  = 'k'
VARIABLE = 'v'
ARGUMENT = 'a'
TYPE     = 't'
NUMBER   = 'n'
FUNCTION = 'f'
KEEP     = object()

classes = {
    ''          : KEEP,
    ' '         : KEEP,
    ')'         : KEEP,
    '('         : KEEP,
    '|'         : KEEP,
    '~'         : KEEP,
    ','         : KEEP,
    '&'         : KEEP,
    ';'         : KEEP,
    '='         : KEEP,
    '^'         : KEEP,
    'const'     : KEYWORD,
    'return'    : KEYWORD,
    'A'         : ARGUMENT,
    'B'         : ARGUMENT,
    'C'         : ARGUMENT,
    'c0'        : VARIABLE,
    'c1'        : VARIABLE,
    't0'        : VARIABLE,
    't1'        : VARIABLE,
    't2'        : VARIABLE,
    't3'        : VARIABLE,
    't4'        : VARIABLE,
    't5'        : VARIABLE,
    't6'        : VARIABLE,
    't7'        : VARIABLE,
    '0'         : NUMBER,
    '-1'        : NUMBER,
    '__m128i'   : TYPE,
    '__m256i'   : TYPE,
    '__m512i'   : TYPE,
    'int32x4_t' : TYPE,
    'uint32_t'  : TYPE,
    'uint64_t'  : TYPE,
    '_mm256_and_si256'      : FUNCTION,
    '_mm256_andnot_si256'   : FUNCTION,
    '_mm256_or_si256'       : FUNCTION,
    '_mm256_set1_epi32'     : FUNCTION,
    '_mm256_setzero_si256'  : FUNCTION,
    '_mm256_xor_si256'      : FUNCTION,
    '_mm512_and_si512'      : FUNCTION,
    '_mm512_andnot_si512'   : FUNCTION,
    '_mm512_or_si512'       : FUNCTION,
    '_mm512_set1_epi32'     : FUNCTION,
    '_mm512_setzero_si512'  : FUNCTION,
    '_mm512_xor_si512'      : FUNCTION,
    '_mm_and_si128'         : FUNCTION,
    '_mm_andnot_si128'      : FUNCTION,
    '_mm_cmov_si128'        : FUNCTION,
    '_mm_or_si128'          : FUNCTION,
    '_mm_set1_epi32'        : FUNCTION,
    '_mm_setzero_si128'     : FUNCTION,
    '_mm_xor_si128'         : FUNCTION,
    'vandq_s32'             : FUNCTION,
    'vbicq_s32'             : FUNCTION,
    'vdupq_n_s32'           : FUNCTION,
    'veorq_s32'             : FUNCTION,
    'vmvnq_s32'             : FUNCTION,
    'vornq_s32'             : FUNCTION,
    'vorrq_s32'             : FUNCTION,
}

unknown = set()


def highlight_code(s):
    global unknown

    fragments = re.split('([ ()|;=~,])', s)
    for i in range(len(fragments)):
        frag = fragments[i]
        cls  = classes.get(frag)
        if cls is not None:
            if cls is not KEEP:
                fragments[i] = f'<span class="{cls}">{frag}</span>'
        else:
            unknown.add(frag)

    return ''.join(fragments)


def execute(options):
    gen = CodeGenerator(options)
    res = gen.run()
    with open(options.filename, 'wt') as f:
        f.write(res)
        print("%s created" % (options.filename))


if __name__ == '__main__':
    main()
    if unknown:
        print(list(sorted(unknown)))
        raise ValueError("not all program items properly detected")
