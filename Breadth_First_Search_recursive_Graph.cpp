#include <queue>
#include "iostream"
#include "vector"
#include "set"
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
            //  adjList[i.destination].push_back(i.source);
        }
    }
    void printGraph();
    void BFSRecursivelyUtility(vector<bool> &discovered,queue<int> & q);
    void BSFRecursive(int s);
};

void Graph :: printGraph()
{
    for (int i = 0; i <V; i++)
    {
        cout << i << " -- ";
        for (int v : adjList[i])
            cout <<"->"<< v << " ";
        cout << endl;
    }cout <<"\n";
}

void Graph :: BFSRecursivelyUtility(vector<bool> &discovered,queue<int> & q){
    if (q.empty())
        return;
    int v = q.front();
    q.pop();
    cout << v << " ";

    for (int u : adjList[v])
    {
        if (!discovered[u])
        {
            discovered[u] = true;
            q.push(u);
        }
    }

    BFSRecursivelyUtility( discovered,q);
}

void Graph :: BSFRecursive(int s){
    vector<bool> discovered(V, false);
    queue<int> q;
    for (int i = s; i < V; ++i) {
        if(discovered[i] == false){
            discovered[i] = true;
            q.push(i);
            BFSRecursivelyUtility(discovered,q);
        }
    }
}

int main()
{

    vector<Edge> edges =
            {
                    {0, 1}, {0, 2}, {1, 2}, {2, 0}, {2,3},{3,3}
            };


    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V);
    // graph.printGraph();
    graph.BSFRecursive(2);
    cout << "\n";


    edges = {
            {0,4},{1,2},{1,3},{1,4},{2,3},{3,4}
    }; // this is aa disjoint graph
    set <int > setsize1;
    for(auto  i : edges){ setsize1.insert(i.source);setsize1.insert(i.destination);}
    int V1 = setsize1.size();
    Graph graph2(edges,V1);

    graph2.BSFRecursive(0);
    return 0;

}