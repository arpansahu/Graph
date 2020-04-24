
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

    bool Total_number_of_paths_in_given_digraph_from_given_source_to_destination_having_exactly_m_edges_Using_DFS(int source, int destination, int m, int count,int &total,vector <int> temp);
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
    int vertex ,parent ;
};
bool Graph ::Total_number_of_paths_in_given_digraph_from_given_source_to_destination_having_exactly_m_edges_Using_DFS(int source, int destination, int m, int count,int &total,vector <int>  temp) {
    for (int u :adjList[source])
    {   vector<int> temp1 = temp; temp1.push_back(u);
        if(source != destination)Total_number_of_paths_in_given_digraph_from_given_source_to_destination_having_exactly_m_edges_Using_DFS(u, destination, m, count++,total,temp1);
        if(temp.size() == m + 1 && temp.back() == destination) total++;
    }
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
    int total = 0;
    graph.Total_number_of_paths_in_given_digraph_from_given_source_to_destination_having_exactly_m_edges_Using_DFS(0, 3, 4, 0,total,{0});
    cout <<"total no of paths are : " <<total;

    return 0;
}