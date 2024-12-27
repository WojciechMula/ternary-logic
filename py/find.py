import sys
from os.path import dirname, join, realpath
from lib.ast import *
from itertools import chain

def arguments():
    yield (Variable('A'), Variable('B'))
    yield (Variable('A'), Variable('C'))
    yield (Variable('B'), Variable('C'))
    yield (Variable('A'), Negation(Variable('B')))
    yield (Variable('A'), Negation(Variable('C')))
    yield (Variable('B'), Negation(Variable('C')))
    yield (Negation(Variable('A')), Variable('B'))
    yield (Negation(Variable('A')), Variable('C'))
    yield (Negation(Variable('B')), Variable('C'))
    yield (Variable('A'), Constant(True))
    yield (Variable('B'), Constant(True))
    yield (Variable('C'), Constant(True))

def variables():
    yield Constant(False)
    yield Constant(True)
    yield Variable('A')
    yield Variable('B')
    yield Variable('C')
    yield Negation(Variable('A'))
    yield Negation(Variable('B'))
    yield Negation(Variable('C'))

def ops():
    yield 'and'
    yield 'or'
    yield 'xor'

def two_ops():
    for op1 in ops():
        for op2 in ops():
            yield (op1, op2)

def three_ops():
    for op1 in ops():
        for op2 in ops():
            for op3 in ops():
                yield (op1, op2, op3)

def three_pairs_of_args():
    for arg1 in arguments():
        for arg2 in arguments():
            for arg3 in arguments():
                yield (arg1, arg2, arg3)

def two_pairs_of_args():
    for arg1 in arguments():
        for arg2 in arguments():
            yield (arg1, arg2)


def functions_3levels():
    for level0 in ops():
        for level1 in two_ops():
            for level2 in three_ops():
                for args in three_pairs_of_args():
                    op2_0 = Binary(level2[0], args[0][0], args[0][1])
                    op2_1 = Binary(level2[1], args[1][0], args[1][1])
                    op2_2 = Binary(level2[2], args[2][0], args[2][1])

                    op1_0 = Binary(level1[0], op2_0, op2_1)
                    op1_1 = Binary(level1[1], op2_1, op2_2)

                    op_0 = Binary(level0, op1_0, op1_1)

                    yield op_0


def functions_2levels():
    for level0 in ops():
        for level1 in two_ops():
            for args in three_pairs_of_args():
                op1_0 = Binary(level1[0], args[0][0], args[0][1])
                op1_1 = Binary(level1[1], args[1][0], args[1][1])

                op_0 = Binary(level0, op1_0, op1_1)

                yield op_0


def functions_1level():
    for op in ops():
        for arg0, arg1 in arguments():
            yield Binary(op, arg0, arg1)


def conditions():
    processed = set()
    functions = []
    for fun in chain(variables(), functions_1level(), functions_2levels()):
        expr  = simplify(fun)
        index = expr.bin()
        if index not in processed:
            processed.add(index)
            functions.append(expr)

    for var in [Variable('A'), Variable('B'), Variable('C')]:
        for t in functions:
            for f in functions:
                yield Condition(var, t, f)


from lib.bodygen import BodyGenerator
from lib.load import load
from lib.simplify import simplify


Target_SSE      = 10
Target_AVX2     = 20
Target_XOP      = 30
Target_NEON     = 70

def parse_args(args):
    from optparse import OptionParser

    parser = OptionParser()

    parser.add_option(
        "--target",
        help="choose target (SSE, AVX2, XOP, NEON)"
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
    elif options.target.lower() == 'xop':
        options.target = Target_XOP
    elif options.target.lower() == 'neon':
        options.target = Target_NEON
    else:
        valid = ('sse', 'avx2', 'xop', 'neon')
        parser.error("--target expects: %s" % ', '.join(valid))

    return options


def get_file(name, mode='rt'):
    dir = dirname(realpath(__file__))

    return open(join(dir, name), mode)


class Application:
    def __init__(self, options, functions):
        self.options   = options
        self.functions = functions

        if self.options.target == Target_SSE:
            from lib.lowering_sse   import transform
            from lib.assembler_sse  import AssemblerSSE as AssemblerClass
            self.transform = transform
            self.AssemblerClass = AssemblerClass
        elif self.options.target == Target_AVX2:
            from lib.lowering_sse   import transform
            from lib.assembler_avx2 import AssemblerAVX2 as AssemblerClass
            self.transform = transform
            self.AssemblerClass = AssemblerClass
        elif self.options.target == Target_XOP:
            from lib.lowering_xop   import transform
            from lib.assembler_xop  import AssemblerXOP as AssemblerClass
            self.transform = transform
            self.AssemblerClass = AssemblerClass
        elif self.options.target == Target_NEON:
            from lib.lowering_neon  import transform
            from lib.assembler_neon import AssemblerNEON as AssemblerClass
            self.transform = transform
            self.AssemblerClass = AssemblerClass


        self.improved = set()


    def run(self):
        self.load()
        self.find_better()
        self.save()


    def pick_best(self, path):
        with get_file(path, 'rt') as f:
            tmp = load(f)
            for index, (string, expr) in tmp.items():
                root = self.transform(expr)
                gen  = BodyGenerator(root, self.AssemblerClass())
                body = gen.run()
                if index not in self.data:
                   self.data[index] = (root, body)
                elif len(body) < len(self.data[index]):
                   self.data[index] = (root, body)


    def load(self):
        self.data = {}
        paths = ('data/intel.txt', 'data/manually_optimized.txt', 'data/sse_and_avx2.txt')
        for path in paths:
            self.pick_best(path)


    def find_better(self):
        processed = set()
        for fun in self.functions:

            simpl = simplify(fun)
            r     = repr(simpl)
            if r in processed:
                continue

            processed.add(r)

            root  = self.transform(simpl)
            gen   = BodyGenerator(root, self.AssemblerClass())
            body  = gen.run()
            index = fun.bin()
            if len(body) < len(self.data[index][1]):
                print()
                print("improved %02x (%s):" % (index, root))
                print("was:")
                print("\n".join(self.data[index][1]))
                print("better:")
                print("\n".join(body))
                print()
                self.data[index] = (root, body)
                self.improved.add(index)


    def save(self):
        if not self.improved:
            return

        with open(self.options.filename, 'wt') as file:
            for index in sorted(self.improved):
                expr = self.data[index][0]
                file.write('# %s\n' % expr)
                file.write('%02x %r\n' % (index, expr))


def main():
    options = parse_args(sys.argv)
    
    if options.target == Target_XOP:
        functions = conditions()
    else:
        functions = chain(functions_1level(), functions_2levels(), functions_3levels())

    app = Application(options, functions)
    app.run()


if __name__ == '__main__':
    main()

