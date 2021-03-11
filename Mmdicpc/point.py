n = int(input())

p = [ list(map(float, input().split())) for i in range(n) ]

print(p)

def checkA(x, y):
    _y = x - x // 1
    return abs(_y - y) <= 0.2

def checkB(x, y):
    _y = x**2 + x
    return abs(_y - y) <= 0.2

def checkC(x, y):
    _y = abs(-x**3 + 1) + x**3
    return abs(_y - y) <= 0.2

flag = False

for i in range(n):
    x, y = p[i][0], p[i][1]
    if checkA(x, y) and i == n-1:
        print(1)
        exit()
    if not checkB(x, y):
        break

for i in range(n):
    x, y = p[i][0], p[i][1]
    if checkB(x, y) and i == n-1:
        print(2)
        exit()
    if not checkB(x, y):
        break

for i in range(n):
    x, y = p[i][0], p[i][1]
    if checkC(x, y) and i == n-1:
        print(3)
        exit()
    if not checkB(x, y):
        break

print('No ones')