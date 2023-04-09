#include <iostream>
using namespace std;

bool is_possible(long score, long* pieces, long N, long K);

int main(void) {
    long N,L,K;
    cin>>N>>L;
    cin>>K;
    long* A = new long[N];
    for(long i=0;i<N;i++){
        cin>>A[i];
    }
    long* pieces = new long[N+1];
    pieces[0] = A[0];
    pieces[N] = L-A[N-1];
    for(long i=1;i<N;i++){
        pieces[i] = A[i] - A[i-1];
    }

    long h = 0;
    long H = L+1;
    while(H-h>1){
        long m = (h+H)/2;
        if(is_possible(m, pieces, N, K)){
            h=m;
        }
        else{
            H=m;
        }
    }
    long retval = H;
    if(is_possible(h, pieces, N, K)){
        retval = h;
    }
    cout<<retval<<endl;
    return 0;
}

bool is_possible(long score, long* pieces, long N, long K) {
    long total = 0;
    long length = 0;
    for(long i=0;i<=N;i++){
        if(length + pieces[i] >= score) {
            length = 0;
            total ++;
        }
        else{
            length += pieces[i];
        }
    }
    return total>=K+1;
}