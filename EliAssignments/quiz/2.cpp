#include <iostream>

using namespace std;

void read_string() {
    string s;
    cin >> s;

    // array hayee ke tedad char haro negah midaran
    // [0:25] for abc...z
    // [26:51] for ABC...Z
    int *cnt = new int[26 * 2];
    fill(cnt, cnt + 52, 0);

    for(int i = 0; i < s.length(); i++) {
        int j = -1;
        // cheking
        if (s[i] >= 'a' && s[i] <= 'z') j = s[i] - 'a';
        if (s[i] >= 'A' && s[i] <= 'Z') j = s[i] - 'a' + 26;
        if (j != -1) cnt[j]++;
    }


    // printing the result
    for(int i = 0; i < 26; i++) {
        cout << (char)('a' + i) << ": " << cnt[i] << endl;
    }

    for(int i = 0; i < 26; i++) {
        cout << (char)('A' + i) << ": " << cnt[i + 26] << endl;
    }
}

int main() {
    read_string();
}