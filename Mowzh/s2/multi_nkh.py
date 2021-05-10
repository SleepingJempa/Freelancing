"""

aabb
abab
abba

baab
baba
bbaa

f(n,m) = f(n-1, m) + f(n, m-1)

"""
MOD = 10**9 + 7
N = 1111

n, m = map(int, input().split())


dp = [[1 for j in range(2*N)] for i in range(2*N)]

for i in range(2, n+m+1):
    for j in range(1, i):
        dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD

print(dp[n+m][n])