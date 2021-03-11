#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int findPosition(char *s, char *t) {
    int n = strlen(s);
    int m = strlen(t);

    for (int i = 0; i < n-m; i++) {
        int j = 0;
        while(j < m-1 && t[j] == s[i+j]) {
            j++;
        }
        if (j == m) return i;
    }

    return -1;
}

int main() {
    char *s;
    char *t;
    scanf("%s", &s);
    scanf("%s", &t);

    int index = findPosition(s, t);

    printf("%d\n", index);
}