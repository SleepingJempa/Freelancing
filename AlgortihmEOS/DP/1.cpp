#include <iostream>

using namespace std;

int main() {

    string s;
    cin >> s;

    int n = s.size();
    int dp[n][2];

    dp[0][0] = 0;
    // Agar s[0] == '0' bood pas dp[0][1] = 1 (true cast mishe be 1)
    dp[0][1] = (s[0] == '0');
    

    /**
     * Be soorate dynamic programming pish mirim ba int dp[n][2]
     * dp[i][0]: behtarin javab dar baaze 0 ta i age khode i ro hesab nakonim
     * dp[i][1]: behtarin javab dar baaze 0 ta i age khode i ro hesab bekonim
     */
    for(int i = 1; i < n; i++) {
        // Agar ozve feli ro hesab nakonim ingar dp[i-1] hastim va ozve i-1 om ro hesab kardim
        dp[i][0] = dp[i-1][1];
        
        /**
         * Hala mikhahim halati ke ozve i om ra bar midarim ra hesab konim
         * age s[i] == 1 bashe az meghdare adadie dp[i-1][1] yek vahed kam mishe
         */
        int v = dp[i-1][1] + (s[i] == '1' ? -1 : +1);

        /**
         * va age in meghdar manfi beshe behtare kolan bikhiale meghdar haye ghabl az i beshim
         * va az jelo edame bedim
         */
        dp[i][1] = (v < 0 ? 0 : v);
    }

    int ans = 0;
    // Javab bara javab ham bayad rooye noghte payan ye loop zad
    for(int i = 0; i < n; i++) {
        if (dp[i][1] > ans) ans = dp[i][1];
    }

    cout << ans << endl;
}