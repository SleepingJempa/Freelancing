list_input = list(map(int, input().split()))

MAP = []
n = 30

for i in range(n):
    MAP.append(list_input[i * n: (i+1) * n])
    # MAP.append(list(map(int, input().split())))

"""
[a, b, c, 0, 0, d, 1, 1, e]

[1][1] => [1][2]
[1][2] => [1][3]
[1][3] => [2][3]
[2][3] => [3][3]

visited = []

DFS(map, coord, target, moves) {
    if (node is visited) return;
    visited[node] = true;

    for(adj of node) {
        DFS(adj)
    }
}
"""


DIRS = [(0, 1), (1, 0), (-1, 0), (0, -1)]

visited = {}

def dfs(map: list, coord, target, moves: list) -> bool:
    i, j = coord
    a, b = target

    if map[i][j] == 0:
        return False

    if coord in visited:
        return
    visited[coord] = True

    if coord == target:
        moves.append((i, j))
        return True

    for d in DIRS:
        x, y = d
        x += i
        y += j

        if 0 <= x <= a and 0 <= y <= b:
            result = dfs(map, (x, y), target, moves)
            if result:
                moves.append((i, j))
                return True
    
    return False

moves = []
possible = dfs(MAP, (0, 0), (n-1, n-1), moves)

if possible:
    moves.reverse()

    for i in range(len(moves)-1):
        a, b = moves[i]
        c, d = moves[i+1]
        print('[{}][{}] ==> [{}][{}]'.format(a+1, b+1, c+1, d+1))
else:
    print('Impossible !')