#include <iostream>

using namespace std;

bool starts_with(string s, char c) {
    return s[0] == c;
}

bool size_equal(string s, int n) {
    return s.size() == n;
}

int main() {
    string phone;
    cin >> phone;

    try {
        if (starts_with(s, '0') && size_equal(s, 11)) {
            cout << "It's ok" << endl;
        } else {
            throw "Invalid phone number";
        }
    } catch (const char* err) {
        cout << err << endl;
    }
}