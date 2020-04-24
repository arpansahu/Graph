
#include "iostream"
#include "vector"
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
        }
    }

    void transitive_Closure_Using_DFS();
    void printGraph();
    void DFS(vector<vector<int>> &T,int vertex );

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

void Graph :: DFS(vector<vector<int>> &T,int vertex ){
    T[vertex][vertex] = 1;
    for(auto i : adjList[vertex]){
        if(!T[vertex][i]) {T[vertex][i]= 1; DFS(T,i);}
    }
}
void Graph ::transitive_Closure_Using_DFS() {
    vector<int> temp (V,0);
    vector<vector<int>> T(V,temp);
    for (int i = 0; i < V ; i++)  DFS(T,i);
    for (auto  i: T) { for(auto j : i ) cout << j << " ";cout <<"\n";}
}

int main()

{

    vector<Edge> edges ={  		{ 0, 2 }, { 1, 0 }, { 3, 1 }
    };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V);
    graph.transitive_Closure_Using_DFS();
    return 0;
}
#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

struct Edge {
    int source,destination;
};

class Graph{
    int V;
    vector<vector<int>> adjList;
    vector<int> indegree;
public:

    Graph(vector<Edge> edges,int V){
        this->V = V;
        adjList.resize(V);
        indegree.resize(V,0);
        for(auto i : edges){
            adjList[i.source].push_back(i.destination);
            indegree[i.destination]++;
        }
    }

    void transitive_Closure_Using_DFS();
    void printGraph();
    void DFS(vector<vector<int>> &T,int vertex );

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

void Graph :: DFS(vector<vector<int>> &T,int vertex ){
    T[vertex][vertex] = 1;
    for(auto i : adjList[vertex]){
        if(!T[vertex][i]) {T[vertex][i]= 1; DFS(T,i);}
    }
}
void Graph ::transitive_Closure_Using_DFS() {
    vector<int> temp (V,0);
    vector<vector<int>> T(V,temp);
    for (int i = 0; i < V ; i++)  DFS(T,i);
    for (auto  i: T) { for(auto j : i ) cout << j << " ";cout <<"\n";}
}

int main()

{

    vector<Edge> edges ={  		{ 0, 2 }, { 1, 0 }, { 3, 1 }
    };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V);
    graph.transitive_Closure_Using_DFS();
    return 0;
}