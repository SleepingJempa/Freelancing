n, s, a, b = map(int, input().split(', '))

# print(n, s, a, b)

chk = [False] * n

def dfs(n, s, a, b, chk):
    if s >= n or s < 0 or chk[s]: return 0

    chk[s] = True

    return (
        1
        + dfs(n, s-a, a, b, chk)
        + dfs(n, s-b, a, b, chk)
        + dfs(n, s+a, a, b, chk)
        + dfs(n, s+b, a, b, chk)
    )

print(dfs(n, s-1, a, b, chk))

for i in range(n):
    if chk[i]: print(i+1, end=' ')

print()