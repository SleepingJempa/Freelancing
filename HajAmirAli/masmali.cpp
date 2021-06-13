#include <iostream>

using namespace std;

int getVal(string s) {
    int val = 0;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == 'I') val++; else val--;
        if (val < 0) return -1;
    }
    return val;
}

int solve(int n, string s, int val) {
    if (s.size() == 2 * n) {
        // cout << s << endl;
        return 1;
    }
    if (val == -1) val = getVal(s);
    if (val == -1) return -1;

    int open = val < 2 * n - s.size() ? solve(n, s + 'I', val+1) : 0;
    int close = val > 0 ? solve(n, s + 'O', val-1) : 0;

    return open + close;
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    cout << solve(n, s, -1) << endl;
}