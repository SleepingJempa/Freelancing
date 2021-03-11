#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = n + 1; i < m; i++) {
        if (i % 2 == 0) cout << i << endl;
    }
}