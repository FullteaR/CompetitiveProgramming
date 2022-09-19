#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, L, R;
    cin>>N>>L>>R;
    long long *A = new long long[N];
    for(long long i=0;i<N;i++) {
        cin>>A[i];
    }
    long long *f = new long long[N+1];
    long long *g = new long long[N+1];
    f[0] = 0;
    for(long long i=0;i<N;i++) {
        f[i+1] = min(f[i]+A[i], L*(i+1));
    }
    g[N] = 0;
    for(long long i=N;i>0;i--) {
        g[i-1] = min(g[i]+A[i-1], (N-i+1)*R);
    }
    long long retval = R*N;
    for(long long i=0;i<=N;i++) {
        retval = min(retval, f[i]+g[i]);
    }
    
    cout<<retval<<endl;
    return 0;
}