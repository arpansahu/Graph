#include <queue>
#include "iostream"
#include "vector"
#include "set"
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
            //  adjList[i.destination].push_back(i.source);
        }
    }
    void  Bipartite();
    void printGraph();
    void Bipartiteutility(vector<char> &discovered, int i, bool &cond);
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
    cout <<"\n";
}


void Graph ::Bipartiteutility(vector<char> &discovered, int i, bool &cond) {
    queue <int> q;
    q.push(i);
    discovered[i] = 'R';
    while(!q.empty())
    {
        i = q.front();    q.pop();  //cout << s<<" " ;
        for (auto  j : adjList[i]) {
            if(discovered[j] == NULL){
                discovered[j] = (discovered[i] == 'R') ? 'B' : 'R';
                q.push(j);
            }
            else if (discovered[i] == discovered[j]){ cond = false ;return;}
        }
    }

}

void Graph :: Bipartite(){
    bool cond = true;
    vector <char> colored(V, NULL);
    for(int i = 0; i <  V ; i++)   if(colored[i] == NULL && cond == true) Bipartiteutility(colored, i, cond);
    (cond == true) ? cout << "Bipartite Graph  \n" :cout <<"Not a Bipartite Graph  \n";
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