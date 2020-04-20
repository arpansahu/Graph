#include <queue>
#include "iostream"
#include "vector"
#include "queue"
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

void BFSRecursively(Graph  graph,vector<bool> &discovered,queue<int> & q){
    if (q.empty())
        return;
    int v = q.front();
    q.pop();
    cout << v << " ";

    for (int u : graph.adjList[v])
    {
        if (!discovered[u])
        {
            discovered[u] = true;
            q.push(u);
        }
    }

    BFSRecursively(graph, discovered,q);
}


int main()
{

    vector<Edge> edges =
            {
                    {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
                    {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
            };

    int N = 15;
    Graph graph(edges, N);
 //   printGraph(graph);
    vector<bool> discovered(N, false);
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        discovered[i] = true;
        q.push(i);
        BFSRecursively(graph,discovered,q);
    }

    return 0;
}