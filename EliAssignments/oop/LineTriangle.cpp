#include <iostream>

using namespace std;

class LineTriangleTool
{
private:
    int n;
    char c;
public:
    void getInput() { cin >> n >> c; }
    void line() { for(int i=0; i<n; i++) cout << c; cout << endl; }
    void triangle() { for(int l=1; l<=n; l++) { for(int i=0; i<l; i++) cout << c; cout << endl; } }
};



int main() {
    LineTriangleTool ltt;
    ltt.getInput();

    ltt.line();
    ltt.triangle();
}