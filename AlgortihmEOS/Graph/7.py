n, m = map(int, input().split())
grid = [list(input()) for _ in range(n)]

EMPTY = '.'
WALL = '#'
HUMAN = 'H'
CORONA = 'C'

# Utility function to validate the cell
def is_valid(i, j):
    return 0 <= i < n and 0 <= j < m

# Utility function to get adjacent cells
def get_adj(i, j):
    adj = []
    
    dirs = [
        (0, 1),
        (0, -1),
        (1, 0),
        (-1, 0)
    ]

    for x, y in dirs:
        if is_valid(i+x, j+y):
            adj.append((i+x, j+y))

    return adj

def put_walls(grid):
    for i in range(n):
        for j in range(m):
            if grid[i][j] == CORONA:
                for x, y in get_adj(i, j):
                    if grid[x][y] == HUMAN:
                        return False
                    elif grid[x][y] == EMPTY:
                        grid[x][y] = WALL
    return True

def dfs(grid, i, j):
    if grid[i][j] == WALL: return
    grid[i][j] = WALL

    for x, y in get_adj(i, j):
        dfs(grid, x, y)

def solve_corona_maze(grid):
    if not put_walls(grid):
        print('NO')
    else:
        flag = True
        dfs(grid, n-1, m-1)

        for i in range(n):
            for j in range(m):
                if grid[i][j] == HUMAN:
                    flag = False
                    break
            if not flag:
                break

        print('YES' if flag else 'NO')
            


solve_corona_maze(grid)

