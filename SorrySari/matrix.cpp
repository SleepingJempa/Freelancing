#include <iostream>

using namespace std;

void swapMaxAndMin(float **mat, int row, int col) {
    // متغیر های مربوط به کوچیکترین و بزرگترین
    int iMin = 0;
    int jMin = 0;
    int vMin = mat[0][0];
    int iMax = 0;
    int jMax = 0;
    int vMax = mat[0][0];

    // پیمایش کل ماتریس
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            // اگر عضو فعلی از کوچکترین عضوی که تا کنون پیدا شده کوچکتر باشد
            if (mat[i][j] < vMin) {
                vMin = mat[i][j];
                iMin = i;
                jMin = j;
            }

            // اگر عضو فعلی از بزرگترین عضوی که تا کنون پیدا شده بزرگتر باشد
            if (mat[i][j] > vMax) {
                vMax = mat[i][j];
                iMax = i;
                jMax = j;
            }
        }
    }

    // جا به جا کردن آن دو
    int tmp = mat[iMax][jMax];
    mat[iMax][jMax] = mat[iMin][jMin];
    mat[iMin][jMin] = tmp;
}

int main() {
    int n, m;
    cin >> n >> m;

    // تخصیص حافضه به صورت پویا
    float **mat = (float **) malloc(n * sizeof(float*));
    for(int i = 0; i < n; i++)
        mat[i] = (float *) malloc(m * sizeof(float));

    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < m; j++) {
            //دریافت ماتریس
            cin >> mat[i][j];
        }
    }

    swapMaxAndMin(mat, n, m);

    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < m; j++) {
            // چاپ ماتریس
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}