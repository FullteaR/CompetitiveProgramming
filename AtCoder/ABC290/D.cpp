#include <iostream>
using namespace std;

long solve(long N, long D, long K);
long gcd(long a, long b);

int main(void) {
    long T;
    cin>>T;
    for(long t=0;t<T;t++) {
        long N,D,K;
        cin>>N>>D>>K;
        cout << solve(N,D,K) << endl;
    }
    return 0;
}

long solve(long N, long D, long K) {
    K-=1;
    long g = gcd(N, D);
    long r = K/(N/g);
    K = K%(N/g);
    return ((D*K)%N + r)%N;
}

long gcd(long a, long b){
    if(min(a,b)==0){
        return max(a,b);
    }
    return gcd(min(a,b), max(a,b)%min(a,b));
}