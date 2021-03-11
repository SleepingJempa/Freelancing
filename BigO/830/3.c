#include <stdlib.h>
#include <stdio.h>

const int N = 6;

int main() {
    for(int i = 0; i < N; i++) {
        printf("# ");
        for(int j = 0; j < i-1; j++) {
            printf("@ ");
        }
        if(i) printf("%d\n", i+1); else printf("\n");
    }
}