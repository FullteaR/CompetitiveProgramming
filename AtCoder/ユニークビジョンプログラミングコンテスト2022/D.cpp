#include <iostream>
#include <vector>
using namespace std;


int main(void){
    long N;
    cin>>N;
    vector<long>* vectors = new vector<long>[N];
    for(long i=0;i<N;i++){
        vectors[i].clear();
    }
    for(long i=0;i<N;i++){
        long A;
        cin>>A;
        A--;
        vectors[A].push_back(i);
    }
    long Q;
    cin>>Q;
    for(long q=0;q<Q;q++){
        long L,R,X;
        cin>>L>>R>>X;
        X--;
        L--;
        R--;
        long result = (lower_bound(vectors[X].begin(),vectors[X].end(), R+1) - vectors[X].begin())
            - (lower_bound(vectors[X].begin(),vectors[X].end(), L) - vectors[X].begin());
        cout<<result<<endl;
    }
}