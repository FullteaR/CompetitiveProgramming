#include <iostream>
#include <vector>
using namespace std;
#define INF 100000010

int main(void){
  string* dp[3010];
  long* len[3010];
  for(int i=0;i<3010;i++){
    dp[i] = new string[3010];
    len[i] = new long[3010];
  }
  for(int i=0;i<3010;i++){
    dp[i][0]="";
    len[i][0]=0;
  }
  for(int j=0;j<3010;j++){
    dp[0][j]="";
    len[0][j]=0;
  }
  string s;
  string t;
  cin>>s;
  cin>>t;
  int s_size=s.size();
  int t_size=t.size();
  for(int i=1;i<=s_size;i++){
    for(int j=1;j<=t_size;j++){
      if(len[i-1][j]>len[i][j-1]){
        dp[i][j]=dp[i-1][j];
        len[i][j]=len[i-1][j];
      }
      else{
        dp[i][j]=dp[i][j-1];
        len[i][j]=len[i][j-1];
      }
      if(s[i-1]==t[j-1]){
        if(len[i-1][j-1]+1>len[i][j]){
          dp[i][j]=dp[i-1][j-1]+s[i-1];
          len[i][j]=len[i-1][j-1]+1;
        }
      }
      else{
        if(len[i-1][j-1]>len[i][j]){
          dp[i][j]=dp[i-1][j-1];
          len[i][j]=len[i-1][j-1];
        }
      }
    }
  }
  cout<<dp[s.size()][t.size()]<<endl;
  return 0;
}
