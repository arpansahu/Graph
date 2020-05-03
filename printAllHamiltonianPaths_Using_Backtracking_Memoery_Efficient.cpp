
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

    void printGraph();
    void printAllHamiltonianPaths(int start ,vector<int> &path,vector<bool> &visited );
};

void Graph :: printGraph()
{
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << i << " -- ";
        for (int v : adjList[i])
            cout <<"->"<< v << " ";
        cout << endl;
    }
}

void Graph :: printAllHamiltonianPaths(int start ,vector<int> & path,vector<bool> &visited) {
    if(path.size() == V){
        for(auto i : path) cout <<i <<" ";
        cout <<endl; return;
    }
    for(auto i : adjList[start]){
        if(!visited[i]){
            visited[i] = true;
            path.push_back(i);
            printAllHamiltonianPaths(i,path,visited);

            //backtracking
            visited[i] = false;
            path.pop_back();
        }
    }
}
int main()

{    vector<Edge> edges = {
            {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}
    };

    int start = 0;
    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V);

    //  graph.printGraph();
    vector<bool> visited(V,false);
    visited[start] = true;

    vector<int>path;
    path.push_back(start);
    graph.printAllHamiltonianPaths(start,path,visited);

    return 0;
}
