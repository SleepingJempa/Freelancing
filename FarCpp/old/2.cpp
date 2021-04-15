#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int m;
    cin >> m;

    int a = 0;
    int b = 0;

    for(int i = 0; i < m; i++) {
        int n;
        cin >> n;

        int A[n];
        int B[n];

        for(int i = 0; i < n; i++)
            cin >> A[i];

        for(int i = 0; i < n; i++)
            cin >> B[i];

        for(int i = 0; i < n; i++) {
            int x = A[i];
            int y = B[i];

            if (x + y == 3) {
                (x == 1 ? a : b) += 6;
            }

            else if (abs(x-y)) {
                (x < y ? a : b) += x + y;
            }

            else if (abs(x-y) > 1) {
                (x > y ? a : b) += (x > y ? x : y);
            }
        }
    }

    cout << "A's Score is " << a << endl;
    cout << "B's Score is " << b << endl;
}