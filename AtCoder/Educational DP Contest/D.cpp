#include <iostream>
using namespace std;

int main(void){
  long N,W;
  cin>>N>>W;
  long* dp[N+1];
  for(int i=0;i<=N;i++){
    dp[i]=new long[W+1];
  }

  for(int i=0;i<=N;i++){
    for(int j=0;j<=W;j++){
      dp[i][j]=0;
    }
  }
  for(int i=1;i<=N;i++){
    long w,v;
    cin>>w>>v;
    for(int j=0;j<=W;j++){
      dp[i][j]=dp[i-1][j];
      if(j-w>=0){
        dp[i][j]=max(dp[i][j],dp[i-1][j-w]+v);
      }
    }
  }
  long retval=0;
  for(long i=0;i<=W;i++){
    retval=max(retval,dp[N][i]);
  }
  cout<<retval<<endl;
  return 0;
}
