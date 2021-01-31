#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define INF 1000000000010

void dijkstra(set<long> * v, map<pair<long, long> ,long> * mp, int N, int s, vector<long>* retval);

int main(void){
  long N,M;
  cin>>N>>M;
  set<long>* v=new set<long>[N];
  for(int i=0;i<N;i++){
    v[i].clear();
  }
  map<pair<long, long>, long> mp;
  for(long i=0;i<M;i++){
    long A,B;
    cin>>A>>B;
    v[A-1].insert(B-1);
    v[B-1].insert(A-1);
    mp[make_pair(A-1,B-1)]=1;
    mp[make_pair(B-1,A-1)]=1;
  }

  long K;
  cin>>K;
  long* C = new long[K];
  for(long i=0;i<K;i++){
    cin>>C[i];
  }
  map<pair<long, long>, long> mp_dist;
  for(long i=0;i<K;i++){
    vector <long> dij;
    dijkstra(v,&mp,N,C[i]-1,&dij);
    for(long j=0;j<K;j++){
      mp_dist[make_pair(C[i]-1,C[j]-1)]=dij[C[j]-1];
    }
  }
  long m=INF;
  long Ci,Cj;
  bool* reached=new bool[N];
  for(long i=0;i<N;i++){
    reached[i]=false;
  }
  for(auto iter=mp_dist.begin();iter!=mp_dist.end();iter++){
    if(iter->second<m){
      Ci=iter->first.first;
      Cj=iter->first.second;
      m=iter->second;
    }
  }
  reached[Ci]=true;
  reached[Cj]=true;
  long retval=m;
  for(long i=0;i<K-1;i++){
    long m_Ci=INF;
    long _Ci;
    for(auto iter=mp_dist.begin();iter!=mp_dist.end();iter++){
      if(iter->first.first!=Ci)continue;
      if(iter->second<m_Ci){
        if(reached[iter->first.second])continue;
        _Ci=iter->first.second;
        m_Ci=iter->second;
      }
    }
    long m_Cj=INF;
    long _Cj;
    for(auto iter=mp_dist.begin();iter!=mp_dist.end();iter++){
      if(iter->first.first!=Cj)continue;
      if(iter->second<m_Cj){
        if(reached[iter->first.second])continue;
        _Cj=iter->first.second;
        m_Cj=iter->second;
      }
    }
    if(m_Ci<m_Cj){
      Ci=_Ci;
      reached[Ci]=true;
      retval+=m_Ci;
    }
    else{
      Cj=_Cj;
      reached[Cj]=true;
      retval+=m_Cj;
    }
  }
  if(retval<INF){
    cout<<retval+1<<endl;
  }
  else{
    cout<<-1<<endl;
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
