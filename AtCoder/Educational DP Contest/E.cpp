#include <iostream>
using namespace std;
#define INF 10000000010

int main(void){
  long N,W;
  cin>>N>>W;

  long* dp[N+1];
  for(int i=0;i<=N;i++){
    dp[i] = new long[100010];
    for(int j=0;j<100010;j++){
      dp[i][j]=INF;
    }
    dp[i][0]=0;
  }
  for(int i=1;i<=N;i++){
    long v,w;
    cin>>w>>v;
    for(int j=0;j<100010;j++){
      if(j-v>=0){
        dp[i][j]=min(dp[i-1][j],dp[i-1][j-v]+w);
      }
      else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  for(long v=100010-1;v>=0;v--){
    if(dp[N][v]<=W){
      cout<<v<<endl;
      break;
    }
  }

  return 0;
}
