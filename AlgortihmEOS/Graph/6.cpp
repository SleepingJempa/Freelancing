#include <iostream>
#include <vector>

using namespace std;

const int N = 50;
int a[N*N];
bool chk[N][N];
int clr[N][N];
string s[N];

int n, m;
int color;

vector<vector<int>> dirs = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

bool is_in(vector<int> &v, int n) {
    for(int t : v) if (t == n) return true;
    return false;
}

int expand(int i, int j) {
    vector<int> colors;
    for (auto dir : dirs) {
        int x = i + dir[0];
        int y = j + dir[1];
        if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.') {
            if (!is_in(colors, clr[x][y])) colors.push_back(clr[x][y]);
        }
    }

    int ans = 1;
    for(int c : colors) {
        ans += a[c];
    }
    return ans % 10;
}

int dfs(int i, int j, int color) {
    if (chk[i][j]) {
        return 0;
    }

    chk[i][j] = true;
    clr[i][j] = color;

    char c = s[i][j];

    int cnt = 1;

    for (auto dir : dirs) {
        int x = i + dir[0];
        int y = j + dir[1];
        if (x >= 0 && x < n && y >= 0 && y < m && chk[x][y] == false && s[x][y] == '.') {
            cnt += dfs(x, y, color);
        }
    }

    return cnt;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> s[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (chk[i][j] == false && s[i][j] == '.') {
                a[color] = dfs(i, j, color);
                color++;
            }
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << clr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (s[i][j] == '*') {
                cout << expand(i, j);
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }

    // cout << color << endl;
    // for(int i = 0; i < color; i++) cout << a[i] << " ";
}