#include <iostream>
#include <string.h>

using namespace std;

void myReverse(char *start, char *end);

const int N = 100;

int main() {
    char str[N];
    cin >> str;

    int n = strlen(str);

    myReverse(str, str+n);
    printf("%s", str);

}

void myReverse(char *start, char *end) {
    // If the start pointer is after the end pointer
    if (start >= end) {
        return;
    }

    end--;

    // Swap
    char tmp = *start;
    *start = *end;
    *end = tmp;

    // reverse rest of the string
    myReverse(++start, end);
}