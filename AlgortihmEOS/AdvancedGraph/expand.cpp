#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

const int N = 1111;

int n, m, k;
tuple<int, int, int> edges[N];

// DSU
int parent[N];
int sz[N];

int find(int v) {
    return (v == parent[v] ? v : parent[v] = find(parent[v]));
}

void merge(int v, int u) {
    int pv = find(v);
    int pu = find(u);

    if (pv != pu) {
        if (sz[pv] < sz[pu]) {
            swap(pv, pu);
        }

        parent[pu] = pv;
        sz[pv] += sz[pu];
    }
}

int main() {
    int ans = 0;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    int f, t, w;
    for(int i = 0; i < m; i++) {
        cin >> f >> t >> w;
        f--; t--;
        edges[i] = make_tuple(w, f, t);
    }

    sort(edges, edges+m);

    // for(int i = 0; i < m; i++) {
    //     w = get<0>(edges[i]);
    //     f = get<1>(edges[i]);
    //     t = get<2>(edges[i]);

    //     cout << w << " " << f << " " << t << endl;
    // }

    for(int i = 0; i < k; i++) {
        cin >> f >> t;
        f--; t--;
        merge(f, t);
    }

    int i = 0;
    while(sz[find(0)] < n && i < m) {
        auto e = edges[i++];
        w = get<0>(e);
        f = get<1>(e);
        t = get<2>(e);

        if (find(f) != find(t)) {
            ans += w;
            merge(f, t);
        }
    }

    if (sz[find(0)] == n) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}