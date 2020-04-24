
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
        }
    }

    void transitive_Closure_Using_BFS();
    void printGraph();
    void BFS(vector<vector<int>> &T,int vertex );

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

void Graph :: BFS(vector<vector<int>> &T,int vertex ){
    vector<int>discovered(V,0);
    queue <int> q;
    q.push(vertex);
    discovered[vertex] = true;
    while(!q.empty())
    {
        int s = q.front();   q.pop();
        for (auto  j : adjList[s]) {
            if(!discovered[j]){
                discovered[j] = true;
                q.push(j);
            }
        }
    }
    T[vertex] = discovered;

}
void Graph ::transitive_Closure_Using_BFS() {
    vector<int> temp ;
    vector<vector<int>> T(V,temp);
    for (int i = 0; i < V ; i++)  BFS(T,i);
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
    graph.transitive_Closure_Using_BFS();
    return 0;
}