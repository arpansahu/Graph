
#include "iostream"
#include "vector"


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
    void DFSRecurisvelyUtil(vector<bool> &discovered,int s);
    void DFSRecurisvely(int s);
    void printGraph();


};

void Graph :: printGraph()
{
    for (int i = 0; i < this->adjList.size(); i++)
    {
        cout << i << " -- ";
        for (int v : this->adjList[i])
            cout <<"->"<< v << " ";
        cout << endl;
    }
}


void Graph ::DFSRecurisvelyUtil(vector<bool> &discovered,int s) {
    discovered[s] = true;
    cout << s <<" ";
    for(auto i : this->adjList[s]){
        if(discovered[i] == false) DFSRecurisvelyUtil(discovered,i);
    }
}

void Graph ::DFSRecurisvely(int s) {
    vector<bool> discovered(V, false);
    for (int i = s; i < V; i++) {if (discovered[i] == false) DFSRecurisvelyUtil(discovered,i);} //if we remove if then it will not work for disjoint graph
}

int main()

{

    vector<Edge> edges =
            {
                    {0, 1}, {0, 2}, {1, 2}, {2, 0}, {2,3},{3,3}
            };

    int V = 4;
    Graph graph(edges, V);
    //   graph.printGraph();
    graph.DFSRecurisvely(2);
    cout << "\n";




    edges = {
            {0,4},{1,2},{1,3},{1,4},{2,3},{3,4}
    }; // this is aa disjoint graph

    Graph graph2(edges,5);

    graph2.DFSRecurisvely(0);
    return 0;
}