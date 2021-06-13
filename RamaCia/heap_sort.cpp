#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &a, int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && a[left] > a[i]) {
        swap(a[i], a[left]);
        heapify(a, n, left);
    }

    if (right < n && a[right] > a[i]) {
        swap(a[i], a[right]);
        heapify(a, n, right);
    }
}

void heapSort(vector<int> &a) {
    int n = a.size();

    for(int i = n/2-1; i >= 0; i--) {
        heapify(a, n, i);
    }

    for(int i = n-1; i > 0; i--) {
        swap(a[0], a[i]);

        heapify(a, i, 0);
    }
}

int main() {
    vector<int> a;
    int x;

    while (cin >> x) {
        a.push_back(x);
    }

    heapSort(a);

    for(int i = 0; i < a.size(); i++) cout << a[i] << ' '; cout << endl;
}