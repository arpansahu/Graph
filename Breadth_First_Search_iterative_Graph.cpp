#include <queue>
#include "iostream"
#include "vector"
#include "queue"
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
    void  BFSIterativelyJointGraph(int s);
    void  BFSIterativelydisJointGraph();
    void printGraph();
    void BFSutility(vector <bool> &discovered ,int  i);
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

void Graph :: BFSIterativelyJointGraph(int s){
    vector<bool> discovered(V, false);
    for(int i = 0; i < V; i++)
        discovered[i] = false;

    queue <int> q;
    discovered[s] = true;
    q.push(s);

    while(!q.empty())
    {
        s = q.front();  cout << s << " ";   q.pop();
        for (auto  j : this->adjList[s]) {
            if(!discovered[j]){
                discovered[j] = true;
                q.push(j);
            }
        }
    }
}

void Graph :: BFSutility(vector <bool> &discovered ,int  s){
    queue <int> q;
    q.push(s);
    discovered[s] = true;
    while(!q.empty())
    {
        s = q.front();  cout << s << " ";   q.pop();

        for (auto  j : this->adjList[s]) {
            if(!discovered[j]){
                discovered[j] = true;
                q.push(j);
            }
        }
    }
}

void Graph :: BFSIterativelydisJointGraph(){
    vector <bool> discovered(V, false);
    for(int i = 0; i <  V ; i++)   if(discovered[i] == false) BFSutility(discovered,i);
}

int main()
{

    vector<Edge> edges =
            {
                    {0, 1}, {0, 2}, {1, 2}, {2, 0}, {2,3},{3,3}
            };

    int V = 4;
    Graph graph(edges, V);
    //  graph.printGraph();
    graph.BFSIterativelyJointGraph(2);
    cout << "\n";
    edges = {
            {0,4},{1,2},{1,3},{1,4},{2,3},{3,4}
    };

    Graph graph2(edges,5);

    graph2.BFSIterativelydisJointGraph();
    return 0;
}