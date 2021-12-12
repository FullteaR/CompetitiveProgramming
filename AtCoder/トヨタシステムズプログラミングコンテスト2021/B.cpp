#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
#define INF 10000000010

void dijkstra(map<long long, set<long long> > * v, long long s, map<long long, long long>* retval);

int main(void){
    long long N,X;
    cin>>N>>X;
    map<long long, set<long long> > v;
    v.clear();
    for(long long i=0;i<N;i++){
        v[i].clear();
    }
    for(long long i=0;i<N;i++){
        long long A;
        cin>>A;
        v[i].insert(A-1);
    }
    map<long long, long long> retval;

    dijkstra(&v, X-1, &retval);
    long long ret=0;
    for(long long i=0;i<N;i++){
        long long dist = retval[i];
        if(dist<INF){
            ret++;
        }
    }
    cout<<ret<<endl;
    return 0;
}

void dijkstra(map<long long, set<long long> > * v, long long s, map<long long, long long>* retval){
        retval->clear();
        for(auto iter = v->begin(); iter != v->end(); iter++) {
                (*retval)[iter->first]=INF;
        }
        (*retval)[s]=0;
        set<long long> updated, next;
        updated.clear();
        updated.insert(s);
        while(!updated.empty()) {
                next.clear();
                for(auto iter=updated.begin(); iter!=updated.end(); iter++) {
                        for(auto iter2=(*v)[*iter].begin(); iter2!=(*v)[*iter].end(); iter2++) {
                                long long weight=1;
                                if((*retval)[*iter2]>(*retval)[*iter]+weight) {
                                        (*retval)[*iter2]=(*retval)[*iter]+weight;
                                        next.insert(*iter2);
                                }
                        }
                }
                updated.swap(next);
        }
}