class Assembler:
    "Basic assembly utils"
    def __init__(self):
        self.varnumber = 0


    def get_var(self):
        var = 't%d' % (self.varnumber)
        self.varnumber += 1
        
        return var

    def add_true(self):
        raise ValueError("unsupported")

    def add_false(self):
        raise ValueError("unsupported")

    def add_and(self, var1, var2):
        raise ValueError("unsupported")

    def add_or(self, var1, var2):
        raise ValueError("unsupported")

    def add_xor(self, var1, var2):
        raise ValueError("unsupported")

    def add_notand(self, var1, var2):
        raise ValueError("unsupported")

    def add_not(self, var):
        raise ValueError("unsupported")

    def add_negation(self, var):
        raise ValueError("unsupported")
