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
    void Dijkstras_Algorithm_Single_Source_Shortest_Path(int starting_vertex);

};
void print_route(vector<int> predecessor,int i){
    if (i < 0) return;
    print_route(predecessor, predecessor[i]);
    cout << i << " ";
}

void Graph :: Dijkstras_Algorithm_Single_Source_Shortest_Path(int starting_vertex){
    priority_queue<Node, vector<Node>, Compare> min_heap;
    min_heap.push({starting_vertex,0});

    vector<int> dist(V,INT_MAX);
    dist[starting_vertex] = 0;

    vector<bool>discovered(V, false);

    //for printing  path
    vector<int> predecessor(V,-1);

    while(!min_heap.empty()){
        Node node = min_heap.top(); min_heap.pop();

        for(auto i : adjList[node.vertex]){

            if (!discovered[i.destination] && (dist[node.vertex] + i.weight) < dist[i.destination])
            {
                dist[i.destination] = dist[node.vertex] + i.weight;
                predecessor[i.destination] = node.vertex;
                min_heap.push({i.destination, dist[i.destination]});
            }
        }
        discovered[node.vertex] = true;
    }
    //   for(auto i : predecessor) cout <<i <<" ";cout <<"\n";
    //   for(auto i : dist) cout <<i <<" ";cout <<"\n";
    for(int i = 0;i < V; i++){
        if(i != starting_vertex &&  i != INT_MAX){
            cout << "Path (" << starting_vertex << " -> " << i << "): Minimum Cost = "<< dist[i] << " and Route is [ ";
            print_route(predecessor, i);
            cout << "]" << endl;
        }
    }
}


int main(){
    vector<Edge> edges =
            {
                    {0, 1, 10}, {0, 4, 3}, {1, 2, 2}, {1, 4, 4}, {2, 3, 9},
                    {3, 2, 7}, {4, 1, 1}, {4, 2, 8}, {4, 3, 2}
            };


    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();

    Graph graph(edges,V);
    graph.Dijkstras_Algorithm_Single_Source_Shortest_Path(0);

}