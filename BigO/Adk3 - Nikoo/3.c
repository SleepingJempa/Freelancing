#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j+1], &arr[j]);
            }
        }
    }
}

int minDistance(int *arr, int n) {
    if (n==1) return NULL;
    int minD = arr[1] - arr[0];
    for(int i = 1; i < n; i++) {
        if (arr[i] - arr[i-1] < minD) minD = arr[i] - arr[i-1];
    }
    return minD;
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *) malloc (n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int ans = minDistance(arr, n);

    printf("Min distance is: %d", ans);
}