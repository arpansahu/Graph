#include<iostream>
#include<set>
#include<queue>
#include<climits>

using namespace std;
# define N 8

int row[] = {1,1,-1,-1,2,2,-2,-2};
int col[] = {2,-2,2,-2,1,-1,1,-1};

bool valid(int x,int y){
    if(x <0 || y < 0 || x >= N || y >= N) return false;
    return true;
}

struct Node{
    int x,y,dist;
    Node(int x,int y,int dist = 0) : x(x),y(y),dist(dist) {}
    bool operator<(const Node& o) const
    {
        return x < o.x || (x == o.x && y < o.y);
    }
};

int BFS(Node src,Node dest){
    set<Node> visited;
    queue<Node> queue1;
    queue1.push(src);
    while(!queue1.empty()){
        Node node = queue1.front(); queue1.pop();
        if(node.x == dest.x && node.y == dest.y) return node.dist;
        if(!visited.count(node)){
            visited.insert(node);
            for(int i  = 0; i < 8 ; i++)  if(valid(node.x + row[i],node.y + col[i])) queue1.push({node.x + row[i],node.y + col[i],node.dist + 1});
        }
    }
}
int main(){
    Node src = {0 , 7};
    Node dest = {7 , 0};
    cout <<"Minimum number of steps required is : "<<BFS(src,dest);
    return 0;
}
