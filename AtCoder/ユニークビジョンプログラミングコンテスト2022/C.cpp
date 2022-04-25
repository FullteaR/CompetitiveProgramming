#include <iostream>
#define MOD 998244353
using namespace std;


int main(void){
    int N,M,K;
    cin>>N>>M>>K;
    long ** dp = new long* [N+1];
    for(int n=0;n<=N;n++){
        dp[n] = new long[K+1];
        for(int k=0;k<=K;k++){
            dp[n][k] = 0;
        }
    }
    dp[0][0] = 1;
    for(int n=1;n<=N;n++){
        for(int k=0;k<=K;k++){
            for(int A=1;A<=min(M,k);A++){
                dp[n][k]+=dp[n-1][k-A];
                dp[n][k] = dp[n][k] % MOD;
            }
        }
    }
    long retval = 0;
    for(int k=0;k<=K;k++){
        retval+=dp[N][k];
        retval = retval%MOD;
    }
    cout<<retval<<endl;
    return 0;
}