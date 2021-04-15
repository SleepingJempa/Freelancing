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

bool isPrime(int n) {
    if (n == 2) return true;
    for(int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {
        if (isPrime(i) && i == reverseOfInteger(i)) {
            cout << i << endl;
        }
    }
}