#include <iostream>
#include <stack>
#include <string>

using namespace std;

void printStackReversed(stack<int> s) {
    string ans;

    while(! s.empty()) {
        string n = to_string(s.top()) + " ";
        s.pop();
        ans = n + ans;
    }

    cout << ans;
}

int main() {
    stack<int> s;
    
    s.push(1);
    s.push(9);
    s.push(5);
    s.push(2);

    printStackReversed(s);
}