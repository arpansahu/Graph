#include <queue>
#include "iostream"
#include "vector"
#include "set"
using namespace std;

struct Edge {
    int source,destination,weight;
};

class Graph{
    int V;
    vector<vector<int>> adjList;
public:

    Graph(vector<Edge> edges,int V,int x){
        this->V = V;
        adjList.resize(V * 3);
        for(auto i : edges){
            if(i.weight == 3*x){
                adjList[i.source].push_back(i.source + V);
                adjList[i.source + V].push_back(i.source + 2 * V);
                adjList[i.source + 2 * V].push_back(i.destination);
            }
            else if (i.weight == 2 * V){
                adjList[i.source].push_back(i.source + V);
                adjList[i.source +  V].push_back(i.destination);
            }
            else adjList[i.source].push_back(i.destination);

        }
    }

    void BFS(int source  ,int  destination);
    void printPath(vector<int> predecessor,int dest, int &cost);
};

void Graph :: printPath(vector<int> predecessor,int dest, int &cost){
    if(dest < 0) return;
    printPath(predecessor,predecessor[dest],cost);
    cost++;
    if(dest < V) cout <<dest <<" ";
}

void Graph :: BFS(int source  ,int destination){

    vector<bool> discovered(3*V, false);
    discovered[source] = true;

    vector<int> predecessor(3*V, -1);

    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int curr = q.front();       q.pop();

        if (curr == destination)
        {	//for(auto i : predecessor) cout <<i <<" ";cout <<"\n";
            int cost = -1;
            cout << "Least cost path between " << source << " and " <<destination << " is ";
            printPath(predecessor, destination, cost );
            cout << "having cost " << cost;
        }

        for (int v : adjList[curr])
        {
            if (!discovered[v])
            {
                discovered[v] = true;
                q.push(v);
                predecessor[v] = curr;
            }
        }
    }
}



int main()
{
    int x =1;
    vector<Edge> edges =
            {
                    {0, 1, 3*x}, {0, 4, 1*x}, {1, 2, 1*x}, {1, 3, 3*x},
                    {1, 4, 1*x}, {4, 2, 2*x}, {4, 3, 1*x}
            };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V, x);
    //graph.printGraph();
    graph.BFS(0,2);
    cout << "\n";



    return 0;
}