from ast import *

def transform_binary(root):

    if isinstance(root, (Constant, Variable)):
        return root

    if isinstance(root, Binary):
        a = transform_binary(root.a)
        b = transform_binary(root.b)

        if root.op in ('xor', 'notand', 'notor'):
            return Binary(root.op, a, b)
        elif root.op == 'or':
            # exploiting existence of the notor instruction
            if isinstance(a, Negation):
                return Binary('notor', a.value, b)
            elif isinstance(b, Negation):
                return Binary('notor', b.value, a)
            else:
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
        # express condition as logic expression x?y:z <=> (x and y) or (not x and y)
        var   = transform_binary(root.var)
        true  = transform_binary(root.true)
        false = transform_binary(root.false)

        t1 = Binary('and', var, true)
        t2 = Binary('and', Negation(var), false)
        t3 = Binary('or', t1, t2)
        return transform(t3)

    if isinstance(root, Negation):
        return Negation(transform_binary(root.value))

    assert False, root


def transform(root):
    return transform_binary(root)
    # root = transform_binary(root)

    # return transform_negations(root)
