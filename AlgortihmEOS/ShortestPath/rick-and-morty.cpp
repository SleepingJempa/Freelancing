#include <iostream>
#include <set>
#include <vector>

using namespace std;


const int N(1 << 17), MXN(N * 3);
int n, q, s;

vector<pair<int, int> > e[MXN];


void connect(int x, int y, int w) {
	e[x].emplace_back(y, w);
}

void connect_range(int t, int x, int l, int r, int w) {
	auto f = [&](int i) {
		int y = (i + (t - 1) * N) % (t * N);
		if (t == 2) connect(x, y, w);
		if (t == 3) connect(y, x, w);
	};

	for (l += N - 1, r += N + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
		if (~l & 1) f(l ^ 1);
		if (r & 1) f(r ^ 1);
	}
}

int main() {
	cin >> n >> q >> s;
	for (int i = 2; i < N * 2; ++i) {
		connect(N * 1 + i / 2, (N * 1 + i) % (2 * N), 0);
		connect((N * 2 + i) % (3 * N), N * 2 + i / 2, 0);
	}

	while(q--) {
		int t, v, x, y, w;
		cin >> t;
		if(t == 1) {
			cin >> v >> x >> w;
			connect(v, x, w);
		} else {
			cin >> v >> x >> y >> w;
			connect_range(t, v, x, y, w);
		}
	}

	vector<unsigned long long> dis(N * 3, -1);
	set<pair<unsigned long long, int> > Q = {{dis[s] = 0, s}};

	while(!Q.empty()) {
		int u = Q.begin()->second;
		Q.erase(Q.begin());
		for(auto p : e[u]) {
			int v = p.first, w = p.second;
			if (dis[v] > dis[u] + w)
				Q.erase({dis[v], v}), Q.insert({dis[v] = dis[u] + w, v});
		}
	}
    
	for(int i = 1; i <= n; ++i) cout << (long long)dis[i] << " ";
	return 0;
}