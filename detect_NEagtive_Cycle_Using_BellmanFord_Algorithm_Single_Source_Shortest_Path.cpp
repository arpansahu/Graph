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

void  detect_NEagtive_Cycle_Using_BellmanFord_Algorithm_Single(int starting_vertex,vector<Edge> edges,int V){
    int noOfEdges = edges.size();
    vector<int>distance(V,INT_MAX);
    vector<int> predecessor(V,-1);
    distance[starting_vertex] = 0;
    int k = V;
    while(--k){
        for (int i = 0; i < noOfEdges; ++i) {
            if(distance[edges[i].source] != INT_MAX && distance[edges[i].source] + edges[i].weight < distance[edges[i].destination]){
                distance[edges[i].destination] = distance[edges[i].source] + edges[i].weight;
                predecessor[edges[i].destination] = edges[i].source;
            }
        }
    }
    //run relaxation for checking of  a negative weight cycle  Since this lago does not work for negative weight cycle
    for (int i = 0; i < V ; ++i) {
        if(distance[edges[i].source] != INT_MAX && distance[edges[i].source] + edges[i].weight < distance[edges[i].destination]){
            cout <<"Negative Weight Cycle Found!";
            return;
        }
    }
    //   for(auto i : predecessor) cout <<i <<" ";cout<<"\n";
    //   for(auto i : distance) cout <<i <<" ";cout<<"\n";
    cout<<"No negative Weight Cycle Found";
}


int main(){
    vector<Edge> edges =
            {
                    // (x, y, w) -> edge from x to y having weight w
                    { 0, 1, -1 }, { 0, 2, 4 }, { 1, 2, 3 }, { 1, 3, 2 },
                    { 1, 4, 2 }, { 3, 2, 5 }, { 3, 1, 1 }, { 4, 3, -3 }
            };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    int source = 0;
    detect_NEagtive_Cycle_Using_BellmanFord_Algorithm_Single(source,edges,V);

}