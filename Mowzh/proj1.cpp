#include <iostream>
using namespace std;

inline void get(int* arr, bool* chk, int i) {
    if (chk[i]) return;
    chk[i] = true;

    cout << "? " << i << '\n';
    cout.flush();
    
    cin >> arr[i];
}

inline void submit(int i) {
    cout << "! " << i << '\n';
    cout.flush();
}

int solve(int* arr, bool* chk, int n, int l, int r);
int find(int* arr, bool* chk, int n, int l, int r);

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    bool *chk = new bool[n];

    for(int i = 0; i < n; i++) {
        chk[i] = false;
    }

    submit(find(arr, chk, n, 0, n-1));
}

int solve(int* arr, bool* chk, int n, int l, int r) {
    get(arr, chk, 0);
    get(arr, chk, 1);
    get(arr, chk, n-2);
    get(arr, chk, n-1);

    if (arr[0] >= arr[1] && arr[0] >= arr[n-1]) {
        return 0;
    }

    if (arr[n-1] >= arr[0] && arr[n-1] >= arr[n-2]) {
        return n-1;
    }

    return find(arr, chk, n, 0, n-1);
}

int find(int* arr, bool* chk, int n, int l, int r) {
    int m = l + (r - l) / 2;

    get(arr, chk, m-1);
    get(arr, chk, m);
    get(arr, chk, m+1);
    
    if ((m == 0 || arr[m-1] <= arr[m]) && (m == n - 1 || arr[m + 1] <= arr[m])) {
        return m;
    } else if (m > 0 && arr[m-1] > arr[m]) {
        return find(arr, chk, n, l, m-1);
    } else {
        return find(arr, chk, n, m+1, r);
    }
}