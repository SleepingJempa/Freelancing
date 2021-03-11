#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 1e6;

void countSort(int *arr, int n);

int main()
{
    int n;
    scanf("%d", &n);

    int* arr = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    countSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void countSort(int *arr, int n)
{
    int *cnt = (int *) malloc(MAX * sizeof(int));
    memset(cnt, 0, MAX * sizeof(int));

    for (int i = 0; i < n; i++)
        cnt[arr[i]]++;
    
    for(int i = 0, j = 0; i < MAX; i++)
        while(cnt[i]--) arr[j++] = i;
}