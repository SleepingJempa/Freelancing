n = int(input())

if n % 2 == 1:
    print(-1)
    exit()

ans = [0]
val = [1] * n
vis = [False] * n
adj_list = [[] for i in range(n)]

def dfs(node, a):
    vis[node] = True

    for adj in adj_list[node]:
        if vis[adj]: continue

        dfs(adj, a)

        if val[adj] % 2 == 1:
            val[node] += val[adj]
        else:
            a[0] += 1
 
for i in range(n-1):
    x, y = map(int, input().split())
    adj_list[x-1].append(y-1)
    adj_list[y-1].append(x-1)


dfs(0, ans)

print(ans[0])
