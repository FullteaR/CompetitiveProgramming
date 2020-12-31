#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define INF 1000000000010

//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja

void dijkstra(set<long> * v, map<pair<long, long> ,long> * mp, int N, int s, vector<long>* retval);
/*
入力
v: 隣接要素のsetを持つ配列。v[i]はi番目の頂点から行くことができる頂点を集めたset。
mp: 辺の重みを参照 mp[make_pair(i,j)]で辺i->jの重みを取得できる。
N: 頂点サイズ
s: スタート
retval: 各頂点のスタートからの最短距離が格納されるベクトル。
*/

int main(void){
  vector<long> retval;
  long V,E,r;
  cin>>V>>E>>r;
  set<long>* v=new set<long>[V];
  for(int i=0;i<V;i++){
    v[i].clear();
  }
  map<pair<long, long>, long> mp;
  for(long i=0;i<E;i++){
    long s,t,d;
    cin>>s>>t>>d;
    v[s].insert(t);
    mp[make_pair(s,t)]=d;
  }
  dijkstra(v,&mp,V,r,&retval);
  for(int i=0;i<V;i++){
    if(retval[i]==INF){
      cout<<"INF"<<endl;
    }
    else{
      cout<<retval[i]<<endl;
    }
  }
  return 0;
}

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
