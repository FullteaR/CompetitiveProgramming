#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
#define INF 1000000010

struct HashPair {

    //注意 constがいる
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {

        //first分をハッシュ化する
        auto hash1 = hash<T1>{}(p.first);

        //second分をハッシュ化する
        auto hash2 = hash<T2>{}(p.second);

        //重複しないようにハッシュ処理
        size_t seed = 0;
        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

void dijkstra(set<long> * v, unordered_map<pair<long, long> ,long, HashPair> * mp, int N, int s, vector<long>* retval);
  /*
  入力
  v: 隣接要素のsetを持つ配列。v[i]はi番目の頂点から行くことができる頂点を集めたset。
  mp: 辺の重みを参照 mp[make_pair(i,j)]で辺i->jの重みを取得できる。
  N: 頂点サイズ
  s: スタート
  retval: 各頂点のスタートからの最短距離が格納されるベクトル。
  */



int main(void){
  long N,M;
  cin>>N>>M;

    long** cost = new long*[N];
    for(long i=0;i<N;i++){
      cost[i]=new long[N];
      for(long j=0;j<N;j++){
        cost[i][j]=INF;
      }
    }

    for(long i=0;i<M;i++){
      long A,B,C;
      cin>>A>>B>>C;
      A--;
      B--;
      cost[A][B]=min(cost[A][B],C);
    }
    for(long k=0;k<N;k++){
      for(long i=0;i<N;i++){
        for(long j=0;j<N;j++){
          cost[i][j]=min(cost[i][j], cost[i][k]+cost[k][j]);
        }
      }
    }
    for(long i=0;i<N;i++){
      if(cost[i][i]==INF){
        printf("-1\n");
      }
      else{
        printf("%ld\n",retval[i+N]);
      }
    }
    return 0;

}


void dijkstra(set<long> * v, unordered_map<pair<long, long> ,long, HashPair> * mp, int N, int s, vector<long>* retval){
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
