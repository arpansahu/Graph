
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
            adjList[i.destination].push_back(i.source);
        }
    }

    void detect_Cycle_In_Undirected_Graph_Using_BFS();
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
void Graph ::detect_Cycle_In_Undirected_Graph_Using_BFS() {
    vector<bool> discovered(V);
    int src = 1;
    discovered[src] = true;
    queue<Node> q;
    q.push({src, -1});
    while (!q.empty())
    {
        Node node = q.front();
        q.pop();
        for (int u :adjList[node.vertex])
        {
            if (!discovered[u])
            {
                discovered[u] = true;
                q.push({ u, node.vertex });
            }
            else if (u != node.parent)  {cout << "Cycle found "; return;}

        }
    }
    cout <<"Cycle not found ";

}

int main()

{

    vector<Edge> edges ={  			{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
                                     {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}, {6, 10}
    };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V +1 );
    graph.detect_Cycle_In_Undirected_Graph_Using_BFS();
    return 0;
}