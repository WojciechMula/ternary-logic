import sys
import lib
from os.path import dirname, join, realpath
from lib.load import load


Target_SSE      = 10
Target_AVX2     = 20
Target_XOP      = 30
Target_X86_64   = 40
Target_X86_32   = 50
Target_AVX512   = 60
Target_NEON     = 70


def main():
    options = parse_args(sys.argv)   
    execute(options)


def parse_args(args):
    from optparse import OptionParser

    parser = OptionParser()
    parser.add_option(
        "--target",
        help="choose target (SSE, AVX2, XOP, X86_64, X86_32, NEON)"
    )

    parser.add_option(
        "--name",
        default="ternary",
        help="function name"
    )

    parser.add_option(
        "-o",
        dest="filename",
        help="output file"
    )

    (options, rest) = parser.parse_args(args)
    if options.filename is None:
        parser.error("-o is required")

    if options.target is None:
        parser.error("--target is required")

    if options.target.lower() == 'sse':
        options.target = Target_SSE
    elif options.target.lower() == 'avx2':
        options.target = Target_AVX2
    elif options.target.lower() == 'avx512':
        options.target = Target_AVX512
    elif options.target.lower() == 'xop':
        options.target = Target_XOP
    elif options.target.lower() == 'x86_64':
        options.target = Target_X86_64
    elif options.target.lower() == 'x86_32':
        options.target = Target_X86_32
    elif options.target.lower() == 'neon':
        options.target = Target_NEON
    else:
        valid = ('sse', 'avx2', 'xop', 'x86_64', 'x86_32', 'avx512', 'neon')
        parser.error("--target expects: %s" % ', '.join(valid))

    return options


def get_indent(s, substring):
    lines = s.splitlines()
    for line in lines:
        p = line.find(substring)
        if p >= 0:
            return p

    return 0


def indent_lines(lines, indent):
    indent = ' ' * indent

    tmp = [lines[0]] + [indent + line for line in lines[1:]]

    return '\n'.join(tmp)


def get_file(name, mode='rt'):
    dir = dirname(realpath(__file__))

    return open(join(dir, name), mode)


class CodeGenerator:
    def __init__(self, options):
        self.options = options
        self.setup()
        self.load()


    def setup(self):
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

        if self.options.target == Target_SSE:
            self.lowering  = lib.lowering_sse.transform
            self.assembler_class = lib.assembler_sse.AssemblerSSE

        elif self.options.target == Target_AVX2:
            self.lowering = lib.lowering_sse.transform
            self.assembler_class = lib.assembler_avx2.AssemblerAVX2

        elif self.options.target == Target_AVX512:
            self.lowering = lib.lowering_sse.transform
            self.assembler_class = lib.assembler_avx512.AssemblerAVX512

        elif self.options.target == Target_XOP:
            self.lowering = lib.lowering_xop.transform
            self.assembler_class = lib.assembler_xop.AssemblerXOP

        elif self.options.target == Target_X86_64:
            self.lowering = lib.lowering_x86.transform
            self.assembler_class = lib.assembler_x86.AssemblerX86_64

        elif self.options.target == Target_X86_32:
            self.lowering = lib.lowering_x86.transform
            self.assembler_class = lib.assembler_x86.AssemblerX86_32

        elif self.options.target == Target_NEON:
            self.lowering = lib.lowering_neon.transform
            self.assembler_class = lib.assembler_neon.AssemblerNEON

        with get_file(self.get_function_file()) as f:
            self.function_pattern = f.read()

        with get_file(self.get_main_file()) as f:
            self.main_pattern = f.read()

        self.global_indent = get_indent(self.main_pattern, '%(FUNCTIONS)s')
        self.body_indent   = get_indent(self.function_pattern, '%(BODY)s')


    def get_main_file(self):
        if self.options.target == Target_SSE:
            return 'cpp.sse.main'
        elif self.options.target == Target_AVX2:
            return 'cpp.avx2.main'
        elif self.options.target == Target_AVX512:
            return 'cpp.avx512.main'
        elif self.options.target == Target_XOP:
            return 'cpp.xop.main'
        elif self.options.target == Target_X86_64:
            return 'cpp.x86_64.main'
        elif self.options.target == Target_X86_32:
            return 'cpp.x86_32.main'
        elif self.options.target == Target_NEON:
            return 'cpp.neon.main'
        else:
            assert False


    def get_function_file(self):
        return 'cpp.function'


    def load(self):
        self.data = {}
        with get_file('data/intel.txt', 'rt') as f:
            self.data['intel'] = load(f)

            assert(len(self.data['intel']) == 256)
            

        paths = {
            'optimized': 'data/manually_optimized.txt',
            'automat'  : 'data/sse_and_avx2.txt',
            'xop'      : 'data/xop.txt',
        }

        for name, path in paths.iteritems():
            with get_file(path, 'rt') as f:
                self.data[name] = load(f)


    def generate_single(self, code, expr, source):

        lowered = self.lowering(expr)
        comment = "code=0x%02x, function=%s, lowered=%s, set=%s" % (code, expr, lowered, source)

        from lib.bodygen import BodyGenerator
        g = BodyGenerator(lowered, self.assembler_class())
        body = g.run()

        params = {
            'TYPE'  : self.assembler_class().type,
            'NAME'  : self.options.name,
            'CODE'  : code,
            'BODY'  : indent_lines(body, self.body_indent),
            'COMMENT' : comment
        }

        return (len(body), self.function_pattern % params)


    def generate(self):
        result = ''
        for code in xrange(256):
            weight = 1e10 # It is rather unlikely that a 3-argument function would be expressed
                          # by more than one million instructions. :)
            src    = None

            for name in self.data:
                if code not in self.data[name]:
                    continue

                expr = self.data[name][code][1]
                if expr:
                    w, s = self.generate_single(code, expr, name)
                    if w < weight:
                        src    = s
                        weight = w
                        picked_set = name

            assert src is not None
            result += src

        params = {
            'TYPE'      : self.assembler_class().type,
            'FUNCTIONS' : indent_lines(result.splitlines(), self.global_indent)
        }

        return self.main_pattern % params


    run = generate

def execute(options):

    gen = CodeGenerator(options)
    res = gen.run()
    with open(options.filename, 'wt') as f:
        f.write(res)
        print "%s created" % (options.filename)


if __name__ == '__main__':
    main()

