#include <iostream>

using namespace std;

int main() {
    int a, b;
    char c;

    cin >> a >> b;
    cin >> c;

    if (c == 'A') {
        int sum = 0;
        for(int i = 0; i < b; i++) {
            sum += a;
        }
        cout << sum << endl;
    }

    else if (c == 'B') {
        if (a < b) {
            int tmp = b;
            b = a;
            a = tmp;
        }
        int prod = 1;
        for(int i = 0; i < b; i++) {
            prod *= a;
        }
        cout << prod << endl;
    }

    else {
        cout << "Invalid Character" << endl;
    }
}