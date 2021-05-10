#include <iostream>
#include <vector>

using namespace std;

int solve(string s, string t, int i, int j, vector<vector<int>> &dp);

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    cout << solve(s, t, n, m, dp);
}

int solve(string s, string t, int i, int j, vector<vector<int>> &dp) {
    if (i == 0 || j == 0) return i + j;

    if (dp[i][j] != -1) return dp[i][j];

    // Akharin harf yeksan
    if (s[i-1] == t[j-1]) {
        return solve(s, t, i-1, j-1, dp);
    }

    // Akharin harf tafavot dare
    int remove = solve(s, t, i-1, j, dp) + 1;
    int insert = solve(s, t, i, j-1, dp) + 1;
    int replace = solve(s, t, i-1, j-1, dp) + 2;

    dp[i][j] = min( min(remove, insert), replace);

    return dp[i][j];
}