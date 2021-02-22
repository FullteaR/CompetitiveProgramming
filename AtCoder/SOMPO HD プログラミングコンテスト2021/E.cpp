#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <utility>
#define INF 1000000000000010
using namespace std;


void dijkstra(set<long long> * v, map<pair<long long, long long> ,set<pair<long long, long long> > > * mp, long long N, long long s, vector<long long>* retval){
  retval->clear();
  for(int i=0;i<N;i++){
    retval->push_back(INF);
  }
  (*retval)[s]=0;
  set<long long> updated, next;
  updated.clear();
  updated.insert(s);
  while(!updated.empty()){
    next.clear();
    for(auto iter=updated.begin();iter!=updated.end();iter++){
      for(auto iter2=v[*iter].begin();iter2!=v[*iter].end();iter2++){
        auto weights=(*mp)[make_pair(*iter,*iter2)];
        long long weight = INF;
        for(auto iter3 = weights.begin();iter3!=weights.end();iter3++){
          long long T = (*iter3).first;
          long long K = (*iter3).second;
          weight = min((K-(*retval)[*iter]%K)%K+T,weight);
        }
        if((*retval)[*iter2]>(*retval)[*iter]+weight){
          (*retval)[*iter2]=(*retval)[*iter]+weight;
          //cout<<"start:"<<*iter<<" goal:"<<*iter2<<" departure time:"<<(*retval)[*iter]<<" arrive time:"<<(*retval)[*iter2]<<endl;
          next.insert(*iter2);
        }
      }
    }
    updated.swap(next);
  }
}


int main(void){
  long long N,M,X,Y;
  cin>>N>>M>>X>>Y;
  X--;
  Y--;
  set<long long>* v = new set<long long> [N];
  map<pair<long long, long long> ,set<pair<long long, long long> > >  mp;
  for(long long i=0;i<N;i++){
    v[i].clear();
  }
  vector<long long> retval;
  for(long long i=0;i<M;i++){
    long long A,B,T,K;
    cin>>A>>B>>T>>K;
    A--;
    B--;
    v[A].insert(B);
    v[B].insert(A);

    mp[make_pair(A,B)].insert(make_pair(T,K));
    mp[make_pair(B,A)].insert(make_pair(T,K));

  }
  dijkstra(v,&mp, N,X,&retval);
  if(retval[Y]==INF){
    cout<<-1<<endl;
  }
  else{
    cout<<retval[Y]<<endl;
  }

  return 0;
}
