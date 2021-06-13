arr = [1, 4, 3, 5, 2]

def kaf_gir_sort(a: list, n: int):
    if n == 1: return
    n -= 1

    def find_max(a: list, n: int):
        ind = 0
        mx = max(a[:n+1])
        while a[ind] != mx: ind += 1
        return ind
    
    def kaf_gir(a, k):
        a[:k+1] = reversed(a[:k+1])
    
    k = find_max(a, n)
    kaf_gir(a, k)
    kaf_gir(a, n)

    kaf_gir_sort(a, n)

kaf_gir_sort(arr, len(arr))

print(arr)        