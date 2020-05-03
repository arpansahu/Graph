#include "iostream"
#include "vector";
#include "queue"
#include "set"
using namespace std;
#define N 4

int row[]={1,-1,0,0};
int column [] = {0,0,-1,1};
int sizeof_Row = (*(&row + 1) - row);


struct Node{
    int x,y,dist;
    Node(int x,int y,int dist = 0) : x(x),y(y),dist(dist) {}
    bool operator<(const Node& o) const
    {
        return x < o.x || (x == o.x && y < o.y);
    }
};

bool valid(Node curr){
    if(curr.x <0 || curr.y < 0 || curr.x >= N || curr.y >= N) return false;
    return true;
}

void BFS(int x1,int y1,int x2,int y2,int maze[N][N]){
    int row []= {1 ,-1 ,0 , 0};
    int column [] = {0 ,0 ,-1, 1};
    int size_Of_row = (*(&row  + 1) - row);

    Node source(x1,x2); Node destination(x2,y2);
    queue<Node> q;
    set<Node> visited;
    q.push(source);
    while(!empty(q)){
        Node curr = q.front();  q.pop();
        cout <<curr.x <<"," <<curr.y <<"\n";
        if(curr.x == destination.x && curr.y == destination.y) {cout <<"Path exists ";return;}
        for(auto i = 0; i < sizeof_Row; i ++){
            Node next  = {curr.x + row[i] , curr.y + column[i] , curr.dist + 1};
            if(!visited.count(next)) if(valid(next) && maze[curr.x][curr.y] && maze[next.x][next.y]) {q.push(next); visited.insert(next);}
        }

    }
    cout <<"Path does not exist ";

}

int main(){
    int maze[N][N] = { { 1, 1, 0, 9 },
                       { 1, 1, 0, 0},
                       { 0, 1, 0, 1 },
                       { 3, 1, 1, 1 } };

    BFS(3,0,0,3,maze);

    return 0;
}