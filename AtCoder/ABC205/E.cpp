#include <iostream>

using namespace std;
#define MOD 1000000007
#define MAX 1010000


long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main(void){
    COMinit();
    long long N,M,K;
    cin>>N>>M>>K;

    long long ans = COM(N+M,N);
    for(long long i=0;i<N-K;i++){
        ans -= COM(N+M-i,M);
        ans = ans % MOD;
    }
    cout<<ans%MOD<<endl;

    return 0;
}