#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char ***board_read(char *name) {
    FILE *file = fopen(name, "r");

    int n, m;
    fscanf(file, "%d %d", &n, &m);

    if (n == 0 || m == 0) return NULL;

    char ***board = (char ***) malloc(n * sizeof(char **));
    for(int i = 0; i < n; i++) {
        board[i] = (char **) malloc(m * sizeof(char *));
        for(int j = 0; j < m; j++) {
            board[i][j] = (char *) malloc(50 * sizeof(char));
        }
    }

    while (!feof(file)) {
        int i, j;
        fscanf(file, "%d %d", &i, &j);
        fscanf(file, "%s", board[i][j]);
    }

    fclose(file);

    return board;
}