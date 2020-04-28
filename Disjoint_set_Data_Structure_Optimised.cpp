#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DisjointSet{
    unordered_map <int,int> parent;
    unordered_map <int,int> rank;

public:

    void makeSet(vector<int> universe){
      for(auto i : universe) {parent[i] = i;  rank[i] = 0;   }
    }
    int Find(int k){
      if(parent[k] == k) return k;
      return Find(parent[k]);
    }
    void Union(int a,int b){
      if ( a == b ) return ;
      if(rank[a] < rank[b]) parent[a] = b;
      else if (rank[a] > rank[b]) parent[b] = a;
      else{parent[a] = b; rank[b]++; }
    }
    void printSets(vector<int> universe){
      for (auto i :universe) cout<<Find(i)<<" "; cout<<"\n";
    }
};

int main(){
  vector<int> universe = { 1, 2, 3, 4, 5 };
  DisjointSet s1;
  s1.makeSet(universe);
  s1.printSets(universe);

  s1.Union(4,3);
  s1.printSets(universe);

  s1.Union(2,1);
  s1.printSets(universe);

  s1.Union(1,3);
  s1.printSets(universe);

  return 0;
}
