
#include "iostream"
#include "vector"


using namespace std;

struct Edge {
    int source,destination;
};

struct EdgeTypes {
    vector<Edge> tree_edge;
    vector<Edge> forward_edge;
    vector<Edge> back_edge;
    vector<Edge> cross_edge;
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
            // adjList[i.destination].push_back(i.source);

        }
    }

    /*
            *  DFS only yield tree and back edges on undirected, connected
            *
            *Tree edge:

               arrival[u] < arrival[v]
               departure[u] > departure[v]

               Back edge:

               arrival[u] < arrival[v]
               departure[u] < departure[v]

               Forward edge:

               arrival[u] < arrival[v]
               departure[u] > departure[v]

               Cross edge:

               arrival[u] > arrival[v]
               departure[u] > departure[v]

               For tree edge, back edge and forward edges, the relation between the arrival times and departure times of
               the endpoints is immediate from the tree structure. For any cross edge, u is neither an ancestor nor descendant of v.
               So we can say that u and v’s intervals do not overlap. i.e. for an edge u -> v,

               arrival[v] < departure[v] < arrival[u] < departure[u]

               Please note we cannot have an edge from v -> u. If any such edge was there, it would have formed the Tree Edge.
            *
    * */


    void types_OF_Edges_In_GraphUtil(vector<bool> &discovered, int s, vector<int> &arriavl, vector<int> &departure, int &time,EdgeTypes &result );
    void types_OF_Edges_In_Graph(int s);
    void printGraph();


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


void Graph ::types_OF_Edges_In_GraphUtil(vector<bool> &discovered,int s,vector<int> &arrival,vector<int> & departure ,int & time1,EdgeTypes &result ) {
    discovered[s] = true;
    arrival[s] = ++time1;
    for(auto i : this->adjList[s]) {
        if(discovered[i] == false) {
            types_OF_Edges_In_GraphUtil(discovered, i, arrival, departure, time1,result);
            result.tree_edge.push_back({s,i});   //tree edge
        }
        else if(departure[s]==-1 && departure[i]==-1)               result.back_edge.push_back({s,i});  // back edge
        else if(departure[s]==-1 && arrival[s]<arrival[i])          result.forward_edge.push_back({s,i});   // forward edge
        else                                                        result.cross_edge.push_back({s,i});    // cross edge

    }
    departure[s] = ++time1;
}

void Graph ::types_OF_Edges_In_Graph(int s) {
    vector<bool> discovered(V, false);
    vector <int > arrival(V,0);
    vector<int > departure(V,-1);
    EdgeTypes result;
    int time = 0;
    for (int i = s; i < V; i++) if (discovered[i] == false)    DFSRecurisvelyUtil(discovered, i, arrival, departure,time,result);
    //if we remove if then it will not work for disjoint graph

    for (int j = 0; j < V; ++j) {
        cout << "Vertex " << j << " (" << arrival[j]<< ", " << departure[j] << ")" << endl;
    }
    cout <<"\n";

    cout <<"Tree edges are :  "; for(auto i : result.tree_edge) cout <<" (" <<i.source <<"," <<i.destination <<") ";cout <<" \n";
    cout <<"Forward edges are :  "; for(auto i : result.forward_edge) cout <<" (" <<i.source <<"," <<i.destination <<") ";cout <<" \n";
    cout <<"Back edges are :  "; for(auto i : result.back_edge) cout <<" (" <<i.source <<"," <<i.destination <<") ";cout <<" \n";
    cout <<"Cross edges are :  "; for(auto i : result.cross_edge) cout <<" (" <<i.source <<"," <<i.destination <<") ";cout <<" \n";
}

int main()

{

    vector<Edge> edges ={   {0, 1}, {0, 2}, {2, 3}, {2, 4}, {3, 1}, {3, 5},
                            {4, 5}, {6, 7}
    };
    vector<Edge> edges1 ={   {1 , 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7},
                             {5, 8}, {5, 4} ,{6,2} ,{1,8}
    };
    int V = edges.size();
    Graph graph(edges, V);
    graph.types_OF_Edges_In_Graph(0);
    return 0;
}