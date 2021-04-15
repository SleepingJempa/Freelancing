#include <iostream>

using namespace std;

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

    for(int i = 2; i < n; i++) {
        if (isPrime(i) && isPrime(n-i)) {
            cout << n-i << " " << i << endl;
            break;
        }
    }
}