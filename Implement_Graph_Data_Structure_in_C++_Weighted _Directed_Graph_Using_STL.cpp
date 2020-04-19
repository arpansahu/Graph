#include "iostream"
#include "vector"
using namespace std;

struct Edge {
    int source,destination,weight;
};

class Graph{
public:
    vector<vector<pair<int,int>>> adjList;
    Graph(vector<Edge> edges,int N){
        adjList.resize(N);
        for(auto i : edges){
            pair<int,int> pair1(i.destination,i.weight);
            adjList[i.source].push_back(pair1);
        }
    }
};

void printGraph(Graph graph)
{
    for (int i = 0; i < graph.adjList.size(); i++)
    {
        cout << i << " -- ";
        for (auto v : graph.adjList[i])
            cout <<"->"<< v.first <<" ("<<v.second<<") " << " ";
        cout << endl;
    }
}
int main()
{

    vector<Edge> edges =
            {{ 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
             { 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }
            };

    int N = 6;
    Graph graph(edges, N);
    printGraph(graph);

    return 0;
}