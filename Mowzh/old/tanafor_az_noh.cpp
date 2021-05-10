#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1000000000 + 7;

ll mod_pow(ll a, ll d) {
    ll r = 1;
    while(d > 0) {
        // cout << d << endl;
        if (d % 2 == 1) {
            r = (r * a) % MOD;
        }
        a = (a * a) % MOD;
        d /= 2;
    }
    return r;
}

int main () {
    ll d;
    cin >> d;
    ll ans = (8 * mod_pow(9, d-1)) % MOD;
    cout << ans;
}