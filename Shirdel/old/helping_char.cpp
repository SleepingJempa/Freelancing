#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);

    char s[1000000];
    scanf("%s", s);

    int n = strlen(s);
    // int n = 50;

    // for(int i = 0; i < n; i++) {
    //     s[i] = '0';
    // }
    // s[0] = '1';

    int t = n - 1;

    while(true) {
        if (s[t] > '0') {
            s[t]--;
            break;
        } else {
            s[t] = '9';
        }

        t--;
    }

    t = 0;

    while(t < n) {
        if (t == 0 && s[t] == '0') {
            t++;
            continue;
        };
        printf("%c", s[t]);
        t++;
    }
}