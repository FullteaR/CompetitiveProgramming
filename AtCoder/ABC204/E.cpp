#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <cassert>

using namespace std;
#define INF 4000000000000000001

long long sqrt(long long x){
    long long m=0;
    long long M=x;
    while(M-m>1){
        long long mid=(M+m)/2;
        if(mid*mid>x){
            M=mid;
        }
        else{
            m=mid;
        }
    }
    if((m+1)*(m+1)==x){
        return m+1;
    }
    assert(m*m<=x and x<(m+1)*(m+1));
    return m;
}

long long get_weight(long long time, long long C, long long D){
    long long retval=C+D/(time+1);
    long long wait = sqrt(D) - (time+1);
    for(long long i=-1;i<=1;i++){
        if(wait+i>=0){
            retval=min(C+D/(time+1+wait+i)+wait+i, retval);
        }
    }
    return retval;
}

void dijkstra(map<long long, unordered_set<long long> > * v, map<pair<long long, long long>, set<pair<long long, long long> > >* mp, long long s, unordered_map<long long, long long>* retval){
        retval->clear();
        for(auto iter = v->begin(); iter != v->end(); iter++) {
                (*retval)[iter->first]=INF;
        }
        (*retval)[s]=0;
        unordered_set<long long> updated, next;
        updated.clear();
        updated.insert(s);
        while(!updated.empty()) {
                next.clear();
                for(auto iter=updated.begin(); iter!=updated.end(); iter++) {
                        long long time = (*retval)[*iter];
                        for(auto iter2=(*v)[*iter].begin(); iter2!=(*v)[*iter].end(); iter2++) {
                                for(auto iter3=(*mp)[make_pair(*iter,*iter2)].begin();iter3!=(*mp)[make_pair(*iter,*iter2)].end();iter3++){
                                    long long weight = get_weight(time, iter3->first, iter3->second);
                                    if((*retval)[*iter2]>(*retval)[*iter]+weight) {
                                        (*retval)[*iter2]=(*retval)[*iter]+weight;
                                        next.insert(*iter2);
                                    }
                                }
                        }
                }
                updated.swap(next);
        }
}

int main(void){
    long long N,M;
    cin>>N>>M;
    map<pair<long long, long long>, set<pair<long long, long long> > > mp;
    mp.clear();
    map<long long, unordered_set<long long> > v;
    v.clear();
    for(long long i=0;i<N;i++){
        v[i].clear();
    }
    for(long long i=0;i<M;i++){
        long long A,B,C,D;
        scanf("%lld %lld %lld %lld",&A,&B,&C,&D);
        A--;
        B--;
        mp[make_pair(A,B)].insert(make_pair(C,D));
        v[A].insert(B);
        v[B].insert(A);
    }
    unordered_map<long long, long long> retval;
    dijkstra(&v,&mp,0,&retval);
    if(retval[N-1]==INF){
        cout<<-1<<endl;
    }
    else{
        cout<<retval[N-1]<<endl;
    }
    return 0;
}