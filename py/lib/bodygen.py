from ast import *

class BodyGenerator:
    def __init__(self, root, assembler):
        self.root = root
        self.program = []
        self.variables = {}
        self.assembler = assembler
        self.last   = None
        self.const0 = None
        self.const1 = None

    def emit(self, node):
        if node in self.variables:
            return self.variables[node]

        var  = None
        expr = None
        if isinstance(node, Constant):
            if node.value:
                if self.const1 is None:
                    var, expr = self.assembler.add_true()
                    self.const1 = var
                else:
                    var = self.const1
            else:
                if self.const0 is None:
                    var, expr = self.assembler.add_false()
                    self.const0 = var
                else:
                    var = self.const0

        elif isinstance(node, Variable):
            var = node.var

        elif isinstance(node, Negation):
            neg = self.emit(node.value)
            var, expr = self.assembler.add_negation(neg)

        elif isinstance(node, Binary):
            a = self.emit(node.a)
            b = self.emit(node.b)

            if node.op == 'and':
                var, expr = self.assembler.add_and(a, b)
            elif node.op == 'or':
                var, expr = self.assembler.add_or(a, b)
            elif node.op == 'xor':
                var, expr = self.assembler.add_xor(a, b)
            elif node.op == 'notand':
                var, expr = self.assembler.add_notand(a, b)
            else:
                assert False, "unsupported op=%s" % node.op

        elif isinstance(node, Condition):
            cond  = self.emit(node.var)
            true  = self.emit(node.true)
            false = self.emit(node.false)

            var, expr = self.assembler.add_condition(cond, true, false)

        assert var != None

        if expr:
            self.program.append(expr)

        self.variables[node] = var
        self.last = var
        return var


    def run(self):
        self.emit(self.root)
        self.program.append('return %s;' % self.last)

        return self.program
