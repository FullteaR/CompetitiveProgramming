#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void){
    long N,Q;
    cin>>N>>Q;
    vector<long> v;
    v.clear();
    v.push_back(1);
    for(long i=0;i<Q;i++){
        long l,r;
        cin>>l>>r;
        v.push_back(l);
        v.push_back(r+1);
    }
    sort(v.begin(), v.end());
    int c = 0;
    string S = "";
    for(long i=1;i<(long)v.size();i++){
        S+=string(v[i]-v[i-1],(char)(c+'0'));
        c = 1-c;
    }
    S+=string(N+1, '0');
    for(long i=0;i<N;i++){
        cout<<S[i];
    }
    cout<<endl;

    return 0;
}