#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstdio>

using namespace std;


bool contains(set<pair<long long, long long> >* porns, long long i, long long j){
    return porns->find(make_pair(i,j))!=porns->end();
}

int main(void){
    long long N,M;
    unordered_set<long long> now;
    now.clear();
    set<pair<long long, long long>> porns;
    porns.clear();    
    cin>>N>>M;
    set<long long> _Xs;
    for(long long i=0;i<M;i++){
        long long X,Y;
        scanf("%lld %lld", &X,&Y);
        porns.insert(make_pair(X,Y));
        _Xs.insert(X);
    }
    vector<long long> Xs(_Xs.begin(), _Xs.end());
    sort(Xs.begin(),Xs.end());
    now.insert(N);
    for(auto iter2 = Xs.begin();iter2!=Xs.end();iter2++){
        long long i = *iter2-1;
        if(i<0 or i>=2*N){
            continue;
        }
        for(auto iter = now.begin();iter!=now.end();iter++){
            long long j = *iter;
            if(contains(&porns, i+1, j)){
                now.erase(j);
            }
            if(j<2*N and contains(&porns, i+1, j+1)){
                now.insert(j+1);
            }
            if(0<j and contains(&porns,i+1,j-1)){
                now.insert(j-1);
            }
        }
    }
    cout<<now.size()<<endl;
    return 0;
}