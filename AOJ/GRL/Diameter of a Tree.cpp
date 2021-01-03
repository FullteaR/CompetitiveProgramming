#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define INF 1000000000010

void dijkstra(set<long> * v, map<pair<long, long> ,long> * mp, int N, int s, vector<long>* retval);

int main(void){
  long n;
  cin>>n;
  auto v = new set<long> [n];
  for(int i=0;i<n;i++){
    v[i].clear();
  }
  map<pair<long, long> ,long> mp;
  vector<long> retval;
  for(int i=0;i<n-1;i++){
    long s,t,w;
    cin>>s>>t>>w;
    v[s].insert(t);
    v[t].insert(s);
    mp[make_pair(s,t)]=w;
    mp[make_pair(t,s)]=w;
  }

  long ind=0;
  long M=0;
  dijkstra(v, &mp, n, ind, &retval);
  for(int i=0;i<n;i++){
    if(M<retval[i]){
      ind=i;
      M=retval[i];
    }
  }
  dijkstra(v, &mp, n, ind, &retval);
  M=0;
  for(int i=0;i<n;i++){
    M=max(M,retval[i]);
  }
  cout<<M<<endl;
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
