from lexer import Lexer
from ast import *

def expression(lexer):
    c = lexer.peek()

    if c in 'ABC':
        lexer.consume()
        v = Variable(c)

        if lexer.peek() == '?':
            lexer.consume()
            true = expression(lexer)

            assert(lexer.peek() == ':')
            lexer.consume()
            false = expression(lexer)

            assert(lexer.eof())

            return Condition(v, true, false)
        else:
            assert(lexer.eof)
            return v

    elif c == '!':
        lexer.consume()
        return Negation(expression(lexer))

    else:
        binary = ('and', 'or', 'xor', 'nand', 'nor', 'xnor')
        for op in binary:
            if lexer.startswith(op):
                lexer.skip(len(op))
                a = expression(lexer)
                b = expression(lexer)
                ret = Binary(op, a, b)

                if lexer.peek() in ['A', 'B', 'C']:
                    ret = Binary(op, Variable(lexer.peek()), ret)
                    lexer.consume()

                return ret


def parse(expr):
    if expr == 'TRUE':
        return Constant(True)

    if expr == 'FALSE':
        return Constant(False)

    L = Lexer(expr)
    return expression(L)

