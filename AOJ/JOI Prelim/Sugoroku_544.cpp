#include <iostream>
using namespace std;

long fin(long N, long M, long* masu, long* dice);

int main(void){
  long N,M;
  while(cin>>N>>M){
    if(N==0 and M==0)break;
    long* masu = new long[N];
    for(long i=0;i<N;i++){
      cin>>masu[i];
    }
    long* dice = new long[M];
    for(long i=0;i<M;i++){
      cin>>dice[i];
    }
    cout<<fin(N,M,masu,dice)+1<<endl;
    delete [] masu;
    delete [] dice;
  }
  return 0;
}

long fin(long N, long M, long* masu, long* dice){
  long pos = 0;
  for(long i=0;i<=M;i++){
    pos+=dice[i];
    if(pos>=N-1){
      return i;
    }
    pos+=masu[pos];
    if(pos<0){
      pos = 0;
    }
    if(pos>=N-1){
      return i;
    }
  }
  return 0;
}
