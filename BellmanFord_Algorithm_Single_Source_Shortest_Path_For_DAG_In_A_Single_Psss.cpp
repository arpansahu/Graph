#include <iostream>
#include <vector>
#include "set"
#include "unordered_map"
#include "algorithm"
#include "queue"
#include "climits"
using namespace std;

struct Edge{
    int source,destination,weight;
};
struct Node {
    int vertex, weight;
};


struct Compare{
    inline bool operator ()( Node a,  Node b){
        return (a.weight > b.weight);
    }
};


void print_route(vector<int> predecessor,int i){
    if (i < 0) return;
    print_route(predecessor, predecessor[i]);
    cout << i << " ";
}

class Graph{
    int V;
    vector<vector<Edge>> adjList;
public:

    Graph(vector<Edge> edges,int V){
        this->V = V;
        adjList.resize(V);
        for(auto i : edges){
            adjList[i.source].push_back(i);
            //     adjList[i.destination].push_back(i.source);
        }
    }
    void   BellmanFord_Algorithm_Single_Source_Shortest_Path_For_DAG_In_A_Single_Psss(int starting_vertex);
    void DFS(vector<int> &departure,vector<bool> &discovered,int start,int & time1);
};
void Graph :: DFS(vector<int> &departure,vector<bool> &discovered,int start,int & time1){
    discovered[start] = true;
    for(auto i: adjList[start]) if(!discovered[i.destination]) DFS(departure,discovered,i.destination,time1);
    departure[time1] = start;   //topological sorting
    time1++;
}
void  Graph :: BellmanFord_Algorithm_Single_Source_Shortest_Path_For_DAG_In_A_Single_Psss(int starting_vertex){
    vector<int> departure(V,-1);
    vector<bool> discovered(V,false);
    int time1 = 0;
    for(int i = 0; i < V; i++) if(!discovered[i]) DFS(departure,discovered,i,time1);

    vector<int> cost(V, INT_MAX);
    cost[starting_vertex] = 0;

    for (int i = V - 1; i >= 0; i--)
    {
        int v = departure[i];
        for (Edge e : adjList[v])
        {
            int u = e.destination;
            int w = e.weight;
            if (cost[v] != INT_MAX && cost[v] + w < cost[u])cost[u] = cost[v] + w;
        }
    }

    for (int i = 0; i < V - 1; i++) {
        cout << "dist(" << starting_vertex << ", " << i << ") = "  << cost[i];
        cout << endl;
    }
}


int main(){
    vector<Edge> edges =
            {
                    {0, 6, 2}, {1, 2, -4}, {1, 4, 1}, {1, 6, 8}, {3, 0, 3}, {3, 4, 5},
                    {5, 1, 2}, {7, 0, 6}, {7, 1, -1}, {7, 3, 4}, {7, 5, -4}
            };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    int source = 7;
    Graph graph(edges,V);
    graph.BellmanFord_Algorithm_Single_Source_Shortest_Path_For_DAG_In_A_Single_Psss(source);

}