#include <iostream>

using namespace std;

bool check_capacity(int *arr, int n, int e) {
    // andaze array
    static int size = 0;
    
    // age por bood
    if (size == n) return false;

    // ezafe kardan
    arr[size++] = e;

    return true;
}

int main() {
    int *arr = new int[4];
    check_capacity(arr, 4, 2);
    check_capacity(arr, 4, 3);
    check_capacity(arr, 4, 1);
    check_capacity(arr, 4, 5);

    for(int i = 0; i < 4; i++) {
        cout << arr[i] << endl;
    }
}