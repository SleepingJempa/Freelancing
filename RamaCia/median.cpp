#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// #include "heap.h"
#include <iostream>

template <typename T>
class heap
{
private:
    std::vector<T> heapArray;
public:
    heap();
    ~heap();
    T extract();
    T min();
    void heapify(int index);
    void insert(T value);
    void remove(int index);
    void set(int index, T value);
    void inverseHeapify(int index);
    int size();
    int left(int index);
    int right(int index);
    int parent(int index);
    void log();
    bool empty() { return size() == 0; }
    T peek() { return heapArray[0]; }
};

template <typename T>
heap<T>::heap()
{
}


template <typename T>
heap<T>::~heap()
{
}

template <typename T>
T heap<T>::min()
{
    return heapArray[0];
}


template <typename T>
T heap<T>::extract()
{
    if (heapArray.empty()) return NULL;

    T root = heapArray[0];

    if (heapArray.size() > 1)
    {
        heapArray[0] = heapArray[heapArray.size() - 1];
        heapify(0);
    }

    heapArray.pop_back();

    return root;
}



template <typename T>
void heap<T>::heapify(int index)
{
    int leftChild = left(index);
    int rightChild = right(index);
    int smallerChild = index;

    if (leftChild < heapArray.size() && heapArray[leftChild] < heapArray[index])
    {
        smallerChild = leftChild;
    }
    
    if (rightChild < heapArray.size() && heapArray[rightChild] < heapArray[index])
    {
        if (smallerChild == index) {
            smallerChild = rightChild;
        } else {
            smallerChild = (heapArray[rightChild] < heapArray[leftChild] ? rightChild : leftChild);
        }
    }

    if (smallerChild != index)
    {
        std::swap(heapArray[smallerChild], heapArray[index]);
        heapify(smallerChild);
    }
}



template <typename T>
void heap<T>::insert(T value)
{
    heapArray.push_back(value);
    int index = heapArray.size() - 1;
    inverseHeapify(index);
}



template <typename T>
void heap<T>::remove(int index)
{
    set(index, INT32_MIN);
    extract();
}



template <typename T>
void heap<T>::set(int index, T value)
{
    heapArray[index] = value;
    inverseHeapify(index);
}



template <typename T>
void heap<T>::inverseHeapify(int index)
{
    while(index && heapArray[index] < heapArray[parent(index)])
    {
        std::swap(heapArray[index], heapArray[parent(index)]);
        index = this->parent(index);
    }
}



template <typename T>
int heap<T>::left(int index)
{
    return 2 * index + 1;
}



template <typename T>
int heap<T>::right(int index)
{
    return 2 * index + 2;
}



template <typename T>
int heap<T>::parent(int index)
{
    return (index-1) / 2;
}



template <typename T>
void heap<T>::log()
{
    for(auto element : heapArray)
    {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}



template <typename T>
int heap<T>::size()
{
    return heapArray.size();
}

template <typename T>
void add(heap<T> &minHeap, heap<T> &maxHeap, T x) {
    if (!minHeap.empty() && x < minHeap.peek()) {
        maxHeap.insert(-x);
        if (maxHeap.size() > minHeap.size()) {
             minHeap.insert(-maxHeap.extract());
        }
    } else {
        minHeap.insert(x);
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.insert(-minHeap.extract());
        }
    }
}

template <typename T>
float getMedian(heap<T> &minHeap, heap<T> &maxHeap) {
    if (minHeap.size() < maxHeap.size()) {
        return -maxHeap.peek();
    } else if (maxHeap.size() < minHeap.size()) {
        return minHeap.peek();
    } else {
        return (double) (minHeap.peek() - maxHeap.peek()) / (double) 2;
    }
}

int main() {
    heap<int> mn, mx;

    
    int x;
    while (cin >> x) {
        add(mn, mx, x);
        cout << getMedian(mn, mx) << endl;
    }
}