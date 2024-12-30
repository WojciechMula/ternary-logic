class Node:
    pass


class Constant(Node):
    def __init__(self, value):
        self.value = bool(value)

    def bin(self):
        if self.value:
            return 0xff
        else:
            return 0x00

    def __str__(self):
        return str(int(self.value))

    __repr__ = __str__


class Negation(Node):
    def __init__(self, value):
        self.value = value

    def bin(self):
        return self.value.bin() ^ 0xff

    def __str__(self):
        return 'not (%s)' % self.value

    def __repr__(self):
        return '!%r' % self.value


VAR = {
    'A': 0xf0,
    'B': 0xcc,
    'C': 0xaa
}


class Variable(Node):
    def __init__(self, var):
        self.var = var

    def bin(self):
        return VAR[self.var]

    def __str__(self):
        return self.var

    __repr__ = __str__


class Binary(Node):
    def __init__(self, op, a, b):
        self.op = op
        self.a  = a
        self.b  = b

    def bin(self):
        a = self.a.bin()
        b = self.b.bin()

        if self.op == 'and':
            return a & b

        if self.op == 'notand':
            return (a ^ 0xff) & b

        if self.op == 'or':
            return a | b

        if self.op == 'xor':
            return a ^ b

        assert False, self.op

    def __str__(self):
        return '(%s %s %s)' % (self.a, self.op, self.b)

    def __repr__(self):
        return '%s%r%r' % (self.op, self.a, self.b)


class Condition(Node):
    def __init__(self, var, true, false):
        self.var   = var
        self.true  = true
        self.false = false

    def bin(self):
        var   = self.var.bin()
        true  = self.true.bin()
        false = self.false.bin()

        return (var & true) | ((var ^ 0xff) & false)

    def __str__(self):
        return '(%s ? %s : %s)' % (self.var, self.true, self.false)

    def __repr__(self):
        return '%r?%r:%r' % (self.var, self.true, self.false)
