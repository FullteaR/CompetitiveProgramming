#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define LEFT 0
#define RIGHT 1
using namespace std;

int main(void){
  long N;
  cin >> N;
  map<long, vector<long> > mp;
  for(long i=0;i<=N+1;i++){
    mp[i].clear();
  }
  mp[0].push_back(0);
  mp[N+1].push_back(0);
  for(long i=0;i<N;i++){
    long X,C;
    cin >> X >> C;
    mp[C].push_back(X);
  }
  for(long i=0;i<=N+1;i++){
    sort(mp[i].begin(), mp[i].end());
  }

  long ** dp = new long* [N+2];//dp[i][LEFT] 色iのballを、左端を最後に回収したときのコスト
  for(long i=0;i<=N+1;i++){
    dp[i] = new long[2];
  }

  for(long i=0;i<=N+1;i++){
    dp[i][LEFT]=0;
    dp[i][RIGHT]=0;
  }
  long left=0;
  long right=0;
  for(long i=1;i<=N+1;i++){
    if(mp[i].empty()){
      dp[i][LEFT]=dp[i-1][LEFT];
      dp[i][RIGHT]=dp[i-1][RIGHT];
      continue;
    }

    long lrl=dp[i-1][LEFT]+abs(mp[i][mp[i].size()-1]-left)+abs(mp[i][mp[i].size()-1]-mp[i][0]);
    long rrl=dp[i-1][RIGHT]+abs(mp[i][mp[i].size()-1]-right)+abs(mp[i][mp[i].size()-1]-mp[i][0]);
    long llr=dp[i-1][LEFT]+abs(mp[i][0]-left)+abs(mp[i][mp[i].size()-1]-mp[i][0]);
    long rlr=dp[i-1][RIGHT]+abs(mp[i][0]-right)+abs(mp[i][mp[i].size()-1]-mp[i][0]);
    dp[i][LEFT]=min(lrl,rrl);
    dp[i][RIGHT]=min(llr,rlr);
    left=mp[i][0];
    right=mp[i][mp[i].size()-1];
  }
  cout<<min(dp[N+1][LEFT],dp[N+1][RIGHT])<<endl;

  return 0;
}
