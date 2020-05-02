#include "iostream"
#include "vector"
#include "iomanip"
#include "set"
using namespace std;

struct Edge {
    int source,destination;
};

class Graph{
    vector<vector<int>> adjList;
    int V;
public:
    Graph(vector<Edge> edges,int V){
        adjList.resize(V); this->V = V;
        for(auto i : edges){
            adjList[i.source].push_back(i.destination);
            adjList[i.destination].push_back(i.source);
        }
    }
    bool isSafe(vector<int> color,int vertex,int color_C);
    void kColorable(vector<int> & color,int k,int v);
};

string COLORS[] =  {"", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE",
                    "PINK", "BLACK", "BROWN", "WHITE", "PURPLE"};
//10-colorable graph
bool Graph ::isSafe(vector<int> color, int vertex, int color_C) {
    for(auto i : adjList[vertex])   if(color[i] == color_C) return false;
    return true;
}

void Graph :: kColorable(vector<int> & color,int k,int v){
    if(v == V){
        for(int v = 0;v < V; v++)cout << setw(8) << left << COLORS[color[v]];
        cout << endl;
        return;
    }

    for (int i = 1; i <= k; ++i) {
        if(isSafe(color,v,i)){
            color[v] = i;
            kColorable(color,k,v+1);
            color[v] = 0;
        }
    }
}

int main()
{

    vector<Edge> edges = {
            {0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}
    };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();

    Graph graph(edges,V );

    int k = 3;

    vector<int> color(V, 0);

    // print all k-colorable configurations of the graph
    graph.kColorable(color, k, 0);

    return 0;
}