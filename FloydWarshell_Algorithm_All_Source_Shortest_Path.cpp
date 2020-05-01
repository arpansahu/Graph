#include <iostream>
#include <iomanip>

#define V 4

#include "climits"
using namespace std;




void printPath(int predecessor[][V], int i, int j)
{
    if (predecessor[i][j] == i)
        return;

    printPath(predecessor, i, predecessor[i][j]);
    cout << predecessor[i][j] << " ";
}


void  FloydWarshell_Algorithm_All_Source_Shortest_Path(int adjMatrix[V][V]){
    int distance[V][V],predecessor[V][V];
    //initialising distance and predecessor
    for(auto i = 0 ;i < V; i++){
        for(auto j = 0; j < V ;j++){
            distance[j][i] = adjMatrix[j][i];
            if(i == j) predecessor[j][i] = 0 ;
            else if (distance[j][i] != INT_MAX) predecessor[j][i] = j;
            else predecessor[j][i] = -1;
        }
    }
    //run floyd warshall
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if(distance[i][k] != INT_MAX && distance[k][j] != INT_MAX && distance[i][k] + distance[k][j] < distance[i][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                    predecessor[i][j] = predecessor[k][j];
                }
            }
            if(distance[i][i] < 0) {
                cout <<"Negative Weight Cycle Found!";
                return;
            }
        }
    }
    //printing the adjacencry matrix of distance [][]
    for (int v = 0; v < V; v++)
    {
        for (int u = 0; u < V; u++)
        {
            if (distance[v][u] == INT_MAX)
                cout << setw(5) << "inf";
            else
                cout << setw(5) << distance[v][u];
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (j != i && predecessor[i][j] != -1)
            {
                cout << "Shortest Path from vertex " << i << " to vertex " << j << " is (" << i << " ";
                printPath(predecessor, i, j);
                cout << j << ")" << endl;
            }
        }
    }
}


int main(){

    int adjMatrix[V][V] =
            {
                    {       0, INT_MAX,      -2, INT_MAX },
                    {       4,       0,       3, INT_MAX },
                    { INT_MAX, INT_MAX,       0,       2 },
                    { INT_MAX,      -1, INT_MAX,       0 }
            };

    FloydWarshell_Algorithm_All_Source_Shortest_Path(adjMatrix);

    return 0;

}