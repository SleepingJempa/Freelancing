#include <iostream>
using namespace std;

typedef long long ll;

const ll N = 3e5 + 1;
const ll M = 1e9 + 7;

ll bpow(ll a, ll b, ll m) {
    ll r = 1;
    
    while (b) {
        if (b % 2 == 1) r = (r * a) % m;
        a = (a * a) % m;
        b /= 2;
    }

    return r;
}

ll inv(ll a, ll m) {
    return bpow(a, m-2, m);
}

int main() {
    ll n;
    cin >> n;

    n--;
    ll c = 1;

    ll ans = 0;

    ll x, d;
    for(ll k = 0; k <= n; k++) {
        cin >> x;

        ll d = (c * x) % M;
        ans = (ans + ((n-k) % 2 == 1 ? -1 : +1) * d) % M;

        c = (c * (n-k) * inv(k+1, M) + M) % M;
    }

    cout << (ans + M) % M << endl;
}


/**
 * 
 * a1 a2 a3 a4 a5
 * 
 * a5-a4
 * a4-a3
 * a3-a2
 * a2-a1
 * 
 * a5-2a4+a3
 * a4-2a3+a2
 * a3-2a2+a1
 * 
 * a5-3a4+3a3-a2
 * a4-3a3+3a2-a1
 * 
 * a5-4a4+6a3-3a2
 * 
 */