#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &a, int n, int i)
{
	int large = i; 
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 

	if (left < n && a[left] > a[large])
		large = left;

	if (right < n && a[right] > a[large])
		large = right;

	if (large != i) {
		swap(a[i], a[large]);

		heapify(a, n, large);
	}
}

void build_heap(vector<int> &a, int n)
{
	for (int i = (n / 2) - 1; i >= 0; i--) {
		heapify(a, n, i);
	}
}

int main()
{
	vector<int> a;
    int x;

    while(cin >> x) a.push_back(x);

	int n = a.size();

	build_heap(a, n);

	for(int i = 0; i < n; i++) cout << a[i] << " ";
}
