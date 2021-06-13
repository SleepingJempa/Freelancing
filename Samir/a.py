n = int(input())


def check(n):
    m = n
    d = []
    l = 0

    while n > 0:
        d.append(n % 10)
        l += 1

        n //= 10

    s = 0
    for x in d:
        s += x ** l
    
    return s == m

print(check(n))