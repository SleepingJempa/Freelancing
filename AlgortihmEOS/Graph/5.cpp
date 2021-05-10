#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
vector<int> val;
vector<bool> vis;
vector<vector<int>> adj_list;

void dfs(int node);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }

    val.resize(n, 1);
    vis.resize(n, false);
    adj_list.resize(n, vector<int>());

    int x, y;
    for(int i = 1; i < n; i++) {
        cin >> x >> y;
        x--; y--;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    dfs(0);

    cout << ans;
}

void dfs(int node) {
    vis[node] = true;

    for(int adj : adj_list[node]) {
        if (vis[adj]) continue;

        dfs(adj);

        int value = val[adj];

        if (value & 1) {
            val[node] += value;
        } else {
            ans++;
        }
    }
}