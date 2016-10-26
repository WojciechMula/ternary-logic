import parser

def load(file):
    
    result = {}

    for k, line in enumerate(file):
        line = line.strip()

        # skip empty lines and comments
        if not line or line[0] == '#':
            continue

        f = line.split()
        assert(len(f) == 2)

        value  = int(f[0], 16)
        string = f[1]
        expr   = parser.parse(string)

        result[value] = (string, expr)

    return result
