#include <stdlib.h>
#include <stdio.h>

const int N = 10;

int main() {
    int yekiDarMion = 0;
    int setaDarMion = 0;

    for(int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        if (i % 2 == 0) yekiDarMion += x;
        if (i % 3 == 0) yekiDarMion += x;
    }

    printf("Yeki Dar Mion = %d\n", yekiDarMion);
    printf("Seta Dar Mion = %d\n", yekiDarMion);
}