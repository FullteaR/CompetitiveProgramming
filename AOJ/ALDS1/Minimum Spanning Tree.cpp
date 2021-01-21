#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

//https://atcoder.jp/contests/atc001/tasks/unionfind_a

class UnionFind{//without using rank(O(log n))
public:
  UnionFind(long n);
  bool Same(long x, long y);
  void Union(long x, long y);
private:
  long * parents;
  long Root(long x);
};

UnionFind::UnionFind(long n){
  parents = new long[n];
  for(long i=0;i<n;i++){
    parents[i]=i;
  }
}

long UnionFind::Root(long x){
  if(parents[x]==x){
    return x;
  }
  else{
    return parents[x]=Root(parents[x]);
  }
}

bool UnionFind::Same(long x, long y){
  return Root(x)==Root(y);
}

void UnionFind::Union(long x, long y){
  x = Root(x);
  y = Root(y);
  if(x==y) return;
  parents[x]=y;
  return;
 }

int main(void){
  long n;
  cin>>n;
  map<long, vector<pair<long,long> > > weights;
  auto uf = UnionFind(n);
  for(long i=0;i<n;i++){
    for(long j=0;j<n;j++){
      long a;
      cin>>a;
      if(a==-1){
        continue;
      }
      if(weights.find(a)==weights.end()){
        vector<pair<long, long> > v;
        v.push_back(make_pair(i,j));
        weights[a] = v;
      }
      else{
        weights[a].push_back(make_pair(i,j));
      }
    }
  }
  long retval=0;
  for(auto key=weights.begin();key!=weights.end();key++){
    auto value=key->second;
    for(auto iter=value.begin();iter!=value.end();iter++){
      long i,j;
      i=iter->first;
      j=iter->second;
      if(uf.Same(i,j)){
        continue;
      }
      else{
        retval+=key->first;
        uf.Union(i,j);
      }
    }
  }
  cout<<retval<<endl;
  return 0;
}
