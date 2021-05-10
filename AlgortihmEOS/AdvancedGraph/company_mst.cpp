#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define range(i, n) for(int i=0; i<n; i++)

typedef vector<int> Array;
typedef vector<bool> Barry;
typedef vector<float> Farry;
typedef vector<double> Darry;
typedef vector<Array> Matrix;
typedef long long ll;

int mpst(Matrix mat);
int find_min(Array arr, Barry flags);
double distance(int x1, int y1, int x2, int y2);

int main() {
    int n;
    cin >> n;

    Matrix mat(n, Array(n));

    Array x(n);
    Array y(n);

    range(i, n) cin >> x[i] >> y[i];

    range(i, n) {
        range(j, n) {
            mat[i][j] = distance(x[i], y[i], x[j], y[j]);
            // cout << mat[i][j] << " ";
        }
        // cout << endl;
    }

    cout << mpst(mat) << endl;
}

int mpst(Matrix mat) {
    int n = mat.size();

    Array p(n);
    Array k(n);
    Barry f(n);

    fill(k.begin(), k.end(), INT32_MAX);
    fill(f.begin(), f.end(), false);

    k[0] = 0;
    p[0] = -1;

    range(i, n-1) {
        int u = find_min(k, f);
        f[u] = true;

        range(v, n) {
            if (mat[u][v] &&
                f[v] == false &&
                mat[u][v] < k[v]) {
                p[v] = u;
                k[v] = mat[u][v];
            }
        }
    }

    ll result = 0;
    range(i, n-1) {
        // cout << p[i+1] << " " << i+1 << endl;
        result += mat[i+1][ p[i+1] ];
    }

    return result;
}

int find_min(Array arr, Barry flags) {
    int index = 0;
    int minimum = INT32_MAX;

    range(i, arr.size()) {
        if (flags[i] == false && arr[i] < minimum) {
            minimum = arr[i];
            index = i;
        }
    }

    return index;
}

double distance(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}