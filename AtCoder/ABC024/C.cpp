#include <iostream>
#include <utility>
using namespace std;

int main(void){
  long N,D,K;
  cin>>N>>D>>K;
  auto schedule = new pair<long,long> [D];
  for(int i=0;i<D;i++){
    long L,R;
    cin>>L>>R;
    schedule[i]=make_pair(L,R);
  }
  for(int i=0;i<K;i++){
    long S,T;
    cin>>S>>T;
    long limit=S;
    if(S<T){
      for(int j=0;j<D;j++){
        if(schedule[j].first<=limit){
          limit=max(schedule[j].second,limit);
        }
        if(limit>=T){
          cout<<j+1<<endl;
          break;
        }
      }
    }
    else{
      for(int j=0;j<D;j++){
        if(limit<=schedule[j].second){
          limit=min(schedule[j].first,limit);
        }
        if(limit<=T){
          cout<<j+1<<endl;
          break;
        }
      }
    }
  }
  return 0;
}
