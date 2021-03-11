#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    FILE *f = fopen("m.txt", "rw");

    char text[1024];
    int i = 0;
    while (!feof(f)) fscanf(f, "%c", &text[i++]);
    char result[1024];
    i = 0;
    int j = 0;
    while(text[i] != '\0') {
        if (text[i]==' ') {
            result[j++] = 't';
        } else {
            result[j++] = text[i];
        }
        i++;
    }

    fprintf(f, "%s", result);

    fclose(f);
}