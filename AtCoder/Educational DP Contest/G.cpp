#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>
#include <utility>
using namespace std;
#define INF 1000000000010

//https://ja.wikipedia.org/wiki/%E3%83%88%E3%83%9D%E3%83%AD%E3%82%B8%E3%82%AB%E3%83%AB%E3%82%BD%E3%83%BC%E3%83%88

void DAGsort(set<long> * before, set<long> * after,long N, vector<long>* retval);
/*
before: before[x]はxに向かって伸びる辺をもつ頂点のset
after: after[x]はxから出る辺の先にある頂点のset
N: 頂点サイズ
retval: DAGsort結果が格納されるベクトル
*/

int main(void){
  long N,M;
  cin>>N>>M;
  set<long> * before =new set<long>[N];
  set<long> * after =new set<long>[N];
  for(long i=0;i<N;i++){
    before[i].clear();
    after[i].clear();
  }
  for(long i=0;i<M;i++){
    long x,y;
    cin>>x>>y;
    x--;
    y--;
    before[y].insert(x);
    after[x].insert(y);
  }
  vector<long> retval;
  DAGsort(before, after, N, &retval);

  long* distance = new long[N];
  for(long i=0;i<N;i++){
    distance[i]=0;
  }
  for(auto iter=retval.begin();iter!=retval.end();iter++){
    for(auto iter2=after[*iter].begin();iter2!=after[*iter].end();iter2++){
      distance[*iter2]=max(distance[*iter]+1,distance[*iter2]);
    }
  }
  
  long longest=0;
  for(long i=0;i<N;i++){
    longest=max(longest,distance[i]);
  }
  cout<<longest<<endl;

  return 0;
}

void DAGsort(set<long> * before, set<long> * after,long N, vector<long>* retval){
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
