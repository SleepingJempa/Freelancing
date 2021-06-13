n = int(input())
m = int(input())
x = int(input())
y = int(input())

p = min(n, m)
q = max(x, y)

s = (p + q - 1) // q

print(s)