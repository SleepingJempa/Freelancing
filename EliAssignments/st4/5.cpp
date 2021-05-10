#include <iostream>

using namespace std;

float mean(int *arr, int n) {
    float result = 0;
    for(int i = 0; i < n; i++) {
        result += arr[i];
    }
    return result / n;
}

void run() {
    int n;
    cin >> n;

    int *a = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int avg = mean(a, n);

    for(int i = 0; i < n; i++) {
        if (a[i] > avg) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    run();
}