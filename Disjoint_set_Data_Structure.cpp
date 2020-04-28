#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DisjointSet{
    unordered_map  <int ,int> parent;
public:

    void  makeSet(vector <int> &universe){
      for(auto i : universe) parent[i] = i;
    }

    int Find(int k ){
      if(parent[k] == k) return k ;
      return Find(parent[k]);
    }

    void Union(int a, int b){
      parent[Find(a)] = Find(b);
    }

    void printSets(vector <int> universe){
      for(auto i:universe) cout <<Find(i) <<" "; cout <<"\n";
    }
};

int  main() {
  vector <int> universe = { 1,2,3,4,5};
  DisjointSet DS1;
  DS1.makeSet(universe);
  DS1.printSets(universe);

  DS1.Union(4,3);
  DS1.printSets(universe);

  DS1.Union(2,1);
  DS1.printSets(universe);

  DS1.Union(1,3);
  DS1.printSets(universe);

  return 0;
}
