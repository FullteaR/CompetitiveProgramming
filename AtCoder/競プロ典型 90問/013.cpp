#include <iostream>
#include <set>
#include <map>
#define INF 1000000010
using namespace std;

//dijkstra search
/*
   入力
   v: 隣接要素のsetを持つmap。v[i]は頂点iから行くことができる頂点を集めたset。
   mp: 辺の重みを参照 mp[make_pair(i,j)]で辺i->jの重みを取得できる。
   s: スタート
   retval: 各頂点のスタートからの最短距離が格納されるmap。
 */

void dijkstra(map<long long, set<long long> > * v, map<pair<long long, long long>,long long> * mp, long long s, map<long long, long long>* retval);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, M;
    cin>>N>>M;
    map<long long, set<long long> > v;
    map<pair<long long,long long>, long long> mp;
    mp.clear();
    v.clear();
    for(long n=0;n<N;n++){
        v[n].clear();
    }
    for(long m=0;m<M;m++){
        long long A,B,C;
        cin>>A>>B>>C;
        A--;
        B--;
        v[A].insert(B);
        v[B].insert(A);
        mp[make_pair(A,B)]=C;
        mp[make_pair(B,A)]=C;
    }
    map<long long, long long> dist_1_k;
    map<long long, long long> dist_N_k;
    dijkstra(&v, &mp, 0, &dist_1_k);
    dijkstra(&v, &mp, N-1, &dist_N_k);
    for(long k=0;k<N;k++){
        cout<<dist_1_k[k]+dist_N_k[k]<<endl;
    }
}

void dijkstra(map<long long, set<long long> > * v, map<pair<long long, long long>,long long> * mp, long long s, map<long long, long long>* retval){
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
                                long long weight=(*mp)[make_pair(*iter,*iter2)];
                                if((*retval)[*iter2]>(*retval)[*iter]+weight) {
                                        (*retval)[*iter2]=(*retval)[*iter]+weight;
                                        next.insert(*iter2);
                                }
                        }
                }
                updated.swap(next);
        }
}