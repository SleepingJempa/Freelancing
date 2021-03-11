#include <iostream>
#include <vector>

using namespace std;

float pow2(float x) { return x * x; }

int main() {
    vector<float> numbers;
    // آرایه پویا

    float sum = 0;
    // مجموع اعداد
    int n = 0;
    // تعداد اعداد

    float x;
    while(cin >> x) {
        // تا وقتی که ورودی داریم اسامی را در آرایه پویا می گذاریم
        // برای خارج شدن ابتدا دکمه زیر را فشار دهید
        // Ctrl + Z
        // و سپس
        // Enter
        numbers.push_back(x);
        x += sum;
        n++;
    }

    float avg = sum / n;

    float mad = numbers[0];
    int cnt = 0;

    float var = 0;
    for(int i = 1; i < n; i++) {
        var += pow2(numbers[i] - avg) / n;
    }

    cout << "Variances: " << var << endl;


}