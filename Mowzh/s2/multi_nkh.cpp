#include <iostream>

using namespace std;

const int K = 2001;
const int N = K * (K + 1) / 2;
const int M = 1e9 + 7;
int dp[N];

int index(int n, int k) {
    return n * (n+1) / 2 + k;
}

int get(int n, int k) {
    return dp[index(n, k)];
}

void set(int n, int k, int value) {
    dp[index(n, k)] = value % M;
}

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < K; i++) {
        set(i, 0, 1);
        set(i, i, 1);
    }

    for(int i = 2; i < K; i++) {
        for(int j = 1; j < i; j++) {
            set(i, j, get(i-1, j-1) + get(i-1, j));
        }
    }

    cout << get(n+k, k) << endl;
}