#include <iostream>
using namespace std;

int main(void){
    long N;
    cin>>N;
    long long * A = new long long[N];
    long long S = 0;
    for(long i=0;i<N;i++){
        cin>>A[i];
        S+=A[i];
    }
    long long X;
    cin>>X;
    long long retval = N*(X/S);
    X = X%S;
    long i=0;
    while(X>=0){
        retval+=1;
        X-=A[i];
        i++;
    }
    cout<<retval<<endl;
    return 0;
}