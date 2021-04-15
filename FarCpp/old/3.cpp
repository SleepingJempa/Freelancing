#include <iostream>

using namespace std;

int reverseOfInteger(int n) {
    int m = 0;
    while (n) {
        m += n % 10;
        m *= 10;
        n /= 10;
    }

    return m / 10;
}

int main() {
    int n;
    cin >> n;

    int a = 0, b = 0;
    int i = 0;
    while (n) {
        if (i % 2) {
            a += n % 10;
            a *= 10;
        } else {
            b += n % 10;
            b *= 10;
        }

        i++;
        n /= 10;
    }

    a /= 10;
    b /= 10;
    
    a = reverseOfInteger(a);
    b = reverseOfInteger(b);

    cout << a << " " << b << endl;
}