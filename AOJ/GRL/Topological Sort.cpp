#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define INF 1000000000010


//https://ja.wikipedia.org/wiki/%E3%83%88%E3%83%9D%E3%83%AD%E3%82%B8%E3%82%AB%E3%83%AB%E3%82%BD%E3%83%BC%E3%83%88
int main(void){
  long V,E;
  cin>>V>>E;
  auto before = new set<long> [V];
  auto after = new set<long> [V];
  for(int i=0;i<V;i++){
    after[i].clear();
    before[i].clear();
  }
  for(int i=0;i<E;i++){
    long s,t;
    cin>>s>>t;
    after[s].insert(t);
    before[t].insert(s);
  }
  vector<long> L;
  vector<long> S;
  for(int i=0;i<V;i++){
    if(before[i].empty()){
      S.push_back(i);
    }
  }
  while(!S.empty()){
    long n = S[0];
    S.erase(S.begin());
    L.push_back(n);
    for(auto iter=after[n].begin();iter!=after[n].end();iter++){
      before[*iter].erase(n);
      if(before[*iter].empty()){
        S.push_back(*iter);
      }
    }
  }
  for(auto iter=L.begin();iter!=L.end();iter++){
    cout<<*iter<<endl;
  }

  return 0;
}
