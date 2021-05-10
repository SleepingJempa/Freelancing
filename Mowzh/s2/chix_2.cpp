#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits>
#include <cstddef>

using namespace std;

const int N = 21;
double dp[(1 << N)];
bool check[(1 << N)];

int n;
double X, Y;
double x[N], y[N];

int select(int mask, int i, int j) {
    return mask | (1 << i) | (1 << j);
}

bool valid(int mask, int i, int j) {
    return ((mask & (1 << i)) == 0) && ((mask & (1 << j)) == 0);
}

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(
        (x2-x1) * (x2-x1)
        +
        (y2-y1) * (y2-y1)
    );
}

double cost(int i, int j) {
    return (
        dist(x[i], y[i], x[j], y[j])
        +
        dist(x[i], y[i], X, Y)
        +
        dist(X, Y, x[j], y[j])
    );
}

bool full(int mask) {
    return mask == ((1 << n) - 1);
}

void solve(int mask) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {

            if (valid(mask, i, j)) {
                int target = select(mask, i, j);
                int value = dp[mask] + cost(i, j);
                
                if (value < dp[target] || !check[target]) {
                    dp[target] = dp[mask] + cost(i, j);
                    check[target] = true;
                }

                if (full(target)) {
                    dp[target] -= max(
                        dist(x[i], y[i], X, Y)
                        ,
                        dist(x[j], y[j], X, Y)
                    );
                } else {
                    solve(target);
                }
            }
        }
    }
}

int main() {
    cin >> X >> Y;
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    if (n % 2 == 1) {
        x[n] = X;
        y[n] = Y;
        n++;
    }

    solve(0);

    double ans = dp[(1 << n) - 1];

    printf("%.6f", ans);
}