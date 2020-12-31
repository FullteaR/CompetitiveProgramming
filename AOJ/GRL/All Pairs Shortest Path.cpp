#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define INF 1000000000010


bool dijkstra(set<long> * v, map<pair<long, long> ,long> * mp, int N, int s, vector<long>* retval);


int main(void){
  vector<long> retval;
  long V,E;
  cin>>V>>E;
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
  for(int r=0;r<V;r++){
    bool all_pos = dijkstra(v,&mp,V,r,&retval);
    if(!all_pos){
      cout<<"NEGATIVE CYCLE"<<endl;
      return 0;
    }
    for(int i=0;i<V;i++){
      if(retval[i]==INF){
        cout<<"INF";
      }
      else{
        cout<<retval[i];
      }
      if(i<V-1){
        cout<<" ";
      }
      else{
        cout<<endl;
      }
    }
  }

  return 0;
}

bool dijkstra(set<long> * v, map<pair<long, long> ,long> * mp, int N, int s, vector<long>* retval){
  retval->clear();
  for(int i=0;i<N;i++){
    retval->push_back(INF);
  }
  (*retval)[s]=0;
  set<long> updated, next;
  updated.clear();
  updated.insert(s);
  long count = 0;
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
    count++;
    if(count>N){
      return false;
    }
  }
  return true;
}
