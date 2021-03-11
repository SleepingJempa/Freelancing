#include <iostream>

using namespace std;

bool isDangerous(string s) {
    int r = 0;
    int y = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'R') r++;
        if (s[i] == 'Y') y++;
    }

    if (r >= 3) return true;
    if (r >= 2 && y >= 2) return true;
    if (r == s.length() || y == s.length()) return true;
    return false;
}

int main() {
    string s;
    cin >> s;
    if (isDangerous(s)) {
        cout << "nakhor lite";
    } else {
        cout << "rahat bash";
    }
}