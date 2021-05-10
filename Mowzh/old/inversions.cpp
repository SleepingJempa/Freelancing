#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll inversions(vector<ll> &a, vector<ll> &t, ll left, ll right);
ll merge(vector<ll> &a, vector<ll> &t, ll left, ll right);


int main() {
    ll n;
    cin >> n;

    vector<ll> a(n), t(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    cout << inversions(a, t, 0, n-1);
}

ll inversions(vector<ll> &a, vector<ll> &t, ll left, ll right) {
    if (left == right) return 0;

    ll mid = (left + right) / 2;
    ll ans = inversions(a, t, left, mid) + inversions(a, t, mid+1, right);

    ans += merge(a, t, left, right);

    return ans;
}

ll merge(vector<ll> &a, vector<ll> &t, ll left, ll right) {
    ll i = left;
    ll mid = (left + right) / 2;
    ll j = mid + 1;
    ll k = left;
    ll ans = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            t[k++] = a[i++];
        } else {
            t[k++] = a[j++];
            ans += mid - i + 1;
        }
    }

    while(i <= mid) {
        t[k++] = a[i++];
    }

    while(j <= right) {
        t[k++] = a[j++];
    }

    for(ll l = left; l <= right; l++) {
        a[l] = t[l];
    }

    return ans;
}

// n = ll(input())
// arr = [ll(input()) for i in range(n)]
// dummy = arr.copy()
// prll(inversions(arr, dummy, 0, n-1))
