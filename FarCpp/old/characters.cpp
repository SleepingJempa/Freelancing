#include <iostream>

using namespace std;

void twoM(int m, int n);
int CheckNum(int n, int m);
int numberOfDivisors(int n);

int main() {
    int n, m;
    cin >> n >> m;

    char ch;
    cin >> ch;

    switch(ch) {
        case 'C':
            twoM(m, n);
            break;
        case 'D':
            cout << CheckNum(n, m) << endl;
            break;
        default:
            cout << "Wrong Char" << endl;
    }
}

void twoM(int m, int n) {
    int p = n % 10;
    while (n > 1) {
        n /= 10;
        int q = n % 10;
        if (p == q) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

int CheckNum(int n, int m) {
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (numberOfDivisors(x) >= m) {
            cout << x << endl;
            cnt++;
        }
    }

    return cnt;
}

int numberOfDivisors(int n) {
    int cnt = 1;

    int i = 2;
    while (n > 1) {
        int t = 0;
        while (n % i == 0) {
            t++;
            n /= i;
        }
        cnt *= t+1;
        i++;
    }

    return cnt;
}