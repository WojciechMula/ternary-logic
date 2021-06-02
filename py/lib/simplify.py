from ast import *

def simplify(root):

    if isinstance(root, (Constant, Variable)):
        return root

    if isinstance(root, Negation):
        v = simplify(root.value)
        if isinstance(v, Constant):
            return Constant(not v.value)

        if isinstance(v, Negation):
            return v.value # not (not x) = x

        return Negation(v)

    if isinstance(root, Binary):
        a = simplify(root.a)
        b = simplify(root.b)
        if root.op in set(('or', 'and', 'xor', 'notand', 'notor')):
            if isinstance(a, Variable) and isinstance(b, Variable) and a.var == b.var:
                
                if root.op in ('or', 'and'):
                    return a # x or x = x, also x and x = x
                elif root.op in ('xor', 'notand', 'notor'):
                    return Constant(False) # x xor x = 0

            if isinstance(a, Constant) and isinstance(b, Constant):
                if root.op == 'or':
                    return Constant(a.value or b.value)
                elif root.op == 'and':
                    return Constant(a.value and b.value)
                elif root.op == 'xor':
                    return Constant((a.value and not b.value) or (not a.value and b.value))
            
            if isinstance(a, Constant):
                if root.op == 'or':
                    if a.value:
                        return Constant(True)   # x or 1 = 1
                    else:
                        return b                # x or 0 = x

                if root.op == 'and':
                    if a.value:
                        return b                # x and 1 = x
                    else:
                        return Constant(False)  # x and 0 = 0

                if root.op == 'xor':
                    if a.value:
                        return Negation(b)      # x xor 1 = not x
                    else:
                        return b                # x and 0 = x

            if isinstance(b, Constant):

                if root.op == 'or':
                    if b.value:
                        return Constant(True)
                    else:
                        return a

                if root.op == 'and':
                    if b.value:
                        return a
                    else:
                        return Constant(False)

                if root.op == 'xor':
                    if b.value:
                        return Negation(a)
                    else:
                        return a

            return Binary(root.op, a, b)

    if isinstance(root, Condition):

        var   = simplify(root.var)
        true  = simplify(root.true)
        false = simplify(root.false)

        if isinstance(var, Constant):
            if var.value:
                return true
            else:
                return false

        return Condition(var, true, false)

    assert False, root
