n = int(input())
a = list(map(int, input().split()))

def solve(arr: list, n: int):
    if n == 0: return 0

    last , ans = 0, 1

    for i in range(1, n):
        t = arr[i] - arr[i-1]
        s = 0
        if t > 0:
            s = 1
        if t < 0:
            s = -1
        
        if s != last and s != 0:
            last = s
            ans += 1
        
    return ans

print(solve(a, n))
