def gcd(a, b):
    while b:
        a, b = b, a % b
    
    return a


ans = -1
for i in range(int(input())):
    if i == 0:
        ans = int(input())
    else:
        n = int(input())
        ans = gcd(ans, n)

print(ans)