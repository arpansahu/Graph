
#include "iostream"
#include "vector"
#include "set"

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
    void DFSRecurisvelyUtil(vector<bool> &discovered, int s, vector<int> &departure, int &time);
    void isDAG();
    void printGraph();


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


void Graph ::DFSRecurisvelyUtil(vector<bool> &discovered,int s,vector<int> & departure ,int & time1) {
    discovered[s] = true;
    for(auto i : adjList[s])  if(discovered[i] == false) DFSRecurisvelyUtil(discovered, i,  departure, time1);
    departure[s] = ++time1;
}

void Graph ::isDAG() {
    vector<bool> discovered(V, false);
    vector<int > departure(V,NULL);
    int time = -1;
    for (int i = 0; i < V; i++) if (discovered[i] == false)    DFSRecurisvelyUtil(discovered, i, departure,time);
    int cond = 0;
    for(int u = 0; u < V ; u++) for(auto v : adjList[u]) if(departure[u] < departure[v]) cond = 1;
    if(cond == 0) cout <<"This is a DAG";
    else cout <<"This is not a DAG since it contained a back edge ";
}

int main()

{

    vector<Edge> edges ={
            {0, 1}, {0, 3}, {1, 2}, {1, 3}, {3, 2}, {3, 4},
             {5, 6}, {6, 3}   //add {3,0}
    };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V);
    graph.isDAG();
    return 0;
}
