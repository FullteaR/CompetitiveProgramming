#include <iostream>
#include <cstdlib>
using namespace std;
#define INF 1000000010

int main(void){
  long N,M,K;
  cin>>N>>M>>K;
  long* A = (long*)malloc(sizeof(long)*(N+1));
  long* B = (long*)malloc(sizeof(long)*(M+1));
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  A[N]=INF;
  for(int i=0;i<M;i++){
    cin>>B[i];
  }
  B[M]=INF;
  long a=0;
  long t=0;
  for(long i=0;t+A[i]<=K;i++){
    t+=A[i];
    a++;
  }
  long b=0;
  long retval=a+b;
  while(a>=0 and b>=0){
    if(t+B[b]<=K){
      t+=B[b];
      b++;
    }
    else{
      a--;
      t-=A[a];
    }
    if(a>=0){
      retval=max(retval,a+b);
    }
  }

  cout<<retval<<endl;
  return 0;
}
