from lib.assembler import Assembler


class AssemblerAVX2(Assembler):
    def __init__(self):
        Assembler.__init__(self)
        self.type = '__m256i'
        self.const_type = 'const %s' % (self.type)

    def add_false(self):
        var  = 'c0'
        expr = '%s %s = _mm256_setzero_si256();' % (self.const_type, var)

        return (var, expr)

    def add_true(self):
        var  = 'c1'
        expr = '%s %s = _mm256_set1_epi32(-1);' % (self.const_type, var)

        return (var, expr)

    def add_and(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = _mm256_and_si256(%s, %s);' % (self.const_type, var, var1, var2)

        return (var, expr)

    def add_or(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = _mm256_or_si256(%s, %s);' % (self.const_type, var, var1, var2)

        return (var, expr)

    def add_xor(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = _mm256_xor_si256(%s, %s);' % (self.const_type, var, var1, var2)

        return (var, expr)

    def add_notand(self, var1, var2):
        var  = self.get_var()
        expr = '%s %s = _mm256_andnot_si256(%s, %s);' % (self.const_type, var, var1, var2)

        return (var, expr)

    def add_not(self, var):
        pass
