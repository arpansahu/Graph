#include <queue>
#include "iostream"
#include "vector"
#include "queue"

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
            //     adjList[i.destination].push_back(i.source);
        }
    }
    void BFSRecursivelyJoinandDisjointtGraphUtil(vector<bool> &discovered, queue<int> &q);
    void BFSRecursivelyJointandDisjointGraph(int s);
    void printGraph();


};

void Graph :: printGraph()
{
    for (int i = 0; i < this->adjList.size(); i++)
    {
        cout << i << " -- ";
        for (int v : this->adjList[i])
            cout <<"->"<< v << " ";
        cout << endl;
    }
}


void Graph ::BFSRecursivelyJoinandDisjointtGraphUtil(vector<bool> &discovered, queue<int> &q) {
    if (q.empty())
        return;
    int v = q.front();
    q.pop();
    cout << v <<" ";
    for (int u : this->adjList[v])
    {
        if (!discovered[u])
        {
            discovered[u] = true;
            q.push(u);
        }
    }
    BFSRecursivelyJoinandDisjointtGraphUtil(discovered, q);

}

void Graph ::BFSRecursivelyJointandDisjointGraph(int s) {
    vector<bool> discovered(V, false);
    queue<int> q;

    for (int i = s; i < V; i++) {
        if (discovered[i] == false)
        {
            discovered[i] = true;
            q.push(i);
            BFSRecursivelyJoinandDisjointtGraphUtil(discovered, q);
        }
    }
}

int main()
{

    vector<Edge> edges =
            {
                    {0, 1}, {0, 2}, {1, 2}, {2, 0}, {2,3},{3,3}
            };

    int V = 4;
    Graph graph(edges, V);
    //   graph.printGraph();
    graph.BFSRecursivelyJointandDisjointGraph(2);
    cout << "\n";




    edges = {
            {0,4},{1,2},{1,3},{1,4},{2,3},{3,4}
    };

    Graph graph2(edges,5);

    graph2.BFSRecursivelyJointandDisjointGraph(0);
    return 0;
}