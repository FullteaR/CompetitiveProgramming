#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    long N;
    cin>>N;
    vector<long> A;
    A.clear();
    for(long i=0;i<N;i++){
        long A_;
        cin>>A_;
        A.push_back(A_);
    }
    sort(A.begin(), A.end());
    long Q;
    cin>>Q;
    for(long i=0;i<Q;i++){
        long B;
        cin>>B;
        auto it = lower_bound(A.begin(), A.end(), B);
        if(it==A.begin()){
            cout<<abs(A[0]-B)<<endl;
        }
        else if(it==A.end()){
            cout<<abs(A[A.size()-1]-B)<<endl;
        }
        else{
            cout<<min(abs(*it-B), abs(*(it-1)-B))<<endl;
        }
    }
    return 0;
}