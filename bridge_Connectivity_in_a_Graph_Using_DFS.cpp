//this code is same for two edge connectivity and brdige program
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

    int  two_Edge_Connectivity_in_a_Graph_Using_DFS(int i, vector<bool> discovered, int parent,int & time,vector<int> & arrival);
    //in dfs we need to find out a back edge
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
struct Node {
    int vertex ,parent ;
};
int Graph ::two_Edge_Connectivity_in_a_Graph_Using_DFS(int v, vector<bool> discovered, int parent,int & time,vector<int> & arrival) {
  arrival[v] = ++time;
  discovered[v] = true;
  int arr = arrival[v];
  for (int w : adjList[v])
  {
      if (!discovered[w]) {arr = min(arr, two_Edge_Connectivity_in_a_Graph_Using_DFS( w, discovered, v, time,arrival));}
      else if (w != parent)   arr = min(arr, arrival[w]);
  }
  if (arr == arrival[v] && parent != -1)
      cout << parent << ", " << v << '\n';
  return arr;
}

int main()

{   //In this progra bridge can be repatted and thsty we can use a dict or map to avoid that and hten print the result
    //	{0, 2}, {1, 2}, {2, 3}, {2, 4}, {3, 4}, {3, 5}    Output : 2, 1   3, 5   0, 2
    //  {0,1},{1,2},{2,0},{1,3},{1,4},{1,6},{3,5},{4,5}  Ouput : 1,6

    vector<Edge> edges ={
        {0,1},{1,2},{2,3}   // 1 0  2 3   1 2
    };

    set <int > setsize;
    for(auto  i : edges){ setsize.insert(i.source);setsize.insert(i.destination);}
    int V = setsize.size();
    Graph graph(edges, V);

    vector<bool> discovered(V + 1,false); int time = 0; vector<int> arrival(V);
  //  graph.printGraph();
    graph.two_Edge_Connectivity_in_a_Graph_Using_DFS(1, discovered, -1 ,time,arrival);

    return 0;
}
