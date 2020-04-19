#include<stdio.h>
#include<stdlib.h>

#define N 6

struct Node{
    int destination,weight;
    struct Node * next;
};

struct Edge{
    int source,destination,weight;
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
        newNode->weight = edges[j].weight;
        newNode->next = graph->head[edges[j].source];
        graph->head[edges[j].source] = newNode;
        //for dest to src
        struct Node * newNode2 = (struct Node *) malloc(sizeof(struct Node));
        newNode2->destination = edges[j].source;
        newNode2->weight = edges[j].weight;
        newNode2->next = graph->head[edges[j].destination];
        graph->head[edges[j].destination] = newNode2;
    }
    return graph;
}

void printGraph(struct Graph * graph){
    for (int i = 0; i < N; ++i) {
        struct Node * temp = graph->head[i];
        while(temp){ printf("(%d -> %d) (%d) ",i,temp->destination,temp->weight);temp = temp->next;}printf("\n");
    }
}
int main(void)
{
    struct Edge edges[] =
            {
                    { 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
                    { 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }
            };


    int  noOfEdges = sizeof(edges)/sizeof(edges[0]);
    struct Graph *graph = createGraph(edges, noOfEdges);
    printGraph(graph);
    return 0;
}
