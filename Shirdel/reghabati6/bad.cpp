#include <iostream>

using namespace std;

int main() {
    int p, d;
    cin >> p >> d;

    for(int i = 1; i <= p; i++) {
        int c = d * i;
        if (c % p <= p/2) {
            cout << c << endl;
            break;
        }
    }
}