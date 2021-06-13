#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Array;
typedef vector<Array> Matrix;

Matrix new_Matrix(int n) { return Matrix(n, Array(n)); }
void Strassen(Matrix &A, Matrix&B, Matrix &C);
void Multiply(Matrix &A, Matrix&B, Matrix &C);
void Addition(Matrix &A, Matrix&B, Matrix &C);
void Subtract(Matrix &A, Matrix&B, Matrix &C);
void showArray(Array &a) { for(int &k : a) cout << k << " "; cout << endl; }
void showMatrix(Matrix &A) { for(Array &a: A) showArray(a); }

int main() {
    Matrix A = new_Matrix(4);
    Matrix B = new_Matrix(4);
    Matrix C = new_Matrix(4);

    A[0][2] = 2;
    A[1][0] = 1;
    A[3][3] = 4;
    
    for(int i = 0; i < 4; i++) B[i][i] = 1;

    Strassen(A, B, C);
    showMatrix(C);
}

void Strassen(Matrix &A, Matrix&B, Matrix &C) {
    int n = A.size();

    if (n == 2) {
        return Multiply(A, B, C);
    } else {
        int k = n / 2;
        Matrix A11 = new_Matrix(k);
        Matrix A12 = new_Matrix(k);
        Matrix A21 = new_Matrix(k);
        Matrix A22 = new_Matrix(k);
        
        Matrix B11 = new_Matrix(k);
        Matrix B12 = new_Matrix(k);
        Matrix B21 = new_Matrix(k);
        Matrix B22 = new_Matrix(k);
        
        Matrix C11 = new_Matrix(k);
        Matrix C12 = new_Matrix(k);
        Matrix C21 = new_Matrix(k);
        Matrix C22 = new_Matrix(k);

        Matrix M1 = new_Matrix(k);
        Matrix M2 = new_Matrix(k);
        Matrix M3 = new_Matrix(k);
        Matrix M4 = new_Matrix(k);
        Matrix M5 = new_Matrix(k);
        Matrix M6 = new_Matrix(k);
        Matrix M7 = new_Matrix(k);

        Matrix AR = new_Matrix(k);
        Matrix BR = new_Matrix(k);

        // Filling Aij and Bij
        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < n / 2; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][n / 2 + j];
                A21[i][j] = A[n / 2 + i][j];
                A22[i][j] = A[n / 2 + i][n / 2 + j];
                
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][n / 2 + j];
                B21[i][j] = B[n / 2 + i][j];
                B22[i][j] = B[n / 2 + i][n / 2 + j];
            }
        }

        // M1 = (A0 + A3) x (B0 + B3)
        Addition(A11, A22, AR);
        Addition(B11, B22, BR);
        Strassen(AR, BR, M1);

        // M2 = (A2 + A3) × B0
        Addition(A21, A22, AR);
        Strassen(AR, B11, M2);
        
        // M3 = A0 × (B1 - B3)
        Subtract(B12, B22, BR);
        Strassen(A11, BR, M3);
        
        // M4 = A3 × (B2 - B0)
        Subtract(B21, B11, BR);
        Strassen(A22, BR, M4);
        
        // M5 = (A0 + A1) × B3
        Addition(A11, A12, AR);
        Strassen(AR, B22, M5);
        
        // M6 = (A2 - A0) × (B0 + B1)
        Subtract(A21, A11, AR);
        Addition(B11, B12, BR);
        Strassen(AR, BR, M6);
        
        // M7 = (A1 - A3) × (B2 + B3)
        Subtract(A12, A22, AR);
        Addition(B21, B22, BR);
        Strassen(AR, BR, M7);
        
        // C0 = M1 + M4 - M5 + M7
        Addition(M1, M4, AR);
        Subtract(M7, M5, BR);
        Addition(AR, BR, C11);
        
        // C1 = M3 + M5
        Addition(M3, M5, C12);
        
        // C2 = M2 + M4
        Addition(M2, M4, C21);
        
        // C3 = M1 - M2 + M3 + M6
        Subtract(M1, M2, AR);
        Addition(M3, M6, BR);
        Addition(AR, BR, C22);

        // Fill C
        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < n / 2; j++) {
                C[i][j] = C11[i][j];
                C[i][n / 2 + j]  = C12[i][j];
                C[n / 2 + i][j]  = C21[i][j];
                C[n / 2 + i][n / 2 + j]  = C22[i][j];
            }
        }
    }
}

void Multiply(Matrix &A, Matrix&B, Matrix &C) {
    int n = A.size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = 0;
            for(int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void Addition(Matrix &A, Matrix&B, Matrix &C) {
    int n = A.size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void Subtract(Matrix &A, Matrix&B, Matrix &C) {
    int n = A.size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

