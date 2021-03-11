def is_prime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

n = int(input())
m = int(input())

for i in range(n+1, m):
    if is_prime(i):
        print(i, end = ' ')