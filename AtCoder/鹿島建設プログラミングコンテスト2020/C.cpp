#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <map>
using namespace std;

int main(void){
  long N;
  cin>>N;
  vector<long> P;
  P.clear();
  bool* used=new bool[N-1];
  for(long i=0;i<N;i++){
    long tmp;
    cin>>tmp;
    P.push_back(tmp);
  }
  for(long i=0;i<N-1;i++){
    used[i]=false;
  }
  vector<pair<long,long> > hist;
  hist.clear();

  long* val2ind = new long[N+1];
  for(long i=0;i<N;i++){
    val2ind[P[i]]=i;
  }
  while(N>1){
    if(P[N-1]==N){
      N--;
      continue;
    }

    long index=val2ind[N];
/*
    for(long i=index;i<N-1;i++){
      used[i]=true;
      hist.push_back(i);
      auto tmp=P[i+1];
      P[i+1]=P[i];
      P[i]=tmp;
    }
    */
    P.erase(P.begin()+index);
    hist.push_back(make_pair(index,N-1));
    N--;
  }
  for(auto iter=hist.begin(); iter!=hist.end();iter++){
    for(long i=iter->first;i<iter->second;i++){
      if(used[i]){
        cout<<-1<<endl;
        return 0;
      }
      used[i]=true;
    }
  }
  bool last=false;
  if(P[0]==2 and P[1]==1 and used[0]==false){
    last=true;
    used[0]=true;
    P[0]=1;
    P[1]=2;
  }

  for(long i=0;i<N-1;i++){
    if(used[i]==false){
      cout<<-1<<endl;
      return 0;
    }
  }
  for(auto iter=hist.begin();iter!=hist.end();iter++){
    for(long i=iter->first;i<iter->second;i++){
      printf("%ld\n",i+1);
    }
  }
  if(last){
    cout<<1<<endl;
  }
  return 0;
}
