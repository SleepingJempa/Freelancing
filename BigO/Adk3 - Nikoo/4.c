#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replace(char *a);

int main()
{

}

int replace(char *a) {
    char *r = (char *) malloc(strlen(a));
    int i = 0;
    while(*a) {
        if (*a == 'a') {
            *a++;
            if(*a == 'd') {
                while(*a != ' ' && !*a) {
                    *a++;
                }
            }
        }

        r[i++] = *a;
        *a++;
    }
}