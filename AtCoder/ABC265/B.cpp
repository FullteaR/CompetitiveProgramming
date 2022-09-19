#include <iostream>
using namespace std;

int main(void) {
    long N, M, T;
    cin>>N>>M>>T;
    long* A = new long[N];
    A[0] = 0;
    for(long i=1;i<N;i++) {
        cin>>A[i];
    }
    for(long i=0;i<M;i++) {
        long X,Y;
        cin>>X>>Y;
        A[X] -= Y;
    }
    bool success = true;
    for(long i=0;i<N;i++){
        T -= A[i];
        if(T<=0) {
            success = false;
            break;
        }
    }
    if(success) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    return 0;
}