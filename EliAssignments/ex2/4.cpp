#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char *s = new char[256];
    char *t = new char[256];
    
    cin >> s >> t;

    char *r = new char[512];

    for(int i = 0; i < strlen(s) + strlen(t); i++) {
        r[i] = (i < strlen(s) ? s[i] : t[i - strlen(s)]);
    }

    cout << r << endl;
}