from lib.assembler import Assembler


class AssemblerSSE(Assembler):
    def __init__(self):
        Assembler.__init__(self)
        self.type = '__m128i'
        self.const_type = 'const %s' % (self.type)

    def add_false(self):
        var  = 'c0'
        expr = '%s %s = _mm_setzero_si128();' % (self.const_type, var)

        return (var, expr)

    def add_true(self):
        var  = 'c1'
        expr = '%s %s = _mm_set1_epi32(-1);' % (self.const_type, var)

        return (var, expr)

    def add_and(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = _mm_and_si128(%s, %s);' % (self.const_type, var, var1, var2)

        return (var, expr)

    def add_or(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = _mm_or_si128(%s, %s);' % (self.const_type, var, var1, var2)

        return (var, expr)

    def add_xor(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = _mm_xor_si128(%s, %s);' % (self.const_type, var, var1, var2)

        return (var, expr)

    def add_notand(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = _mm_andnot_si128(%s, %s);' % (self.const_type, var, var1, var2)

        return (var, expr)
