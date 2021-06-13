t = int(input())

def solve(a, b, m, n, dp):
    """
        @param a: a[i] is memory size of the i-th hagh
        @param b: b[i] is const of that
        @param m: the total capacity of our bag
        @param n: the number of items left
    """
    if sum(a) < m: return -1
    
    x = [-1 for _ in range(b.count(1))]
    y = [-1 for _ in range(b.count(2))]
    x_i, y_i = 0, 0

    for i in range(n):
        if b[i] == 1:
            x[x_i] = a[i]
            x_i += 1
        else:
            y[y_i] = a[i]
            y_i += 1
    
    x.sort()
    y.sort()
    # print(x, y)
    # print(x[:x_i])
    # print(y[:y_i])
    
    i = 0
    ans = -1
    odd = -1
    while m > 0:
        if i > 0: dp[i] += dp[i-1]
        # print(x_i, y_i)
        # print(dp)

        if x_i >= 1 and m - x[x_i - 1] <= 0:
            # print('select the last from x')
            dp[i] += 1
            m -= x[x_i - 1]
            x_i -= 1
            break
        elif x_i == 1:
            # print('extract the last element of x')
            odd = x[x_i - 1]
            x_i = 0
            continue
        elif x_i >= 1 and y_i >= 1 and m - x[x_i - 1] - y[y_i - 1] <= 0:
            # print('selecting in trio case')
            dp[i] += 3
            m -= x[x_i - 1] + y[y_i - 1]
            break
        elif x_i >= 2 and y_i >= 1 and x[x_i - 1] + x[x_i - 2] > y[y_i - 1]:
            # print('if picking two haghs from x is better than one from y')
            dp[i] += 2
            m -= x[x_i - 1] + x[x_i - 2]
            x_i -= 2
        elif y_i >= 1:
            # print('o.w. selecting from y')
            dp[i] += 2
            m -= y[y_i - 1]
            y_i -= 1
            # print(m)
        
        if m > 0 and m - odd <= 0:
            dp[i] += 1
            break
        if m <= 0:
            break
        i += 1
    
    return dp[i]

    

def test_case():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    dp = [0 for _ in range(n)]

    print(solve(a, b, m, n, dp))

for i in range(t):
    test_case()