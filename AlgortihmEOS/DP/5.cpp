#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int> &v, vector<vector<int>> &dp);

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    
    /**
     * dp[i][0]: tedade zir donbale hayee ke be arr[i] khat mishan va ozve koochikan
     * dp[i][0]: tedade zir donbale hayee ke be arr[i] khat mishan va ozve bozorgan 
     */
    vector<vector<int>> dp(n, vector<int>(2, 1));
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    solve(arr, dp);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        // cout << dp[i][0] << " " << dp[i][1] << " ";
        int cur = max(dp[i][0], dp[i][1]);
        ans = max(ans, cur);
    }

    cout << ans;
}

void solve(vector<int> &v, vector<vector<int>> &dp) {
    int n = v.size();

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(v[i] > v[j]) {
                dp[j][0] = max(dp[j][0], dp[i][1] + 1);
            }
        
            if (v[i] < v[j]) {
                dp[j][1] = max(dp[j][1], dp[i][0] + 1);
            }
        }
    }

    // for(int i = 1; i < n; i++) {
    //     for(int j = 0; j < i; j++) {
    //         /**
    //          * Age v[j] az v[i] bozorg tar boode pas az ghablie khodesham bayad bozorg tar bashe
    //          * pas tedade dp[j][1] moheme baramoon
    //          */
    //         if(v[j] > v[i]) {
    //             dp[i][0] = max(dp[i][0], 1 + dp[j][1]);
    //         }

    //         /**
    //          * Age v[j] az v[i] koochik tar boode pas az ghablie khodesham bayad koochik tar bashe
    //          * pas tedade dp[j][0] moheme baramoon
    //          */
    //         if(v[j] < v[i]) {
    //             dp[i][1] = max(dp[i][1], 1 + dp[j][0]);
    //         }
    //     }
    // }
}