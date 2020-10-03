#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void){
  long N,K;
  cin>>N>>K;
  if(N==1){cout<<1<<endl;return 0;}
  long* A=(long*)malloc(sizeof(long)*N);
  long* dp=(long*)malloc(sizeof(long)*N);
  for(long i=0;i<N;i++){
    cin>>A[i];
    dp[i]=1;
  }
  for(int i=1;i<N;i++){
    bool up=false;
    bool down=false;
    for(int j=i-1;j>=0;j--){
      if(A[j]<=A[i] and A[i]-A[j]<=K){
        down=true;
        dp[i]=max(dp[i], dp[j]+1);
      }
      if(A[j]>=A[i] and A[j]-A[i]<=K){
        up=true;
        dp[i]=max(dp[i], dp[j]+1);
      }
      if(up and down){break;}
    }
  }
  long retval=0;
  for(long i=0;i<N;i++){
    retval=max(retval,dp[i]);
  }
  cout<<retval<<endl;
  return 0;
}
