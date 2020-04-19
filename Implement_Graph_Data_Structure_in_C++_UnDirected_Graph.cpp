#include "iostream"
using namespace std;

struct Edge {
    int source,destination;
};

struct Node{
    int destination;
    Node * next;
};

class Graph{
    Node * getAdjListNode(int destination,Node * head ){
        Node * newNode = new Node;
        newNode->destination = destination;
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
            head[edges[j].source] = this->getAdjListNode(edges[j].destination,head[edges[j].source]);
            head[edges[j].destination] = this->getAdjListNode(edges[j].source,head[edges[j].destination]);
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
            cout << " -> " << ptr->destination << " ";
            ptr = ptr->next;
        }cout <<"\n";
    }
    cout << endl;
}

int main()
{
    Edge edges[] =
            {
                    { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
                    { 3, 2 }, { 4, 5 }, { 5, 4 }
            };
    int N = 6;
    int n = sizeof(edges)/sizeof(edges[0]);
    Graph graph(edges, n, N);
    printGraph(graph);
    return 0;
}