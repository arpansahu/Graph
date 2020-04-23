#include "set"
#include "iostream"
#include "vector"
#include <unordered_map>
#include "queue"
using namespace std;

struct Edge {
    int source,destination;
};

struct  Node{
    int ver;
    int minDist;
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

    void printGraph();
    void BFSIterative(int start);

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
void Graph ::BFSIterative(int s) {
    queue <Node> q;
    vector <bool >discovered ( V + 1, false);
    discovered[s] = true;
    Node node = {s,0};
    q.push(node);
    while(!q.empty()){
        node = q.front(); q.pop();
        if(node.ver == V) {cout << node.minDist <<" "; break;}
        for(auto u : adjList[node.ver]){
            if(!discovered[u]){
                discovered[u] = true;
                Node n {u,node.minDist + 1};
                q.push(n);
            }
        }
    }
}
void  findSolution(unordered_map<int, int> ladder, unordered_map<int, int> snake,int start){
    vector <Edge> edges;
    int V = 100; //since its 10 * 10 board
    for (int i = 0; i < V ; ++i) {
        for (int j = 1; j <= 6 ; ++j) {
            int src = i;
            int dest = (ladder[i + j] || snake[i + j]) ? (ladder[i + j] + snake[i + j]) : (i + j);
            edges.push_back({src,dest});
        }
    }
    Graph graph (edges,V);
    graph.BFSIterative(start);
}


int main()

{

    unordered_map<int, int> ladder, snake;

    // insert ladders into the map
    ladder[1] = 38;
    ladder[4] = 14;
    ladder[9] = 31;
    ladder[21] = 42;
    ladder[28] = 84;
    ladder[51] = 67;
    ladder[72] = 91;
    ladder[80] = 99;

    // insert snakes into the map
    snake[17] = 7;
    snake[54] = 34;
    snake[62] = 19;
    snake[64] = 60;
    snake[87] = 36;
    snake[93] = 73;
    snake[95] = 75;
    snake[98] = 79;

    findSolution(ladder, snake,0);
    return 0;
}