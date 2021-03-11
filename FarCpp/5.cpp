#include <iostream>

using namespace std;

int main() {
    int h = 24;
    int m = 60;
    int s = 60;

    int a, b, c;
    cin >> a >> b >> c;

    h += a;
    m += b;
    s += c;

    cin >> a >> b >> c;

    h -= a;
    m -= b;
    s -= c;

    h %= 24;
    m %= 60;
    s %= 60;

    cout << h << ":" << m << ":" << s << endl;
}