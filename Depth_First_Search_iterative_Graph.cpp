#include "set"
#include "iostream"
#include "vector"
#include "stack"
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
    void DFSIterativelyUtil(vector<bool> &discovered,int s);
    void DFSIteratively(int s);
    void printGraph();


};

void Graph :: printGraph()
{
    for (int i = 0; i < V; i++)
    {
        cout << i << " -- ";
        for (int v : adjList[i])
            cout <<"->"<< v << " ";
        cout << endl;
    }
}


void Graph ::DFSIterativelyUtil(vector<bool> &discovered,int s) {

    stack<int> stack1;
    stack1.push(s);

    while (!stack1.empty())
    {

        s = stack1.top();
        stack1.pop();

        if (discovered[s])
            continue;

        discovered[s] = true;
        cout << s << " ";
        for (auto it = adjList[s].rbegin();it != adjList[s].rend(); ++it)
        {
            int u = *it;
            if (!discovered[u])
                stack1.push(u);
        }
    }

}

void Graph ::DFSIteratively(int s) {
    vector<bool> discovered(V, false);
    for (int i = s; i < V; i++) if (discovered[i] == false) DFSIterativelyUtil(discovered,i); //if we remove if then it will not work for disjoint graph
}

int main()
{

    vector<Edge> edges =
            {
                    {0, 1}, {0, 2}, {1, 2}, {2, 0}, {2,3},{3,3}
            };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V);
    //   graph.printGraph();
    graph.DFSIteratively(2);
    cout << "\n";




    edges = {
            {0,4},{1,2},{1,3},{1,4},{2,3},{3,4}
    }; // this is aa disjoint graph
    set <int > setsize1;
    for(auto  i : edges){ setsize1.insert(i.source);setsize1.insert(i.destination);}
    int V1 = setsize1.size();
    Graph graph2(edges,V1);

    graph2.DFSIteratively(0);
    return 0;
}