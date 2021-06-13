#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n < 2 * k) {
        cout << "Impossible" << endl;
    } else {
        int i = n / 2;
        int j = 0;

        for (int k = 0; k < n; k++) {
            cout << (k % 2 == 0 ? ++i : ++j) << " ";

        }
    }
}