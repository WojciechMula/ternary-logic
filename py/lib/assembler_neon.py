from lib.assembler import Assembler


class AssemblerNEON(Assembler):
    def __init__(self):
        Assembler.__init__(self)
        self.type = 'int32x4_t'
        self.const_type = 'const %s' % (self.type)

    def add_false(self):
        var  = 'c0'
        expr = '%s %s = vdupq_n_s32(0);' % (self.const_type, var)

        return (var, expr)

    def add_true(self):
        var  = 'c1'
        expr = '%s %s = vdupq_n_s32(-1);' % (self.const_type, var)

        return (var, expr)

    def add_and(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = vandq_s32(%s, %s);' % (self.const_type, var, var1, var2)

        return (var, expr)

    def add_or(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = vorrq_s32(%s, %s);' % (self.const_type, var, var1, var2)

        return (var, expr)

    def add_notor(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = vornq_s32(%s, %s);' % (self.const_type, var, var2, var1)

        return (var, expr)

    def add_xor(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = veorq_s32(%s, %s);' % (self.const_type, var, var1, var2)

        return (var, expr)

    def add_notand(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = vbicq_s32(%s, %s);' % (self.const_type, var, var2, var1)

        return (var, expr)

    def add_condition(self, cond, var1, var2):
        var  = self.get_var()
        expr = '%s %s = vbslq_s32(vreinterpretq_u32_s32(%s), %s, %s);' % (self.const_type, var, cond, var1, var2)

        return (var, expr)

    def add_negation(self, var1):
        var  = self.get_var()
        expr = '%s %s = vmvnq_s32(%s);' % (self.const_type, var, var1)

        return (var, expr)
