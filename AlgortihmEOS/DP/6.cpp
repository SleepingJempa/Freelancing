#include <iostream>
#include <vector>

const int LEFT = 0;
const int RIGHT = 1;

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<vector<int>> dp(n, vector<int>(2, 0));

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n < 2) {
        cout << 0 << endl;
        return 0;
    }

    int left_small = arr[0];
    for(int i = 1; i < n; i++) {
        dp[i][LEFT] = max(arr[i] - left_small, 0);
        if (arr[i] < left_small) left_small = arr[i];
    }

    int right_large = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        dp[i][RIGHT] = max(right_large - arr[i], 0);
        if (arr[i] > right_large) right_large = arr[i];
    }

    vector<vector<int>> partial(n, vector<int>(2));
    partial[1][LEFT] = dp[1][LEFT];
    partial[n-2][RIGHT] = dp[n-2][RIGHT];

    for(int i = 2; i < n; i++) {
        partial[i][LEFT] = max(partial[i-1][LEFT], dp[i][LEFT]);
    }

    for(int i = n-3; i >= 0; i--) {
        partial[i][RIGHT] = max(partial[i+1][RIGHT], dp[i][RIGHT]);
    }
    
    // int ans = partial[n-2][LEFT];
    int ans = max(partial[n-1][LEFT], partial[0][RIGHT]);

    for(int i = 1; i < n-1; i++) {
        ans = max(ans, partial[i][LEFT] + partial[i+1][RIGHT]);
        ans = max(ans, partial[i][LEFT]);
    }

    cout << ans;
}