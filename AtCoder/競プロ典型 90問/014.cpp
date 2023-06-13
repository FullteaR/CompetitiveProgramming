#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    long N;
    cin>>N;

    long* A = new long[N];
    long* B = new long[N];
    for(long i=0;i<N;i++){
        cin>>A[i];
    }
    for(long i=0;i<N;i++){
        cin>>B[i];
    }
    sort(A, A+N);
    sort(B, B+N);
    long retval = 0;
    for(long i=0;i<N;i++){
        retval += abs(A[i]-B[i]);
    }
    cout<<retval<<endl;
}