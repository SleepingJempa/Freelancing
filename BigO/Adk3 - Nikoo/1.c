#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct scientist {
    char name[15];
    char family[20];
    int index;
    int articles;
    int *c;

} scientist;

void calculateIndex(scientist* arr)
{
    int n = sizeof(arr) / sizeof(scientist);
    for (int i = 0; i < n; i++)
    {
        int maxCnt = arr[i].c[0];
        for(int j = 0; j < n; j++) if(arr[j].c[j] > maxCnt) maxCnt = arr[i].c[j];

        for (int r = 0; r <= maxCnt; r++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if (arr[i].c[j] >= r) cnt++;
            }
            if (cnt > maxCnt) maxCnt = cnt;
        }

        arr[i].index = maxCnt;
    }
}

void sortScientists(scientist* arr) {
    int n = sizeof(arr) / sizeof(scientist);

    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < n; j++) {
            if(arr[i].index < arr[j].index) {
                scientist tmp;
                strcpy(tmp.name, arr[i].name);
                strcpy(tmp.family, arr[i].family);
                tmp.index = arr[i].index;
                tmp.articles = arr[i].articles;
                tmp.c = (int *) malloc(arr[i].articles * sizeof(int));
                for(int k = 0; k < n; k++) tmp.c[k] = arr[i].c[k];

                strcpy(arr[i].name, arr[j].name);
                strcpy(arr[i].family, arr[j].family);
                arr[i].index = arr[j].index;
                arr[i].articles = arr[j].articles;
                arr[i].c = (int *) malloc(arr[j].articles * sizeof(int));
                for(int k = 0; k < n; k++) arr[i].c[k] = arr[j].c[k];

                strcpy(arr[j].name, tmp.name);
                strcpy(arr[j].family, tmp.family);
                arr[j].index = tmp.index;
                arr[j].articles = tmp.articles;
                arr[j].c = (int *) malloc(tmp.articles * sizeof(int));
                for(int k = 0; k < n; k++) tmp.c[k] = tmp.c[k];
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    scientist *arr = (scientist *) malloc(n * sizeof(scientist)); // scientist ha

    for(int i = 0; i < n; i++)
    {
        printf("Enter the name of the scientist: ");
        scanf("%d", &arr[i].name);
        
        printf("Enter the family of the scientist: ");
        scanf("%d", &arr[i].family);
        
        printf("Enter the number of articles of the scientist: ");
        scanf("%d", &arr[i].articles);

        arr[i].c = (int *) malloc(arr[i].articles * sizeof(int));
        printf("Now enter %d article reference count:", arr[i].articles);
        for(int j = 0; j < arr[i].articles; j++) scanf("%d", &arr[i].c[j]);
    }

    calculateIndex(arr);
    sortScientists(arr);

    for(int i = 0; i < n; i++)
    {
        printf("Scientist %d [ %s %s ] has %d articles\n", i+1, arr[i].name, arr[i].family, arr[i].articles);
    }
}