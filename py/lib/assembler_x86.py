from lib.assembler import Assembler


class AssemblerX86(Assembler):
    def __init__(self, base_type):
        Assembler.__init__(self)
        self.type = base_type
        self.const_type = 'const %s' % (self.type)

    def add_false(self):
        var  = 'c0'
        expr = '%s %s = 0;' % (self.const_type, var)

        return (var, expr)

    def add_true(self):
        var  = 'c1'
        expr = '%s %s = %s(-1);' % (self.const_type, var, self.type)

        return (var, expr)

    def add_and(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = %s & %s;' % (self.const_type, var, var1, var2)

        return (var, expr)

    def add_or(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = %s | %s;' % (self.const_type, var, var1, var2)

        return (var, expr)

    def add_xor(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = %s ^ %s;' % (self.const_type, var, var1, var2)

        return (var, expr)

    def add_negation(self, var1):
        var  = self.get_var()
        expr = '%s %s = ~%s;' % (self.const_type, var, var1)

        return (var, expr)

    def add_condition(self, cond, var1, var2):
        var  = self.get_var()
        expr = '%s %s = (%s & %s) | (~%s & %s);' % (self.const_type, var, cond, var1, cond, var2)

        return (var, expr)


class AssemblerX86_64(AssemblerX86):
    def __init__(self):
        AssemblerX86.__init__(self, 'uint64_t')


class AssemblerX86_32(AssemblerX86):
    def __init__(self):
        AssemblerX86.__init__(self, 'uint32_t')
