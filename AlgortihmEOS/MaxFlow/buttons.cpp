#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
 
const long long MAXN=1210;
vector<long long> e[MAXN];
long long d;
long long m;
int chk[MAXN];
long long p[MAXN];
long long q[MAXN];
long long mrk[MAXN];
char s[MAXN];

long long bitsEqualToOne(long long x) {
    long long r = 0;
    while (x) {
        if (x & 1) r++;
        x >>= 1;
    }
    return r;
}

long long dfs(long long u) {
	for (auto v : e[u]) if (!chk[v]) {
		chk[v]=1;
		if (p[v]==-1||dfs(p[v])) { p[v]=u; return 1;}
	}
	return 0;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

	cin >> d >> m;
	for(long long i = 0; i < m; i++) {
		cin >> s;
		long long id = 0;
		for(long long j = 0; j < d; j++) 
            if (s[j]=='1')
                id+=(1<<j);
		q[i]=id;
	}
    
	for(long long i = 0; i < m; i++) {
        for(long long j = 0; j < m; j++) {
            if (j != i && (q[j]&q[i])==q[i]) {
                e[i].push_back(j);
            }
        }
    }
	memset(p,-1,sizeof(p));
	for(long long i = d; i >= 0; i--) {
        for(long long j = 0; j < m; j++) {
            if (bitsEqualToOne(q[j])==i)  {
		        memset(chk,0,sizeof(chk));
                dfs(j);
            }
        }
    }


	string ans;
	bool flag_s=1;
	
	for(long long i = d; i >= 0; i--) {
        for(long long j = 0; j < m; j++) {
            if (bitsEqualToOne(q[j])==i&&!mrk[j])  {
                vector<long long> chm;
                long long u=j;
                while (u!=-1) {
                    chm.push_back(q[u]);
                    mrk[u] = 1;
                    u = p[u];
                }
                chm.push_back(0);
                reverse(chm.begin(), chm.end());
                if (!flag_s) ans.push_back('R');
                flag_s=0;
                for(long long i = 0; i < chm.size() - 1; i++) {
                    long long u=chm[i+1]^chm[i];
                    for(long long j = 0; j < d; j++) if (u & (1<<j)) ans.push_back('0'+j);
                }
            }
        }
	}
	cout << ans.size() << endl;
	for (char x : ans) cout << x << " ";
    cout << endl;
}