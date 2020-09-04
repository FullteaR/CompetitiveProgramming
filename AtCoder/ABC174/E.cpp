#include <iostream>
using namespace std;

bool able_check(long L, long* A, long N, long K);

int main(void){
  long N,K;
  cin>>N>>K;
  long* A = (long*)malloc(sizeof(long)*N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  long min=1;
  long max=1000000010;
  while(max-min>5){
    long mid=(min+max)/2;
    if(able_check(mid,A,N,K)){
      max=mid;
    }
    else{
      min=mid;
    }
  }
  for(long i=min;i<=max;i++){
    if(able_check(i,A,N,K)){
      cout<<i<<endl;
      break;
    }
  }
  return 0;
}

bool able_check(long L, long* A, long N, long K){
  long retval=0;
  for(int i=0;i<N;i++){
    if(A[i]%L==0){
      retval+=A[i]/L-1;
    }
    else{
      retval+=A[i]/L;
    }
  }
  return retval<=K;
}
