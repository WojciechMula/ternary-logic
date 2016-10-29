# Transformations to XOP vcmov

from ast import *
from lowering_sse import transform_negations

def transform_binary(root):

    if isinstance(root, (Constant, Variable)):
        return root

    if isinstance(root, Binary):
        a = transform_binary(root.a)
        b = transform_binary(root.b)

        if root.op in ('or', 'xor'):
            return Binary(root.op, a, b)

        # nor/nand/xnor are not supported
        elif root.op == 'nor':
            return Negation(Binary('or', a, b))
        elif root.op == 'nand':
            return Negation(Binary('and', a, b))
        elif root.op == 'xnor':
            return Negation(Binary('xor', a, b))
        elif root.op == 'and':
            # exploiting existence of the notand instruction
            if isinstance(a, Negation):
                return Binary('notand', a.value, b)
            elif isinstance(b, Negation):
                return Binary('notand', b.value, a)
            else:
                return Binary(root.op, a, b)

    if isinstance(root, Condition):
        var   = transform_binary(root.var)
        true  = transform_binary(root.true)
        false = transform_binary(root.false)

        return Condition(var, true, false);

    if isinstance(root, Negation):
        return Negation(transform_binary(root.value))

    assert False, root


def transform(root):
    root = transform_binary(root)

    return transform_negations(root)
