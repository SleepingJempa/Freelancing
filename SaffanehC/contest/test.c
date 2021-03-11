#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct e1_s e1_t;
typedef struct e2_s e2_t;

struct e1_s {
    char *str;
    e2_t *right;
    e1_t *next;
};

struct e2_s {
    int val;
    e2_t *next;
};

void myf(char *name) {
    FILE *fp;
    char str[100];
    int i, n;
    
    e1_t *p1, *head = NULL;
    e2_t *p2;

    fp = fopen(name, "r");
}


int main() {
    int n, m;
    char *s = give();
    printf("%s", s);
}