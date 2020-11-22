#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

long bonze(int N, string S, vector<int>* v);

int main(void){
  int N;
  string S;
  while(cin>>N){
    if(N==0)return 0;
    cin>>S;
    vector<int> v;
    v.clear();
    long rest = bonze(N,S,&v);
    for(int i=0;i<N;i++){
      cout<<v[i]<<" ";
    }
    cout<<rest<<endl;
  }
  return 0;
}


long bonze(int N, string S, vector<int>* v){
  map<int,int> d;
  for(int i=0;i<N;i++){
    d[i]=0;
  }
  int rest=0;
  for(int i=0;i<100;i++){
    int player=i%N;
    char c=S[i];
    switch(c){
      case 'M':
        d[player]++;
        break;
      case 'S':
        rest+=d[player]+1;
        d[player]=0;
        break;
      case 'L':
        d[player]++;
        d[player]+=rest;
        rest=0;
        break;
    }
  }
  assert(v->empty());
  long total=rest;
  for(int i=0;i<N;i++){
    v->push_back(d[i]);
    total+=d[i];
  }
  sort(v->begin(),v->end());
  assert(total==100);
  return rest;
}
