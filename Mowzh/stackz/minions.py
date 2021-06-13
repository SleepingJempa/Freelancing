n = int(input())
a = [tuple(map(int, input().split())) for i in range(n)]

a.sort(key=lambda p: p[1])

last = 0
cnt = 0

for i in range(n):
    if a[i][0] > last:
        cnt += 1
        last = a[i][1]

print(cnt)