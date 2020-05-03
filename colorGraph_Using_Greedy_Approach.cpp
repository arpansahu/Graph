
#include "iostream"
#include "vector"
#include "queue"
#include "set"
#include "map"
#include "unordered_map"
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
            adjList[i.destination].push_back(i.source);
        }
    }

    void printGraph();
    void colorGraph();
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
string color[] =
        {
                "", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE", "PINK",
                "BLACK", "BROWN", "WHITE", "PURPLE", "VOILET"
        };

void Graph ::colorGraph() {
    unordered_map<int,int> result;

    for (int u = 0; u < V; u++)
    {
        set<int> assigned;

        for (int i : adjList[u])    if (result[i])  assigned.insert(result[i]);

        int color = 1;
        for (auto &c: assigned ) {
            if (color != c) break;
            color++;
        }
        result[u] = color;
    }

    for (int v = 0; v < V; v++) cout << "Color assigned to vertex " << v << " is "<< color[result[v]] << '\n';

}
int main(){

vector<Edge> edges = {
        {0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}
};

    int start = 0;
    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V);

    //  graph.printGraph();

    graph.colorGraph();

    return 0;
}
