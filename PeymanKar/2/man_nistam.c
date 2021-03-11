#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int N = 101;

int main() {
    char *str;
    char *sub;

    str = (char *) malloc(N * sizeof(char));
    sub = (char *) malloc(N * sizeof(char));

    // Getline str
    // Getline sub

    int n = strlen(str);
    int m = strlen(sub);

    int ans = 0;

    int must = 0;
    int size = 0;
    char result[N];

    for(int i = 0; i < n; i++) {
        int j = 0;
        int _i = i;
        while(i < n && j < m && str[i] == sub[j]) {
            i++;
            j++;
        }

        if (j == m) {
            ans++;
            i--;
        } else {
            i = _i;
            result[size++] = str[i];
        }
    }
    printf("%d\n", ans);
        
    for(int i = 0; i < size; i++) {
        printf("%c", result[i]);
    }
}