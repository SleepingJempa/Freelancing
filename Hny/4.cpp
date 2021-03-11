#include <iostream>

using namespace std;

int* construct(int);
void destruct(int*, int);

int main() {
    const int entry = 50;

    int i;

    int* x = construct(entry);
    x[0] = 1;
    x[1] = 1;

    for(i = 2; i < entry; i++) {
        x[i] = x[i-1] + x[i-2];
    }

    for(i = 1; i < entry; i++) {
        cout << x[i] << endl;
    }

    destruct(x, entry);
}

int* construct(int entry) {
    int *arr = new int[entry];

    return arr;
}

void destruct(int* arr, int entry) {
    delete[] arr;
}