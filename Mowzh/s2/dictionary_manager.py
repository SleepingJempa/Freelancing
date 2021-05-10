e = lambda s: (s.split()[0], int(s.split()[1]))

inp = input().split()
n = int(inp[0])
w = inp[1]

l = [e(input()) for i in range(n)]

m = {}
dp = [-1] * len(w)

MOD = 10 ** 9 + 7

for (s, c) in l:
    t = w.find(s)
    if t != -1:
        # m[(t, t+len(s)-1)] = c
        m[s] = c

def solve(s, m, dp):
    n = len(s)

    if n == 1:
        if s in m: 
            return m[s]
        else:
            return 0

    ans = 0 if s not in m else m[s]

    for i in range(n-1):
        if s[:i+1] in m and s[i+1:] in m:
            if dp[i] == -1:
                dp[i] = solve(s[:i+1], m, dp)
            ans = (ans + dp[i] * m[s[i+1:]]) % MOD
    return ans

print(solve(w, m, dp) % MOD)
