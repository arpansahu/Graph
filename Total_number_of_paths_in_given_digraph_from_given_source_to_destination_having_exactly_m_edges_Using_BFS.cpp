
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

    bool Total_number_of_paths_in_given_digraph_from_given_source_to_destination_having_exactly_m_edges_Using_BFS(int source, int destination, int m);
    //in bfs we need to find out a cross edge
    void printGraph();

};

void Graph :: printGraph()
{
    for (int i = 1; i < adjList.size(); i++)
    {
        cout << i << " -- ";
        for (int v : adjList[i])
            cout <<"->"<< v << " ";
        cout << endl;
    }
}
struct Node {
    int vertex ,depth ;
};
bool Graph ::Total_number_of_paths_in_given_digraph_from_given_source_to_destination_having_exactly_m_edges_Using_BFS(int source, int destination, int m) {
    queue<Node> q;
    q.push({source,0});
    int count = 0;
    while(!q.empty()){
        auto  v = q.front(); q.pop();
        if(v.depth == m && v.vertex == destination) count++;
        for(auto i : adjList[v.vertex]) q.push({i,v.depth + 1});
    }
    cout << count;

}

int main()

{

    vector<Edge> edges ={  			      {0, 6}, {0, 1}, {1, 6}, {1, 5}, {1, 2}, {2, 3}, {3, 4},
                                           {5, 2}, {5, 3}, {5, 4}, {6, 5}, {7, 6}, {7, 1}
    };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V  );

    graph.Total_number_of_paths_in_given_digraph_from_given_source_to_destination_having_exactly_m_edges_Using_BFS(0, 3, 4);

    return 0;
}