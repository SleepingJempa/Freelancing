// 2 Polymorphism
#include <iostream>
using namespace std;

class SumTool {
public:
    int sum(int a, int b, int c) {
        return a + b + c;
    }
    int sum(int a, int b) {
        return a + b;
    }
};

int main() {
    SumTool tool;
    cout << tool.sum(3, 2, 5) << endl; // 10
    cout << tool.sum(1, 4) << endl; // 5
}