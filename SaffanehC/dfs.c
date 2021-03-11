#include <stdlib.h>
#include <stdio.h>

typedef struct AdjListNode AdjListNode;
typedef struct ADjList AdjList;
typedef struct Graph Graph;

struct AdjListNode
{
    int data;
    AdjListNode *next;
};

struct ADjList
{
    AdjListNode *head;
};

struct Graph
{
    int v;
    AdjList *adj;
};

AdjListNode *newAdjListNode(int data)
{
    AdjListNode *adjListNode =
      (AdjListNode *) malloc(sizeof(AdjListNode));
    adjListNode->data = data;
    adjListNode->next = NULL;
    return adjListNode;
}

Graph *createGraph(int v)
{
    Graph *graph =
      (Graph *) malloc(sizeof(Graph));
    graph->v = v;
    graph->adj = (AdjList *) malloc(v * sizeof(AdjList));

    for (int i = 0; i < n; i++)
        graph->adj[i].head = NULL;
    
    return graph;
}

void addEdge(Graph *graph, int src, int data)
{
    AdjListNode *adjListNode = newAdjListNode(data);

    adjListNode->
}

int main()
{

}