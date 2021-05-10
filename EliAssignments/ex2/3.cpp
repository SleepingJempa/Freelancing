#include <iostream>

using namespace std;

int main() {
    cout << "Enter two number to calculate a / b." << endl;
    cout << "(if b is zero then an exception will raise)" << endl;

    int a, b;
    cin >> a >> b;
    
    try {
        if (b == 0) {
            throw "Divison by zero!!";
        }
        cout << (float)a/b << endl;
    } catch(const char* err) {
        cout << err << endl;
    }
}