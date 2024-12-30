class Lexer:
    def __init__(self, string):
        self.string = string
        self.index  = 0

    def peek(self):
        try:
            return self.string[self.index]
        except IndexError:
            return ''

    def consume(self):
        c = self.peek()
        self.index += 1
        return c

    def startswith(self, s):
        return self.string[self.index:self.index + len(s)] == s

    def skip(self, n):
        self.index += n
        assert self.index <= len(self.string)

    def eof(self):
        return self.index == len(self.string)

    def __repr__(self):
        return '<Lexer str="%s">' % self.string
