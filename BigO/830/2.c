#include <stdlib.h>
#include <stdio.h>

const int MAXN = 100;

int main() {
    int arr[MAXN];
    int chk[MAXN];

    for (int i = 0; i < MAXN; i++) {
        scanf("%d", &arr[i]);
        chk[i] = 1;
    }

    int bestNum = 0;
    int bestCnt = 0;

    for(int i = 0; i < MAXN; i++) {
        if (!chk[i]) {
            continue;
        }
        int num = arr[i];
        int cnt = 0;
        for(int j = i; j < MAXN; j++) {
            if (arr[j] == num) {
                cnt++;
                chk[j] = 0;
            }
        }

        if (cnt > bestCnt) {
            bestCnt = cnt;
            bestNum = num;
        }
    }

    printf("Number: %d, Times: %d\n", bestNum, bestCnt);
}