#include <iostream>

using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    if (b == "+") {
        if (a.length() < c.length()) swap(a, c);
        a[a.size() - c.length()] = '1';
        if (a.size() == c.size()) a[0] = '2';
    } else {
        a += c.substr(1);        
    }

    cout << a << endl;
}