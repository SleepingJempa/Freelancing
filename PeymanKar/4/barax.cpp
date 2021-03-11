#include <iostream>

using namespace std;

string rev(string s) {
    string result;
    for(int i = 0; i < s.length(); i++) {
        result = s[i] + result;
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    string t = rev(s);
    cout << t;
}