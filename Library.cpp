#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

//Union Find Tree
/*
uf = UnionFind(long n);
void uf.Union(long x, long y);
bool uf.Same(long x, long y);
*/
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


//dijkstra search
/*
入力
v: 隣接要素のsetを持つ配列。v[i]はi番目の頂点から行くことができる頂点を集めたset。
mp: 辺の重みを参照 mp[make_pair(i,j)]で辺i->jの重みを取得できる。
N: 頂点サイズ
s: スタート
retval: 各頂点のスタートからの最短距離が格納されるベクトル。
*/
 void dijkstra(set<long> * v, map<pair<long, long> ,long> * mp, int N, int s, vector<long>* retval){
   retval->clear();
   for(int i=0;i<N;i++){
     retval->push_back(INF);
   }
   (*retval)[s]=0;
   set<long> updated, next;
   updated.clear();
   updated.insert(s);
   while(!updated.empty()){
     next.clear();
     for(auto iter=updated.begin();iter!=updated.end();iter++){
       for(auto iter2=v[*iter].begin();iter2!=v[*iter].end();iter2++){
         long weight=(*mp)[make_pair(*iter,*iter2)];
         if((*retval)[*iter2]>(*retval)[*iter]+weight){
           (*retval)[*iter2]=(*retval)[*iter]+weight;
           next.insert(*iter2);
         }
       }
     }
     updated.swap(next);
   }
 }

void DAGsort(set<long> * before, set<long> * after,long N, vector<long>* retval){
  /*
  before: before[x]はxに向かって伸びる辺をもつ頂点のset
  after: after[x]はxから出る辺の先にある頂点のset
  N: 頂点サイズ
  retval: DAGsort結果が格納されるベクトル
  ※beforeは破壊される。afterは多分非破壊的
  */
   retval->clear();
   vector<long> S;
   for(long i=0;i<N;i++){
     if(before[i].empty()){
       S.push_back(i);
     }
   }
   while(!S.empty()){
     long n = S[0];
     S.erase(S.begin());
     retval->push_back(n);
     for(auto iter=after[n].begin();iter!=after[n].end();iter++){
       before[*iter].erase(n);
       if(before[*iter].empty()){
         S.push_back(*iter);
       }
     }
   }
 }


 int main(void){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
 }
