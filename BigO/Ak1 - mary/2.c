#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* replaceWord(char* text, char* source, char* destination) 
{ 
    char* result; 
    int i, cnt = 0, dSize = strlen(destination), sSize = strlen(source); 
  
    for (i = 0; text[i] != '\0'; i++) if (strstr(&text[i], source) == &text[i]) { cnt++; i += sSize - 1; }

    result = (char*)malloc(i+cnt*(dSize-sSize)+1); 
    i = 0; 
    while (*text)
        if (strstr(text, source) == text) { 
            strcpy(&result[i], destination); 
            i = i+ dSize; 
            text = text + sSize; 
        } else result[i++] = *text++;
    result[i] = '\0'; 
    return result; 
} 

int main() {
    FILE *wrongFile = fopen("D:\\report.txt", "r");
    FILE *fixedFile = fopen("D:\\revised.txt", "w");
    char allText[1024];
    int i = 0;
    while (!feof(wrongFile)) fscanf(wrongFile, "%c", &allText[i++]);
    char *resultText = replaceWord(allText, "programig", "programming");
    fprintf(fixedFile, "%s", resultText);
    fclose(wrongFile); fclose(fixedFile);
}