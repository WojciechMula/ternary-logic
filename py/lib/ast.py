class Node:
    pass


class Constant(Node):
    def __init__(self, value):
        self.value = bool(value)

    def __str__(self):
        return str(int(self.value))


class Negation(Node):
    def __init__(self, value):
        self.value = value

    def __str__(self):
        return 'not (%s)' % self.value


class Variable(Node):
    def __init__(self, var):
        self.var = var

    def __str__(self):
        return self.var


class Binary(Node):
    def __init__(self, op, a, b):
        self.op = op
        self.a  = a
        self.b  = b

    def __str__(self):
        return '(%s %s %s)' % (self.a, self.op, self.b)


class Condition(Node):
    def __init__(self, var, true, false):
        self.var   = var
        self.true  = true
        self.false = false

    def __str__(self):
        return '(%s ? %s : %s)' % (self.var, self.true, self.false)

