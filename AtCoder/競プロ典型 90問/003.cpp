#include <iostream>
#include <map>
#include <set>
using namespace std;
#define INF 1000000010

pair<long, long> longest(long start, map<long, set<long> > &dist, long N);
void dijkstra(map<long, set<long> > *v, long s, map<long, long>* retval);

int main(void) {
    long N;
    cin>>N;
    map<long, set<long> > dist;
    for(long i=0;i<N;i++){
        dist[i].clear();
    }
    for(long i=0;i<N-1;i++){
        long A,B;
        cin>>A>>B;
        A--;
        B--;
        (dist[A]).insert(B);
        (dist[B]).insert(A);
    }

    long edge = longest(0, dist, N).second;
    long d = longest(edge, dist, N).first;
    cout<<d+1<<endl;

    return 0;
}


pair<long, long> longest(long start, map<long, set<long> > &dist, long N) {
    map<long, long> retval;
    dijkstra(&dist, start, &retval);
    long r = 0;
    long g = start;
    for(long i=0;i<N;i++) {
        if(retval[i]>r) {
            r = retval[i];
            g = i;
        }
    }
    return make_pair(r, g);
}

void dijkstra(map<long, set<long> > *v, long s, map<long, long>* retval){
        retval->clear();
        for(auto iter = v->begin(); iter != v->end(); iter++) {
                (*retval)[iter->first]=INF;
        }
        (*retval)[s]=0;
        set<long> updated, next;
        updated.clear();
        updated.insert(s);
        while(!updated.empty()) {
                next.clear();
                for(auto iter=updated.begin(); iter!=updated.end(); iter++) {
                        for(auto iter2=(*v)[*iter].begin(); iter2!=(*v)[*iter].end(); iter2++) {
                                long weight = 1;
                                if((*retval)[*iter2]>(*retval)[*iter]+weight) {
                                        (*retval)[*iter2]=(*retval)[*iter]+weight;
                                        next.insert(*iter2);
                                }
                        }
                }
                updated.swap(next);
        }
}