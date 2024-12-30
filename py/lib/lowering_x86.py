# Transformations apply to x86 code

from lib.ast import Constant
from lib.ast import Variable
from lib.ast import Negation
from lib.ast import Binary
from lib.ast import Condition


def transform_binary(root):
    if isinstance(root, (Constant, Variable, Negation)):  # negations can be expressed in plain C/C++
        return root

    if isinstance(root, Binary):
        a = transform_binary(root.a)
        b = transform_binary(root.b)

        if root.op in ('or', 'xor', 'and'):
            return Binary(root.op, a, b)

        # nor/nand/xnor are not supported
        elif root.op == 'nor':
            return Negation(Binary('or', a, b))
        elif root.op == 'nand':
            return Negation(Binary('and', a, b))
        elif root.op == 'xnor':
            return Negation(Binary('xor', a, b))

    if isinstance(root, Condition):
        var   = transform_binary(root.var)
        true  = transform_binary(root.true)
        false = transform_binary(root.false)

        t1 = Binary('and', var, true)
        t2 = Binary('and', Negation(var), false)
        t3 = Binary('or', t1, t2)
        return transform(t3)

    assert False, root


def transform(root):
    return transform_binary(root)
