#include <stdio.h>
#include <stdlib.h>

void pal_par(char *str);

int main()
{
    char* str;
    scanf("%s", &str);

    pal_par(str);
}

void pal_par(char *str)
{
    int n = strlen(str);
    if (n == 1) return printf("%c", str[0]);

    for(int i = 0; i < n; i++)
    {
        printStringSplitted(str, i);
        for(int j = i; j < n; j++)
            if (isPalindrome(str, i, j)) {
                printString(str, i, j);
            }
    }
}