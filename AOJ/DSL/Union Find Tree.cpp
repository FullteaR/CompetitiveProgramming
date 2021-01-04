#include <iostream>
#include <vector>
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
  int n,q;
  cin>>n>>q;
  auto u = UnionFind(n);
  for(long i=0;i<q;i++){
    long com,x,y;
    cin>>com>>x>>y;
    if(com==0){
      u.Union(x,y);
    }
    else{
      if(u.Same(x,y)){
        cout<<1<<endl;
      }
      else{
        cout<<0<<endl;
      }
    }
  }
  return 0;
}
