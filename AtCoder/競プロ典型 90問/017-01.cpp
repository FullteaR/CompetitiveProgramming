#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    long N,M;
    cin>>N>>M;
    vector<pair<long, long> > v;
    v.clear();
    for(long i=0;i<M;i++){
        long L,R;
        cin>>L>>R;
        L--;
        R--;
        v.push_back(make_pair(L,R));
    }

    sort(v.begin(), v.end());
    long retval = 0;
    for(long i=0;i<v.size();i++){
        pair<long, long> p1 = v[i];
        long l1 = p1.first;
        long r1 = p1.second;
        for(long j=i+1;j<v.size();j++){
            pair<long, long> p2 = v[j];
            long l2 = p2.first;
            long r2 = p2.second;
            if(l1<l2 and l2<r1 and r1<r2){
                retval++;
            }
        }
    }
    cout<<retval<<endl;
    return 0;

}