#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll solve(ll n, vector<ll> &dp);

int main() {
    int n;
    cin >> n;

    vector<ll> dp(n+1, -1);

    cout << solve(n, dp);
}

ll solve(ll n, vector<ll> &dp) {
    if (n < 2) return 1LL;

    if (dp[n] == -1) {
        // Esteghrayee fekr mikonim

        // Ozve jadid ya ba yeki az (n-1) nafare dg doost mishe => (n-1) * f(n-2)
        // ya tanha mimoone => f(n)
        dp[n] = (n-1) * solve(n-2, dp) + solve(n-1, dp);
    }

    return dp[n];
}