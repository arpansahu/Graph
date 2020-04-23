
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
            //     adjList[i.destination].push_back(i.source);
        }
    }
    void DFSRecurisvelyUtil(vector<bool> &discovered, int s, vector<int> &departure, int &time, map<int, int ,greater<int>> & map1);
    void TopologicalSrotUsing_Arrival_and_Departure_Time_of_Vertices_in_DFS(int s);
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


void Graph ::DFSRecurisvelyUtil(vector<bool> &discovered,int s,vector<int> & departure ,int & time1, map<int, int ,greater<int>> &map1) {
    discovered[s] = true;
    ++time1;
    for(auto i : adjList[s])  if(discovered[i] == false) DFSRecurisvelyUtil(discovered, i,  departure, time1,map1);
    departure[s] = ++time1;
    map1[departure[s]] = s;
}

void Graph ::TopologicalSrotUsing_Arrival_and_Departure_Time_of_Vertices_in_DFS(int s) {
    vector<bool> discovered(V, false);
    map<int, int ,greater<int>> map1;
    vector<int > departure(V,-1);
    int time = -1;
    for (int i = s; i < V; i++) if (discovered[i] == false)    DFSRecurisvelyUtil(discovered, i, departure,time,map1);
    for(auto i : map1) cout <<i.second<<" ";
}

int main()

{

    vector<Edge> edges ={  		{0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4},
                                 {5, 1}, {7, 0}, {7, 1}
    };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V);
    graph.TopologicalSrotUsing_Arrival_and_Departure_Time_of_Vertices_in_DFS(0);
    return 0;
}