#include <iostream>
using namespace std;
#define MOD 998244353

long long root2leaf(long long N);
long long count_depth_more_than(long long d, long long N);

long long * pow2;

int main(void){
    long long N, D;
    cin>>N>>D;
    pow2 = new long long [2*N+10];
    pow2[0]=1;
    for(long i=1;i<2*N+10;i++){
        pow2[i] = (pow2[i-1]*2)%MOD;
    }

    if(D>(N-1)*2){
        cout<<0<<endl;
        return 0;
    }
    long long retval = 0;
    for(long long l=0;l<=D;l++){
        long long r = D-l;
        long long _retval = count_depth_more_than(max(l,r), N);
        if(_retval==0){
            continue;
        }
        _retval *= root2leaf(l-1);
        _retval = _retval%MOD;
        _retval *= root2leaf(r-1);
        _retval = _retval%MOD;
        retval += _retval*2;
        retval = retval % MOD;
    }
    cout<<retval<<endl;
    return 0;
}



long long root2leaf(long long N){
    if(N<0){
        return 1;
    }
    return pow2[N];
}
long long count_depth_more_than(long long d, long long N){
    if(d-N>-1){
        return 0;
    }
    return pow2[N-d]-1;
}