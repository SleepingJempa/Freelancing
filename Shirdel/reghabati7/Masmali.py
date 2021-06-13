n = int(input())
s = input()

v = s.count('I') - s.count('O')

def bt(s, n, v):
    if len(s) == 2 * n: return 1

    if v < 0: return -1

    o = bt(s + 'I', n, v + 1) if v < 2 * n - len(s) else 0
    c = bt(s + 'O', n, v - 1) if v > 0 else 0

    return o + c

print(bt(s, n, v))