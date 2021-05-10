for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    s = 0
    b = 0

    for i in range(n):
        s += a[i]
        if s < 0:
            s = 0
        elif s > b:
            b = s
    
    if b == 0:
        print(max(a), end=' ')
    else:
        print(b, end=' ')
    
    a.sort()

    i = 0
    while i < n:
        if a[i] > 0:
            break
        i += 1
    
    if i == n:
        print(max(a))
    else:
        print(sum(a[i:]))

