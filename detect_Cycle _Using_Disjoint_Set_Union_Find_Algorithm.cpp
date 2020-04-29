#include <iostream>
#include <vector>
#include "set"
#include "unordered_map"
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

    void DFS(int s,vector<bool> &discovered);
    bool findCycle();
    void printGraph();
};

class DisjointSet{
    unordered_map  <int ,int> parent;
public:

    void  makeSet(int V){
        for(int i = 1;i<= V;i++) parent[i] = i;
    }

    int Find(int k ){
        if(parent[k] == k) return k ;
        return Find(parent[k]);
    }

    void Union(int a, int b){
        parent[Find(a)] = Find(b);
    }

    void printSets(vector <int> universe){
        for(auto i:universe) cout <<Find(i) <<" "; cout <<"\n";
    }
};

void Graph ::printGraph() {
    for (int i = 1; i < V; i++)
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
bool Graph :: findCycle(){

    DisjointSet ds;
    ds.makeSet(V);
    for(int i =1;i<= V;i++){
        for(auto j : adjList[i]){
            if(ds.Find(i) == ds.Find(j)) return true;
            else ds.Union(i,j);
        }
    }
    return false;
}
int main(){
    vector<Edge> edges =
            {                  {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
                               {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}, {11, 12}
            };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V + 1);
    //   graph.printGraph();
    if(graph.findCycle())   cout<<"Cycle Exists";
    else cout<<"Cycle does not exists";

}