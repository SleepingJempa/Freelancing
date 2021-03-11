#include<stdio.h>    
#include<stdlib.h>  

int main()
{
    int n;
    char *s;
    scanf("%s %s %s %d", &s, &s, &s, &n);

    int *b = (int *) malloc(10 * sizeof(int));

    int i = 0;
    while(n) {
        b[i++] = n & 1;
        n >>= 1;
    }

    printf("Your Number in Binary: ");
    while(i) {
        printf("%d", b[--i]);
    }
}  