#include <iostream>
#include <vector>
#include "set"
using namespace std;

struct Edge{
    int source,destination;
};
class Graph{
    vector<vector<int>> adjList;
    int V;
public:
    Graph(vector<Edge> edges,int V){
        this->V = V;
        adjList.resize(V);
        for(auto i: edges){
            adjList[i.source].push_back(i.destination);
            //adjList[i.destination].push_back(i.source);
        }
    }
    void checkStronglyConnectedGraphEfficient();
    void DFS(int s,vector<bool> &discovered);
    void printGraph();
};
void Graph ::printGraph() {
    for (int i = 0; i < V; i++)
    {
        cout << i << " -- ";
        for (int v : adjList[i])
            cout <<"->"<< v << " ";
        cout << endl;
    }

}
void Graph ::DFS(int s, vector<bool> &discovered) {
    discovered[s] = true;
    for(auto i : adjList[s]){
        if(!discovered[i]) DFS(i,discovered);
    }
}
void Graph ::checkStronglyConnectedGraphEfficient() {

    vector<bool> discovered(V,false);
    int randVertex = 0;
    DFS(randVertex,discovered);
    for(auto i : discovered) if(i == false) {cout <<"No Graph is not a Strongly Connected Graph"; return ;}

    //reversing all the edges
    vector<Edge> edges;
    for(int i = 0;i < V ;i++)   for(auto j:adjList[i])  edges.push_back({j,i});
    Graph graph2(edges,V);

    fill(discovered.begin(),discovered.end(),false);
    DFS(randVertex,discovered);
    for(auto i : discovered) if(i == false) {cout <<"No Graph is not a Strongly Connected Graph"; return ;}

    cout <<"Yes Graph is  Strongly Connected Graph";
}
int main(){
    vector<Edge> edges =
            {           {0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4},
                        {3, 1}, {3, 2}, {4, 3}
            };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V);
    //   graph.printGraph();
    graph.checkStronglyConnectedGraphEfficient();

}