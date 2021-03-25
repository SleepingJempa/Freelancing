n, m = map(int, input().split())

def solve(h: tuple, n: int, m: int, d: dict):
    # dp check
    if h in d:
        return d[h]

    L = 0
    min_height = h[0]

    # Peyda kardane min_height va L
    for i in range(len(h)):
        if (h[i] < min_height):
            min_height = h[i]
            L = i
        
    # Noghte nahayee
    if min_height == n:
        return 0

    # Rah haye por kardan nmitune bishtr az n * m bashe
    # chon age hame ro 1*1 bzarim mishe in
    ans = n * m

    # copy mikonim baraye check kardane hameye halat ha
    dummy = list(h)

    # Gharar dadane tamame moraba hayee ke emkan darad
    for R in range(L, m):
        if dummy[R] == min_height:
            width = R - L + 1

            if min_height + width <= n:
                dummy[L:R+1] = [min_height + width] * width
                ans = min(ans, solve(tuple(dummy), n, m, d) + 1)
        else:
            break
    
    # dp assignment
    d[h] = ans

    return d[h]

d = {}
print(solve(tuple([0] * m), n, m, d))

for i in range(1, 100):
    for j in range(1, 100):
        d = {}
        if solve(tuple([0] * j), i, j, d) > max(n, m):
            print(i, j)