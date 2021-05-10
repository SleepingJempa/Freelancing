#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int N = 32;
int num[N][N];
int dp[N];

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int m = s.size();


    vector<vector<int>> starts(m);

    string t;
    int k;
    for(int i = 0; i < n; i++) {
        cin >> t;
        cin >> k;
        int p = s.find(t);

        if (p == -1) continue;

        num[p][p + t.length()] = k;
        starts[p + t.length()].push_back(p);
    }

    for(int i = 1; i < m; i++) {
        for(int j = 0; j < i; j++) {

        }
    }

    
}