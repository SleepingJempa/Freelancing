#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> Array;

int cnt(string s) {
    Array a(26);

    for(char &c : s) {
        a[c - 'a']++;
    }

    int r = 0;
    for(int x : a) {
        r += (x > 0);
    }

    return r;
}

int main() {
    int n;
    cin >> n;

    int best = 0;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int c = cnt(s);
        best = max(best, c);
    }

    cout << best << endl;
}