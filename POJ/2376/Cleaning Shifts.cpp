#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int main(void){
  long N,T;
  cin>>N>>T;
  pair<long,long>* C=(pair<long,long>*)malloc(N*sizeof(pair<long,long>));
  for(long i=0;i<N;i++){
    scanf("%ld %ld",&C[i].first,&C[i].second);
  }
  sort(C,C+N);

  long finished=0;
  long c=0;
  while(finished<T and c<=N){
    long best=0;
    for(int i=0;i<N;i++){
      if(C[i].first>finished+1){
        break;
      }
      best=max(best,C[i].second);
    }
    if(best<finished){
      break;
    }
    finished=best;
    c+=1;
  }
  if(finished<T){
    cout<<-1<<endl;
  }
  else{
    cout<<c<<endl;
  }
  return 0;
}
