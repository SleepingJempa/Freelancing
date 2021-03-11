#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct scientist scientist;

typedef struct scientist {
    char name[15];
    char family[20];
    int index;
    int paper_count;
    int *c;

};

void sort(scientist* scis) {
    int n = sizeof(scis) / sizeof(scientist);

    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < n; j++) {
            if(scis[i].index < scis[j].index) {
                scientist temp;
                strcpy(temp.name, scis[i].name);
                strcpy(temp.family, scis[i].family);
                temp.index = scis[i].index;
                temp.paper_count = scis[i].paper_count;
                temp.c = (int *) malloc(scis[i].paper_count * sizeof(int));
                for(int k = 0; k < n; k++) {
                    temp.c[k] = scis[i].c[k];
                }

                strcpy(scis[i].name, scis[j].name);
                strcpy(scis[i].family, scis[j].family);
                scis[i].index = scis[j].index;
                scis[i].paper_count = scis[j].paper_count;
                scis[i].c = (int *) malloc(scis[j].paper_count * sizeof(int));
                for(int k = 0; k < n; k++) {
                    scis[i].c[k] = scis[j].c[k];
                }


                strcpy(scis[j].name, temp.name);
                strcpy(scis[j].family, temp.family);
                scis[j].index = temp.index;
                scis[j].paper_count = temp.paper_count;
                scis[j].c = (int *) malloc(temp.paper_count * sizeof(int));
                for(int k = 0; k < n; k++) {
                    temp.c[k] = temp.c[k];
                }
            }
        }
    }
}

void index(scientist* scis)
{
    int n = sizeof(scis) / sizeof(scientist);
    for (int i = 0; i < n; i++) {
        int best = scis[i].c[0];
        for(int j = 0; j < n; j++) {
            if(scis[j].c[j] > best) best = scis[i].c[j];
        }
        for (int r = 0; r <= best; r++) {
            int cnt = 0;


            for(int j = 0; j < n; j++) {
                if (scis[i].c[j] >= r) cnt++;
            }


            if (cnt > best) best = cnt;
        }

        scis[i].index = best;
    }
}

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    scientist *scis = (scientist *) malloc(n * sizeof(scientist));
    for(int i = 0; i < n; i++)
    {
        printf("name");
        scanf("%d", &scis[i].name);
        printf("family");
        scanf("%d", &scis[i].family);
        printf("number of papers");
        scanf("%d", &scis[i].paper_count);
        scis[i].c = (int *) malloc(scis[i].paper_count * sizeof(int));
        printf("enter %d papers:", scis[i].paper_count);
        for(int j = 0; j < scis[i].paper_count; j++) scanf("%d", &scis[i].c[j]);
    }
    index(scis);
    sort(scis);
    for(int i = 0; i < n; i++)
    {
        printf("scientist %d - full name = %s %s - paper_count = %d\n", i+1);
        printf("full name = %s %s", scis[i].name, scis[i].family);
        printf("paper_count = %d\n", scis[i].paper_count);
    }
}