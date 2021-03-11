#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int check(char *a, char *b) {
    if (strlen(a) != strlen(b)) return 0;
    while (*a != '\0' && *b != '\0') {
        if (*a != *b) return 0;
        a++; b++;
    }
    return 1;
}

int main()
{
    int n = 20;
    char **arr = (char **) malloc(n * sizeof(char *));
    for(int i = 0; i < n; i++)
        arr[i] = (char *) malloc(n * sizeof(char));
    
    for(int i = 0; i < n; i++)
        scanf("%s", &arr[i]);

    int flag = -1;
    for(int i = 0; i < n; i++)
        if(check("Amir", arr[i])) {
            flag = i;
            break;
        }
    
    if (flag == -1) {
        printf("Vojood nadarad!");
    } else {
        printf("%d", flag);
    }
}