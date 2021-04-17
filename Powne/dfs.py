n = 30
MAP = [list(map(int, input().split())) for _ in range(n)]
DIRS = [(0, 1), (0, -1), (1, 0), (-1, 0)]

visited = {}

def dfs(map, coord, target, moves: list):
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
        print('[{}][{}] ==> [{}][{}]'.format(a, b, c, d))
else:
    print('Impossible !')