from lib.assembler_sse import AssemblerSSE

class AssemblerXOP(AssemblerSSE):

    def __init__(self):
        AssemblerSSE.__init__(self)

    def add_condition(self, cond, true, false):
        var  = self.get_var()
        expr = '%s %s = _mm_cmov_si128(%s, %s, %s);' % (self.const_type, var, true, false, cond)

        return (var, expr)
