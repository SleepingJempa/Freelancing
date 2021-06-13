n = int(input())
a = list(map(int, input().split()))
s = sum(a)

if s % 2 == 1:
    print('no')
else:
    for i in range(n):
        if a[i] > s // 2:
            print('no')
            exit()
    
    f = [[a[i], i] for i in range(n)]

    while True:
        f.sort(key=lambda p: p[0])
        if f[-1][0] == 0: break
        print(f[-1][1]+1, f[-2][1]+1)
        f[-2][0] -= 1
        f[-1][0] -= 1