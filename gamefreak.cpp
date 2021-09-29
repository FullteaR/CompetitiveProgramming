#include <iostream>
#include <cstdio>
using namespace std;

long long check(long long* A, long long K, long long N);


int main(void){
    long step;
    cin>>step;
    long long N;
    cin>>N;
    long long* A = new long long[N];
    for(long i=0;i<N;i++){
        scanf("%lld",A+i);
    }
    long long retval = 0;
    for(long long k=1;k<N;k++){
      retval = max(check(A,k,N),retval);
    }
    cout<<retval<<endl;
}


long long check(long long* A, long long K, long long N){
    long long * dp = new long long [K+1];
    for(long long i=0;i<=K;i++){
        dp[i] = 0;
    }

    for(long long i=1;i<=N;i++){
        long long m = max(i+K-N,(long long)1);
        long long M = min(i,K);
        for(long long j=M;j>=m;j--){
            dp[j] = max(dp[j], dp[j-1]+A[i-1]*(N-K-i+j));
        }
        for(long long j=0;j<=K;j++){
            cout<<dp[j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    return dp[K];
}

