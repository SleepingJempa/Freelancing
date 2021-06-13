n, k = map(int, input().split())
a = list(map(int, input().split()))
mx = max(a)

def solve(arr, partial, k, left, right):
    # print(arr, left, right)
    if left == right:
        partial[left] = arr[left] if left == 0 else partial[left - 1] + arr[left]
        return int(arr[left] % k == 0) + int(partial[left] % k == 0)

    m = left + (right - left) // 2

    ans = solve(arr, partial, k, left, m) + solve(arr, partial, k, m+1, right)

    if (left == 0 and right == 3): print(partial)

    for l in range(left, m+1):
        for r in range(m+1, right+1):
            # print(l, r, int((partial[r] - partial[l]) % k == 0))
            ans += int((partial[r] - partial[l]) % k == 0)

    return ans

ans = 0
p = [0] * (n-1)

for i in range(n):
    if i+1 < n and a[i] == a[i+1]:
        continue
    if a[i] == mx:
        b = a[:i] + a[i+1:]
        ans = max(ans, solve(b, p, k, 0, n-2))

print(ans)





