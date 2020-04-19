#include "iostream"
using namespace std;

struct Edge {
    int source,destination,weight;
};

struct Node{
    int destination;
    int weight;
    Node * next;
};

class Graph{
    Node * getAdjListNode(int destination,Node * head ,int weight ){
        Node * newNode = new Node;
        newNode->destination = destination;
        newNode->weight = weight;
        newNode->next = head;
    return newNode;
    }


public:
    Node ** head;
    int N;
    Graph(Edge edges[],int noOfEdges,int N){
        head = new Node * [N]();
        this->N = N;

        for (int i = 0; i < N; ++i) head[i] = nullptr;

        for (int j = 0; j < noOfEdges; ++j) {
            head[edges[j].source] = this->getAdjListNode(edges[j].destination,head[edges[j].source],edges[j].weight);
            head[edges[j].destination] = this->getAdjListNode(edges[j].source,head[edges[j].destination],edges[j].weight);
        }
    }
    ~Graph() {
        for (int i = 0; i < N; i++)
            delete[] head[i];
        delete[] head;
    }
};

void printGraph(Graph  graph){

    for (int i = 0; i < graph.N; ++i) {
        Node * ptr = graph.head[i];
        cout << i <<"--";
        while (ptr != nullptr)
        {
            cout << " -> " << ptr->destination<<" ("<<ptr->weight<<") " << " ";
            ptr = ptr->next;
        }cout <<"\n";
    }
    cout << endl;
}

int main()
{
    Edge edges[] =
            {
                    { 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
                    { 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }
            };
    int N = 6;
    int n = sizeof(edges)/sizeof(edges[0]);
    Graph graph(edges, n, N);
    printGraph(graph);
    return 0;
}