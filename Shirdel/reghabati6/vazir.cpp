#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;

    int last_start = 0;
    int first_end = m;

    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        last_start = (last_start < x ? x : last_start);
        first_end = (first_end > y ? y : first_end);
    }


    ll X = last_start;
    ll Y = first_end;

    // cout << X << " " << Y << endl;

    ll A = (X - 1) * (m - X + 1);
    ll B = (Y - X + 1) * (2 * m - (X + Y) + 2) / 2;

    ll ans = A + B;
    cout << ans << endl;
}