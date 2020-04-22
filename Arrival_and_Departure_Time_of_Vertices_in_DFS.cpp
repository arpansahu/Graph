
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
    void DFSRecurisvelyUtil(vector<bool> &discovered, int s, vector<int> &arriavl, vector<int> &departure, int &time);
    void Arrival_and_Departure_Time_of_Vertices_in_DFS(int s);
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


void Graph ::DFSRecurisvelyUtil(vector<bool> &discovered,int s,vector<int> &arrival,vector<int> & departure ,int & time1) {
    discovered[s] = true;
    arrival[s] = ++time1;
    for(auto i : adjList[s])  if(discovered[i] == false) DFSRecurisvelyUtil(discovered, i, arrival, departure, time1);
    departure[s] = ++time1;
}

void Graph ::Arrival_and_Departure_Time_of_Vertices_in_DFS(int s) {
    vector<bool> discovered(V, false);
    vector <int > arrival(V);
    vector<int > departure(V);
    int time = -1;
    for (int i = s; i < V; i++) if (discovered[i] == false)    DFSRecurisvelyUtil(discovered, i, arrival, departure,time);
    //if we remove if then it will not work for disjoint graph

    for (int j = 0; j < V; ++j) {
        cout << "Vertex " << j << " (" << arrival[j]<< ", " << departure[j] << ")" << endl;
    }
}

int main()

{

    vector<Edge> edges ={   {0, 1}, {0, 2}, {2, 3}, {2, 4}, {3, 1}, {3, 5},
                            {4, 5}, {6, 7}
    };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V);
    graph.Arrival_and_Departure_Time_of_Vertices_in_DFS(0);
    return 0;
}