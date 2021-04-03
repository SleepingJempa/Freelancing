#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(2 * n);
    int index = 0;

    long long ans = 0;

    for(int i = 0; i < n; i++) {
        long long a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;

        if (a1 + b1 >= a2 + b2) {
            a[index++] = a1 + b1;
            a[index++] = a2 + b2;
            ans += a1 + a2;
        } else if (a1 > b2) {
            ans += a1 - b2;
        } else if (b1 > a2) {
            ans += a2 - b1;
        }
    }

    sort(a.begin(), a.begin()+index);

    for(int i = 0; i < index; i += 2) {
        ans -= a[i];
    }

    cout << ans;
}