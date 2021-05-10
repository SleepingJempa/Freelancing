#include <iostream>

using namespace std;

void getNumbers(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void sortNumbers(int* arr, int n) {
    cout << "Sorting the array ussing bubble method" << endl;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

float findMedian(int* arr, int n) {
    if (n % 2 == 1) {
        return arr[n / 2];
    } else {
        return (float)(arr[n / 2] + arr[n / 2 - 1]) / 2;
    }
}

void showMedian(int* arr, int n) {
    float median = findMedian(arr, n);

    cout << "Median is: " << median << endl;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    getNumbers(arr, n);
    sortNumbers(arr, n);
    showMedian(arr, n);
}