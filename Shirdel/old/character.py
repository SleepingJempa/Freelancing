def solve(n):
    r = 0
    while n > 2:
        r += n // 2
        n = (n + 1) // 2
    return r + 1

solve(int(input()))