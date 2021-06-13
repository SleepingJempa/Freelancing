def partition(arr, l, r, p):
    i, j, = l, l
    while j < r:
        if arr[j] <= arr[p]:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
        j += 1
    arr[i], arr[r] = arr[r], arr[i]
    return i

def select(arr, l, r, k):
    if l == r:
        return arr[l]
    
    p = partition(arr, l, r, r)

    if k == p:
        return arr[k]
    elif k < p:
        return select(arr, l, p-1, k)
    else:
        return select(arr, p+1, r, k-p)

n, k = map(int, input().split())
a = list(map(int, input().split()))

print(select(a, 0, n-1, k-1))
print(*a)