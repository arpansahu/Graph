#include<stdio.h>
#include<stdlib.h>

#define N 6

struct Node{
    int destination;
    struct Node * next;
};

struct Edge{
    int source,destination;
};

struct Graph{
    struct Node * head [N];
};

struct Graph * createGraph(struct Edge  edges[], int noOfEdges) {
    struct Graph * graph = (struct Graph *)malloc(sizeof(struct Graph));
    for (int i = 0; i < N; ++i) graph->head[i] = NULL;
    for (int j = 0; j < noOfEdges; ++j) {
        //for src to dest
        struct Node * newNode = (struct Node  *)malloc(sizeof(struct Node));
        newNode->destination = edges[j].destination;
        newNode->next = graph->head[edges[j].source];
        graph->head[edges[j].source] = newNode;
        //dest to src
        struct Node * newNode2 = (struct Node *)malloc(sizeof(struct Node));
        newNode2->destination = edges[j].source;
        newNode2->next = graph->head[edges[j].destination];
        graph->head[edges[j].destination] = newNode2;
    }
    return graph;
}

void printGraph(struct Graph * graph){
    for (int i = 0; i < N; ++i) {
        struct Node * temp = graph->head[i];
        while(temp){ printf("(%d -> %d)",i,temp->destination);temp = temp->next;}printf("\n");
    }
}
int main(void)
{
    struct Edge edges[] =
            {
                    { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
                    { 3, 2 }, { 4, 5 }, { 5, 4 }
            };

    int  noOfEdges = sizeof(edges)/sizeof(edges[0]);
    struct Graph *graph = createGraph(edges, noOfEdges);
    printGraph(graph);
    return 0;
}
