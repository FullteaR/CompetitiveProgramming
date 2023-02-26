#include <iostream>
#include <set>
using namespace std;

int main(void) {
    long N,K;
    cin>>N>>K;
    set<long> A;
    A.clear();
    for(long i=0;i<N;i++) {
        long A_;
        cin>>A_;
        A.insert(A_);
    }
    long retval = 0;
    for(long i=0;i<K;i++){
        if(A.find(i) != A.end()){
            retval = i+1;
        }
        else{
            break;
        }
    }
    cout<<retval<<endl;
    return 0;
}