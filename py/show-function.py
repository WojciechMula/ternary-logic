s = """
A B C  x          A / BC 00 01 11 10
----- ---         ------------------
0 0 0  %(a)d              0 | %(a)d  %(b)d  %(d)d  %(c)d
0 0 1  %(b)d              1 | %(e)d  %(f)d  %(h)d  %(g)d
0 1 0  %(c)d
0 1 1  %(d)d
1 0 0  %(e)d
1 0 1  %(f)d
1 1 0  %(g)d
1 1 1  %(h)d
"""

import sys

d = int(sys.argv[1], 16)

assert d >= 0
assert d < 256

def bit(d, i):
    return int((d & (1 << i)) != 0)

M = {
    'a': bit(d, 0),
    'b': bit(d, 1),
    'c': bit(d, 2),
    'd': bit(d, 3),
    'e': bit(d, 4),
    'f': bit(d, 5),
    'g': bit(d, 6),
    'h': bit(d, 7),
}
print s % M
