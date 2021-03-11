#include <iostream>
#include <vector>

using namespace std;

bool isBipartite(vector<vector<int>> A, int v, vector<int> &color);
int numberOfComponents(vector<vector<int>> A, int v);


int main() {
    int v; // vertices
    int e; // edges

    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    printf("Enter the number of edges: ");
    scanf(" %d", &e);

    vector<vector<int>> A(v, vector<int>(v, 0)); // Adjacency matrix
    vector<int> c(v, -1); // color of vertices

    for(int i = 0; i < e; i++) {
        printf("Enter two vertices which will be connected: ");
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        A[u][v] = A[v][u] = 1;
    }

    if (isBipartite(A, v, c)) {
        printf("The graph is bipartite and the coloring is as below:\n");

        for(int i = 0; i < v; i++) {
            printf("V[%d] : %d\n", i+1, c[i]);
        }
    } else {
        printf("The graph is not bipartite\n");
    }

    printf("The graph has %d components.\n", numberOfComponents(A, v));
}

bool isBipartite(vector<vector<int>> A, int v, vector<int> &c) {
    c[0] = 0;

    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(A[i][j]) {

                if (c[i] == c[j]) return false;

                c[j] = c[i] ^ 1;
            }
        }
    }

    return true;
}

int numberOfComponents(vector<vector<int>> A, int v)
{
    vector<int> c(v, -1);

    int cnt = 0;
    for(int i = 0; i < v; i++) {
        if(c[i] == -1) c[i] = cnt++;
        for(int j = 0; j < v; j++) {
            if(A[i][j]) {
                c[j] = cnt;
            }
        }
    }

    return cnt;
}