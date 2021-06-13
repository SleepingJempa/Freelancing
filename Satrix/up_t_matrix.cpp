// Saba Avazeh

#include <iostream>
#include <vector>

using namespace std;

typedef float Number;
typedef vector<Number> Array;
typedef vector<Array> Matrix;

void to_upper(Matrix &mat, int n) {
    for(int j = 0; j < n; j++) {
        for(int i = n-1; i > j; i--) {
            for(int k = 0; k < n; k++) {
                mat[i][k] = mat[i][k] - ((mat[i][j]/mat[i-1][j]) * mat[i-1][k]);
            }
        }
    }
}

double determinant(Matrix &mat, int n) {
    to_upper(mat, n);

    double result = 1;

    for(int i = 0; i < n; i++) {
        result *= mat[i][i];
    }

    return result;
}

void show_matrix(const Matrix &mat, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%2.f ", mat[i][j]);
        }
        cout << endl;
    }
}

int main() {
    const int n = 5;
    Matrix mat(n, Array(n));

    int k = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mat[i][j] = k++;
        }
    }

    cout << endl;
    

    cout << "Matrix is: " << endl;
    show_matrix(mat, n);

    cout << endl;

    cout << "Determinant is equal to: " << determinant(mat, n) << endl;

    show_matrix(mat, n);
}