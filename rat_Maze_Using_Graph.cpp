#include <queue>
#include "iostream"
#include "vector"

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
    void  BFS(int x1,int y1,int x2,int y2,int N);
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

void Graph :: BFS(int x1,int y1,int x2,int y2,int N){
    int s = (x1 * N) + y1; int destination = (x2 * N ) + y1;
    vector<bool> discovered(V, false);
    for(int i = 0; i < V; i++)
        discovered[i] = false;

    queue <int> q;
    discovered[s] = true;
    q.push(s);

    while(!q.empty())
    {
        s = q.front();   q.pop();
        if(s == destination) {cout <<"Path exists"; return;}
        for (auto  j : adjList[s]) {
            if(!discovered[j]){
                discovered[j] = true;
                q.push(j);
            }
        }
    }
    cout <<"Path does not exists";
}

bool valid(int x,int y,int N){
    if(x <0 || y < 0 || x >= N || y >= N) return false;
    return true;
}

int main()
{

    vector<Edge> edges ;

    int maze[4][4] = { { 1, 0, 0, 1 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 1},
                       { 1, 1, 1, 1 } };

    int N = (*(&maze + 1) - maze);

    int row[]     = {1,-1,0,0};
    int column [] = {0,0,-1,1};
    int sizeof_Row = (*(&row + 1) - row);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < sizeof_Row; ++k) {
                int next_X = i + row[k];  int next_Y = j + column[k];
                if(valid(next_X,next_Y,N) && maze[next_X][next_Y]  && maze[i][j] ) edges.push_back({(i * N) + j,(next_X * N ) + next_Y });
            }
        }
    }

    int V = N * N;
    Graph graph(edges, V);
    //  graph.printGraph();
    graph.BFS(3,0,0,3,N);
    cout << "\n";


    return 0;
}