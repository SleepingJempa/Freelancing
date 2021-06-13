[eq1, eq2] = input().split()

def num(s: str):
    if len(s) == 0:
        return 0
    if s in ['+', '-']:
        return int(s + '1')
    return int(s)

def eval(ex: str):
    x = ex.find('x')
    a, b, c = 0, 0, 0

    if x != -1:
        i = x-1
        s = ''
        while i >= 0 and ex[i+1] not in ['-', '+']:
            s = ex[i] + s
            i -= 1
        a = num(s)
        if a == 0: a = 1
        ex = ex[:i+1] + ex[x+1:]

    y = ex.find('y')

    if y != -1:
        i = y-1
        s = ''
        while i >= 0 and ex[i+1] not in ['-', '+']:
            s = ex[i] + s
            i -= 1
        b = num(s)
        if b == 0: b = 1
        ex = ex[:i+1] + ex[y+1:]

    c = num(ex)

    return (a, b, c)

def simplify(eq):
    [l, r] = eq.split('=')
    (al, bl, cl) = eval(l)
    (ar, br, cr) = eval(r)
    
    return (al - ar, bl - br, cl - cr)

def solve(eq1, eq2):
    (a1, b1, c1) = simplify(eq1)
    (a2, b2, c2) = simplify(eq2)

    print(a1, b1, c1)
    print(a2, b2, c2)

    y = (c2 * a1 - c1 * a2) / (b1 * a2 - a1 * b2)
    x = (- c1 - b1 * y) / a1

    return x, y

x, y = solve(eq1, eq2)
print('{:.3f}'.format(x))
print('{:.3f}'.format(y))
