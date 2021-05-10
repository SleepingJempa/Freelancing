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

int main() {
    int n;
    cin >> n;

    Matrix mat(n, Array(n));

    mat[0][1] = 10;
    mat[0][2] = 15;
    mat[0][5] = 1;

    mat[1][0] = 15;
    mat[1][2] = 11;
    mat[1][4] = 2;
    mat[1][5] = 9;

    mat[2][0] = 15;
    mat[2][1] = 11;
    mat[2][3] = 6;
    
    mat[3][2] = 6;
    mat[3][4] = 9;

    mat[4][1] = 2;
    mat[4][3] = 9;
    mat[4][5] = 14;

    mat[5][0] = 1;
    mat[5][1] = 9;
    mat[5][4] = 14;

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
        cout << "Finding the minimum key" << endl;
        for(int j = 0; j < n; j++) cout << f[j] << " "; cout << endl;

        int u = find_min(k, f);
        f[u] = true;
        cout << "Minimum key found: " << u << endl;
        cout << "Mark " << u << endl;

        range(v, n) {
            if (mat[u][v] &&
                f[v] == false &&
                mat[u][v] < k[v]) {
                cout << "mat[" << u << "][" << v << "] < k[" << v << "]" << endl;
                p[v] = u;
                k[v] = mat[u][v];
            }
        }
    }

    ll result = 1;
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
