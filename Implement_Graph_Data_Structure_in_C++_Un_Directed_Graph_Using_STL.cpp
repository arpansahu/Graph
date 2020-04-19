#include "iostream"
#include "vector"
using namespace std;

struct Edge {
    int source,destination;
};

class Graph{
public:
    vector<vector<int>> adjList;
    Graph(vector<Edge> edges,int N){
        adjList.resize(N);
        for(auto i : edges){
            adjList[i.source].push_back(i.destination);
            adjList[i.destination].push_back(i.source);
        }
    }
};

void printGraph(Graph graph)
{
    for (int i = 0; i < graph.adjList.size(); i++)
    {
        cout << i << " -- ";
        for (int v : graph.adjList[i])
            cout <<"->"<< v << " ";
        cout << endl;
    }
}
int main()
{

    vector<Edge> edges =
            {
                    { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
                    { 3, 2 }, { 4, 5 }, { 5, 4 }
            };

    int N = 6;
    Graph graph(edges, N);
    printGraph(graph);

    return 0;
}