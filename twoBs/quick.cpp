#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Array;

void showArray(Array &arr) {
    for(int &n : arr) cout << n << " "; cout << endl;
}

void quicksort(Array &arr, int left, int right) {
    if (left > right) return;
    int p = left;
    int i = left;
    int j = right;

    cout << "Sorting [" << left << ", " << right << "] Subarray\n";
    cout << "Selected pivot is " << arr[p] << " with index of " << p << "\n";

    while (i < j) {
        while (arr[i] <= arr[p] && i <= right) {
            i++;
        }

        while (arr[j] > arr[p] && j >= left) {
            j--;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[j], arr[p]);

    cout << "Array after this step of sorting:\n";
    showArray(arr);

    quicksort(arr, 0, j-1);
    quicksort(arr, j+1, right);

}

int main(void) {
    int n;
    cout << "How many numbers you wanna sort?\n";
    cin >> n;

	Array arr(n);

    cout << "Enter " << n << " numbers.\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

	quicksort(arr, 0, n-1);
}