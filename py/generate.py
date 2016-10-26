import sys
import lib
from os.path import dirname, join, realpath
from lib.load import load


Language_CPP    = 1
Language_C      = 2

Target_SSE      = 10
Target_AVX2     = 20
Target_X86      = 30


def main():
    options = parse_args(sys.argv)   
    execute(options)


def parse_args(args):
    from optparse import OptionParser

    parser = OptionParser()
    parser.add_option(
        "--language",
        help="choose language (C++/CPP or C)"
    )

    parser.add_option(
        "--target",
        help="choose target (SSE, AVX2, x86)"
    )

    parser.add_option(
        "--name",
        default="ternary",
        help="function pattern name"
    )

    (options, rest) = parser.parse_args(args)
    if options.language is None:
        parser.error("--language is required")
    if options.target is None:
        parser.error("--target is required")

    if options.language.lower() in ('cpp', 'c++'):
        options.language = Language_CPP
    elif options.language.lower() in ('c'):
        options.language = Language_C
    else:
        valid = ('cpp', 'c++', 'c')
        parser.error("--language expects: %s" % ', '.join(valid))

    if options.target.lower() == 'sse':
        options.target = Target_SSE
    elif options.target.lower() == 'avx2':
        options.target = Target_AVX2
    elif options.target.lower() == 'x86':
        options.target = Target_X86
    else:
        valid = ('sse', 'avx2', 'x86')
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
        import lib.assembler_sse

        if self.options.target == Target_SSE:
            self.lowering   = lib.lowering_sse.transform
            self.assembler  = lib.assembler_sse.AssemblerSSE

        elif self.options.target == Target_AVX2:
            pass

        elif self.options.target == Target_X86:
            pass

        if self.options.language == Language_CPP:
            with get_file('cpp.function') as f:
                self.function_pattern = f.read()

            with get_file('cpp.pattern') as f:
                self.file_pattern = f.read()

            self.global_indent = get_indent(self.file_pattern, '%(FUNCTIONS)s')
            self.body_indent   = get_indent(self.function_pattern, '%(BODY)s')

        elif self.options.language == Language_C:
            pass
        else:
            assert False


    def load(self):
        with get_file('intel.txt', 'rt') as f:
            self.data = load(f)

            assert(len(self.data) == 256)


    def generate_single(self, code, expr):

        lowered = self.lowering(expr)
        comment = "code=0x%02x, function=%s, lowered=%s" % (code, expr, lowered)

        from lib.generate import Generator
        g = Generator(lowered, self.assembler())
        body = g.run()

        params = {
            'TYPE'  : self.assembler().type,
            'NAME'  : self.options.name,
            'CODE'  : code,
            'BODY'  : indent_lines(body, self.body_indent),
            'COMMENT' : comment
        }

        return self.function_pattern % params


    def generate(self):
        result = ''
        for code in xrange(256):
            expr = self.data[code][1]
            if expr:
                result += self.generate_single(code, expr)

        params = {
            'FUNCTIONS' : indent_lines(result.splitlines(), self.global_indent)
        }

        return self.file_pattern % params


    run = generate

def execute(options):

    gen = CodeGenerator(options)
    print gen.run()


if __name__ == '__main__':
    main()

