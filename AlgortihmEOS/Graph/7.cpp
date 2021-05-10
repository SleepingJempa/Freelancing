#include <iostream>
#include <vector>

using namespace std;

const char EMPTY = '.';
const char WALL = '#';
const char HUMAN = 'H';
const char CORONA = 'C';

void solveCoronaMaze(vector<vector<char>>& grid);

bool putWalls(vector<vector<char>>& grid);
void dfs(vector<vector<char>>& grid, int i, int j);

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            grid[i][j] = s[j];
        }
    }

    solveCoronaMaze(grid);
}

void solveCoronaMaze(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    if (putWalls(grid)) {
        bool flag = true;
        dfs(grid, n-1, m-1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == HUMAN) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        cout << (flag ? "YES" : "NO") << endl;
    } else {
        cout << "NO" << endl;   
    }
}

bool putWalls(vector<vector<char>>& grid) {
    vector<vector<int>> dirs = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char &cur = grid[i][j];
            for(auto dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];

                if (x >= 0 && y >= 0 && x < n && y < m) {
                    char &adj = grid[x][y];
                    if (cur == CORONA && adj == EMPTY) adj = WALL;
                    if (cur == CORONA && adj == HUMAN) return false;
                }
            }
        }
    }
    return true;
}

void dfs(vector<vector<char>>& grid, int i, int j) {
    vector<vector<int>> dirs = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    int n = grid.size();
    int m = grid[0].size();
    
    char &cur = grid[i][j];

    if (cur == WALL) return;
    cur = WALL;

    for(auto dir : dirs) {
        int x = i + dir[0];
        int y = j + dir[1];

        if (x >= 0 && y >= 0 && x < n && y < m) {
            dfs(grid, x, y);
        }
    }
}