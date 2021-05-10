n = int(input())
a = list(map(int, input().split()))

b = list(map(lambda e: (e[1] / (e[0]+1), e[1], e[0] + 1), enumerate(a)))
b.sort(reverse=True)

i = 0
c = 0
p = 0

while i < n:
    while c + b[i][2] <= n:
        # print(b[i])
        c += b[i][2]
        p += b[i][1]
    i += 1

print(p)