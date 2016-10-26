from ast import *

def transform(root):

    def negate(node):
        ones = Constant(True)
        val  = transform(node)
        return Binary('xor', val, ones)

    if isinstance(root, (Constant, Variable)):
        return root

    if isinstance(root, Binary):
        a = transform(root.a) 
        b = transform(root.b) 

        if root.op in ('or', 'xor'):
            return Binary(root.op, a, b)

        elif root.op == 'nor':
            return negate(Binary('or', a, b))
        elif root.op == 'nand':
            return negate(Binary('and', a, b))
        elif root.op == 'xnor':
            return negate(Binary('xor', a, b))
        elif root.op == 'and':
            if isinstance(a, Negation):
                return Binary('notand', a.value, b)
            elif isinstance(b, Negation):
                return Binary('notand', b.value, a)
            else:
                return Binary(root.op, a, b)

    if isinstance(root, Condition):
        var   = transform(root.var)
        true  = transform(root.true)
        false = transform(root.false)

        t1 = Binary('and', var, true)
        t2 = Binary('and', Negation(var), false)
        t3 = Binary('or', t1, t2)
        return transform(t3)

    if isinstance(root, Negation):
        return negate(transform(root.value))

    assert False, root
