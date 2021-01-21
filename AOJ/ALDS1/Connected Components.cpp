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
  int n,m;
  cin>>n>>m;
  auto u = UnionFind(n);
  for(int i=0;i<m;i++){
    long s,t;
    cin>>s>>t;
    u.Union(s,t);
  }
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    long s,t;
    cin>>s>>t;
    if(u.Same(s,t)){
      cout<<"yes"<<endl;
    }
    else{
      cout<<"no"<<endl;
    }
  }
  return 0;
}
