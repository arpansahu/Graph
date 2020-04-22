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
            adjList[i.destination].push_back(i.source);
        }
    }
    void  Bipartite();
    void printGraph();
    void Bipartiteutility(vector <char> &discovered ,int  i);
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
    cout <<"\n";
}


void Graph :: Bipartiteutility(vector <char> &colored ,int  s){
    queue <int> q;
    q.push(s);
    colored[s] = 'R';
    while(!q.empty())
    {
        s = q.front();    q.pop();  //cout << s<<" " ;
        for (auto  j : this->adjList[s]) {
            if(colored[j] == NULL){
                colored[j] = (colored[s] == 'R') ? 'B' : 'R';
                q.push(j);
            }
            else if (colored[s] == colored[j]){ cout << "Not a Bipartite Graph  "; return;}
        }
    }
    cout <<"Bipartite Graph";
}

void Graph :: Bipartite(){
    vector <char> colored(V, NULL);
    for(int i = 0; i <  V ; i++)   if(colored[i] == NULL) Bipartiteutility(colored,i);
}

int main()
{

    vector<Edge> edges =
            {
                    {0, 1}, {0, 5}, {1, 2}, {2, 3}, {3, 4}, {5, 4},

            };

    int V = edges.size();
    Graph graph(edges, V);
    //  graph.printGraph();
    graph.Bipartite();

    return 0;
}