#include <iostream>
using namespace std;

int main(void) {
    long N;
    cin>>N;
    long* class1 = new long[N];
    long* class2 = new long[N];
    for(long i=0;i<N;i++){
        long C, P;
        cin>>C>>P;
        if(C==1){
            class1[i] = P;
            class2[i] = 0;
        }
        else{
            class1[i] = 0;
            class2[i] = P;
        }
    }
    long* cum1 = new long[N+1];
    long* cum2 = new long[N+1];
    cum1[0] = 0;
    cum2[0] = 0;
    for(long i=1;i<=N;i++){
        cum1[i] = cum1[i-1]+class1[i-1];
        cum2[i] = cum2[i-1]+class2[i-1];
    }
    long Q;
    cin>>Q;
    for(long i=0;i<Q;i++){
        long L,R;
        cin>>L>>R;
        long A = cum1[R] - cum1[L-1];
        long B = cum2[R] - cum2[L-1];
        cout<<A<<" "<<B<<endl;
    }
    return 0;
}