#include <iostream>
#include <map>
using namespace std;

int main(void){
  int N,M;
  cin>>N>>M;
  map<int,int> * A = new map<int,int>  [N];
  for(int i=0;i<N;i++){
    map<int, int> d;
    A[i] = d;
  }
  unsigned short s,t,e;
  while(cin>>s>>t>>e){
    if(s==0 and t==0 and e==0)break;
    A[s-1][t-1]=e;
  }
  int L;
  cin>>L;
  for(int _=0;_<L;_++){
    int* b = new int[M];
    for(int i=0;i<M;i++){
      cin>>b[i];
    }
    for(int i=0;i<N;i++){
      long c=0;
      for(auto iter=A[i].begin();iter!=A[i].end();iter++){
        auto key = iter->first;
        auto value = iter->second;
        c+=(long)value * (long)b[key];
      }
      if(i<N-1){
        cout<<c<<" ";
      }
      else{
        cout<<c<<endl;
      }
    }
  }
  return 0;
}
