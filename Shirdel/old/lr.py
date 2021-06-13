M = 10**9 + 7

def bpow(a, b, m):
    r = 1

    while b > 0:
        if b & 1:
            r = (r * a) % m
        a = (a * a) % m
        b >>= 1
    
    return r

def inv(a, m):
    return bpow(a, m-2, m)

n = int(input())
a = list(map(int, input().split()))

c = 1
ans = 0

for k in range(n):
    x = a[n-k-1]
    d = (c * x) % M

    if k % 2 == 1:
        d *= -1

    ans = (ans + d + M) % M

    c = (c * (n-k-1) * inv(k+1, M) + M) % M

print((ans + M) % M)