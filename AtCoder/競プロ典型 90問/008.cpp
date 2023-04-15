#include <iostream>
using namespace std;
#define MOD 1000000007

long search(string s, char c);

int main(void){
    long N;
    cin>>N;
    string S;
    cin>>S;
    string atcoder = "atcoder";
    long** dp = new long* [atcoder.size()+1];
    for(long i=0;i<(long)atcoder.size()+1;i++){
        dp[i] = new long[N+1];
        for(long j=0;j<=N;j++){
            if(i==0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    for(long j=1;j<=N;j++){
        for(long i=0;i<(long)atcoder.size()+1;i++){
            char c = S[j-1];
            long index = search(atcoder,c);
            dp[i][j] = dp[i][j-1];
            if(index==i-1){
                dp[i][j]+=dp[i-1][j-1];
            }
            dp[i][j] %= MOD;
        }
    }
    cout<<dp[atcoder.size()][N]<<endl;

}


long search(string s, char c){
    for(long i=0;i<(long)s.size();i++){
        if(s[i]==c){
            return i;
        }
    }
    return -10;
}