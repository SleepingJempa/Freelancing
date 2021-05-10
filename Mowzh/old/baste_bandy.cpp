#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main () {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[n-i-1];


    int sack = 0;
    int i;
    for(i = 0; i < n; i++) {
        if (a[i] > k) break;

        if (sack + a[i] > k) {
            m--;
            sack = a[i];
            if (m == 0) break;
        } else {
            sack += a[i];
        }
    }

    cout << i;
}