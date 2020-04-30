#include <iostream>
#include <vector>
#include "set"
#include "unordered_map"
#include "algorithm"
using namespace std;

struct Edge{
    int source,destination,weight;
};

struct Compare{
    inline bool operator ()( Edge a, Edge b){
        return (a.weight > b.weight);
    }
};



class DisjointSet{
    unordered_map  <int ,int> parent;
public:

    void  makeSet(int V){
        for(int i = 0;i < V;i++) parent[i] = i;
    }

    int Find(int k ){
        if(parent[k] == k) return k ;
        return Find(parent[k]);
    }

    void Union(int a, int b){
        parent[Find(a)] = Find(b);
    }

};


vector<Edge>  Kruskals_Minimum_Spanning_Tree(int V,vector<Edge> edges){
    vector<Edge> MST;
    DisjointSet ds;
    ds.makeSet(V);
    while (MST.size() != V - 1){
        Edge next_edge = edges.back();
        edges.pop_back();
        if(ds.Find(next_edge.source) != ds.Find(next_edge.destination)){
            ds.Union(next_edge.source,next_edge.destination);
            MST.push_back(next_edge);
        }
    }
    return MST;
}
int main(){
    vector<Edge> edges =
            {
                    // (u, v, w) tiplet represent undirected edge from
                    // vertex u to vertex v having weight w
                    { 0, 1, 7 }, { 1, 2, 8 }, { 0, 3, 5 }, { 1, 3, 9 },
                    { 1, 4, 7 }, { 2, 4, 5 }, { 3, 4, 15 }, { 3, 5, 6 },
                    { 4, 5, 8 }, { 4, 6, 9 }, { 5, 6, 11 }
            };
    sort(edges.begin(),edges.end(),Compare());
    //for(auto i : edges) cout<<i.source <<"->"<<i.destination<<" "<<i.weight<<"\n";
    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    vector<Edge>MST = Kruskals_Minimum_Spanning_Tree( V,edges);
    for(auto i : MST) cout << "(" << i.source << ", " << i.destination << ", "<< i.weight << ")" << endl;

}