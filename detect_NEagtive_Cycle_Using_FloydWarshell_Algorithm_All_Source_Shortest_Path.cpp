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


void  detect_NEagtive_Cycle_Using_FloydWarshell_Algorithm_Single_Source_Shortest_Path(int adjMatrix[V][V]){
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

    cout <<"No Negative Weight Cycle Found!";
}


int main(){

    int adjMatrix[V][V] =
            {
                    {       0, INT_MAX,      -2, INT_MAX },
                    {       4,       0,       3, INT_MAX },
                    { INT_MAX, INT_MAX,       0,       2 },
                    { INT_MAX,      -1, INT_MAX,       0 }
            };

    detect_NEagtive_Cycle_Using_FloydWarshell_Algorithm_Single_Source_Shortest_Path(adjMatrix);

    return 0;

}