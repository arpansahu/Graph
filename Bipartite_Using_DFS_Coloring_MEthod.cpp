#include "set"
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
    void DFSRecurisvelyUtil(vector<bool> &discovered, int s, vector<char> &color, char colorParent, bool &cond);
    void Bipartite();
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


void Graph ::DFSRecurisvelyUtil(vector<bool> &discovered, int s, vector<char> &color, char colorParent, bool &cond) {

    discovered[s] = true;
    if(color[s] == 'N') color[s] = (colorParent == 'B') ? 'R' : 'B';
    for(auto i : adjList[s]){
        if(discovered[i] == false) DFSRecurisvelyUtil(discovered, i, color, color[s], cond);
        else if(color[i] == color[s] ) {  cond = false; return ;}
    }
}

void Graph ::Bipartite() {
    vector<bool> discovered(V, false);
    vector<char> color(V,'N');
    bool cond = true;
    for (int i = 0; i < V; i++) {if (discovered[i] == false && cond == true) DFSRecurisvelyUtil(discovered, i, color, 'B', cond);} //if we remove if then it will not work for disjoint graph
    (cond == true) ? cout << "Bipartite Graph  " :cout <<"Not a Bipartite Graph  \n";
}

int main()

{

    vector<Edge> edges =
            {
                    {0, 1}, {0, 5}, {1, 2}, {2, 3}, {3, 4}, {5, 4},

            };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V);
    //  graph.printGraph();
    graph.Bipartite();

    vector<Edge> edges1 =
            {
                    {2,1},{0,3},{1,0},{4,2},{5,1},{2,0}
            };

    set <int > setsize1;
    for(auto  i : edges1){ setsize1.insert(i.source);setsize1.insert(i.destination);}
    int V1 = setsize1.size();
    Graph graph1(edges1, V1);
    //  graph.printGraph();
    graph1.Bipartite();
    return 0;
}