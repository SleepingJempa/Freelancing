#include <iostream>
#include <string>

using namespace std;

const int N = 1e7 + 10;
bool chk[N+100];

int dfs(int n, int s, int a, int b) {
    if (s >= n || s < 0 || chk[s]) return 0;
    chk[s] = true;

    return 1 + dfs(n, s-a, a, b) + dfs(n, s-b, a, b) + dfs(n, s+a, a, b) + dfs(n, s+b, a, b);
}

int main() {
    string str_n, str_s, str_a, str_b;
    cin >> str_n >> str_s >> str_a >> str_b;
    
    str_n.pop_back();
    str_s.pop_back();
    str_a.pop_back();

    int n = stoi(str_n);
    int s = stoi(str_s);
    int a = stoi(str_a);
    int b = stoi(str_b);

    cout << dfs(n, s-1, a, b) << endl;
    
    for(int i = 0; i < n; i++) {
        if (chk[i]) cout << i+1 << " ";
    }

    cout << endl;
}