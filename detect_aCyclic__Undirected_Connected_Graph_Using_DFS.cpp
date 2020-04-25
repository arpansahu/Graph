
#include "iostream"
#include "vector"
#include "queue"
#include "set"
#include "map"
using namespace std;

struct Edge {
    int source,destination;
};

class Graph{
    int V;
    vector<vector<int>> adjList;
public:

    Graph(vector<Edge> edges,int V){
        this->V = V;
        adjList.resize(V);
        for(auto i : edges){
            adjList[i.source].push_back(i.destination);
            adjList[i.destination].push_back(i.source);
        }
    }

    bool detect_aCyclic__Undirected_Connected_Graph_Using_DFS(int i, vector<bool> discovered, int parent);
    //in dfs we need to find out a back edge
    void printGraph();

};

void Graph :: printGraph()
{
    for (int i = 1; i < adjList.size(); i++)
    {
        cout << i << " -- ";
        for (int v : adjList[i])
            cout <<"->"<< v << " ";
        cout << endl;
    }
}

bool Graph ::detect_aCyclic__Undirected_Connected_Graph_Using_DFS(int i, vector<bool> discovered, int parent) {
    discovered[i] = true;
    for (int u :adjList[i])
    {
        if (!discovered[u])
        {
            discovered[u] = true;
            if(detect_aCyclic__Undirected_Connected_Graph_Using_DFS(u,discovered,i)) return true;
        }
        else if (u != parent) return true;

    }
    return false;
}

int main()

{

    vector<Edge> edges ={
            {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
            {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11},// {11, 12}

    };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V +1 );

    vector<bool> discovered(V + 1,false);
    if (graph.detect_aCyclic__Undirected_Connected_Graph_Using_DFS(1, discovered, -1))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain any cycle";
    return 0;
}