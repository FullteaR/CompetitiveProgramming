#include <iostream>
using namespace std;
#define MOD 1000000007

int main(void){
    string t, b;
    cin>>t;
    cin>>b;
    long** dp = new long* [b.size()+1];
    for(int i=0;i<=b.size();i++){
        dp[i] = new long[t.size()+1];
        for(int j=0;j<=t.size();j++){
            dp[i][j] = 0;
        }
    }
    for(int j=0;j<=t.size();j++){
        dp[0][j] = 1;
    }

    for(int i=1;i<=b.size();i++){
        for(int j=1;j<=t.size();j++){
            if(b[i-1]==t[j-1]){
                dp[i][j] = (dp[i-1][j-1]+dp[i][j-1])%MOD;
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    cout<<dp[b.size()][t.size()]<<endl;
}