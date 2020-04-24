
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
    vector<int> indegree;
public:

    Graph(vector<Edge> edges,int V){
        this->V = V;
        adjList.resize(V);
        indegree.resize(V,0);
        for(auto i : edges){
            adjList[i.source].push_back(i.destination);
            indegree[i.destination]++;
        }
    }

    bool Khans_Topological_Sort_BFS(vector<int> & L);
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


bool Graph ::Khans_Topological_Sort_BFS(vector<int> &L) {
    
    vector<int> SetOfIndegreeWith0IncomingNodes;
    for(auto i  = 0; i < indegree.size() ; i++) if(!indegree[i]) SetOfIndegreeWith0IncomingNodes.push_back(i);
    
    while(!SetOfIndegreeWith0IncomingNodes.empty()){
        int n = SetOfIndegreeWith0IncomingNodes.back();  SetOfIndegreeWith0IncomingNodes.pop_back();
        L.push_back(n);
        for (auto i : adjList[n]) {
            indegree[i]--;
            if(!indegree[i]) SetOfIndegreeWith0IncomingNodes.push_back(i);
        }
    }
    return true ;
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
    vector<int> L;

    // Perform Topological Sort
    if (graph.Khans_Topological_Sort_BFS(L))      for (int i: L)  cout << i << " ";
    else cout << "Graph has at least one cycle. Topological sorting is not possible";
    return 0;
}