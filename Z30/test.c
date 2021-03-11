#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int xyz(char *p) {
    char *q;
    int cnt = 0;
    q = p;

    if(strlen(p) == 0) return cnt;

    while(*q != '\0') {
        cnt += *q - 48;
        q++;
    }

    return cnt;
}

int main() {
    int i, j = 256;
    for(i = 1; i<=4; i++) {
        j >>= 1;
    }
    printf("%d", j);
}