#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<int> ans(n, INT32_MAX);
    ans[0] = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n-1; i++) {
        for(int d = i+1; d <= min(i+k, n-1); d++) {
            ans[d] = min(ans[d], ans[i] + abs(arr[i] - arr[d]));
        }
    }

    cout << ans[n-1] << endl;
}