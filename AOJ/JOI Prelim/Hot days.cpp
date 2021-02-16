#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>
#define INF 1000000100
using namespace std;

void dijkstra(set<long> * v, map<pair<long, long>,long> * mp, long N, long total,vector<long>* retval);

class Cloth {
private:
long a;
long b;
long c;
public:
Cloth(long a, long b, long c);
bool is_wearable(long T);
long distance(Cloth * cloth);
};

Cloth::Cloth(long _a, long _b, long _c){
        a=_a;
        b=_b;
        c=_c;
}

bool Cloth::is_wearable(long T){
        if(a<=T and T<=b) {
                return true;
        }
        else{
                return false;
        }
}

long Cloth::distance(Cloth* cloth){
        return abs(c-cloth->c);
}

int main(void){
        long D,N;
        cin>>D>>N;
        vector<long> temperatures;
        vector<Cloth> clothes;
        for(long i=0; i<D; i++) {
                long temp;
                cin>>temp;
                temperatures.push_back(temp);
        }
        for(long i=0; i<N; i++) {
                long a,b,c;
                cin>>a>>b>>c;
                Cloth C = Cloth(a,b,c);
                clothes.push_back(C);
        }
        set<long>* v = new set<long> [D*N];
        map<pair<long,long>, long> mp;
        for(long i=0; i<D*N; i++) {
                v[i].clear();
        }


        for(long i=0; i<D-1; i++) {
                for(long j=0; j<N; j++) {
                        if(!(clothes[j].is_wearable(temperatures[i]))) {
                                continue;
                        }
                        for(long k=0; k<N; k++) {
                                if(!(clothes[k].is_wearable(temperatures[i+1]))) {
                                        continue;
                                }
                                v[i*N+j].insert((i+1)*N+k);

                                mp[make_pair(i*N+j,(i+1)*N+k)] = clothes[j].distance(&(clothes[k]));
                        }
                }
        }
        vector<long> retval;
        dijkstra(v, &mp, N, N*D, &retval);
        long ans=0;
        for(long i=0; i<N; i++) {
                ans = max(ans, retval[N*D-i-1]);
        }

        cout<<ans<<endl;
        return 0;
}

void dijkstra(set<long> * v, map<pair<long, long>,long> * mp, long N, long total,vector<long>* retval){
        retval->clear();
        for(long i=0; i<total; i++) {
                retval->push_back(-1*INF);
        }
        for(long i=0; i<N; i++) {
                (*retval)[i]=0;
        }
        set<long> updated, next;
        updated.clear();
        for(int i=0; i<N; i++) {
                updated.insert(i);
        }
        while(!updated.empty()) {
                next.clear();
                for(auto iter=updated.begin(); iter!=updated.end(); iter++) {
                        for(auto iter2=v[*iter].begin(); iter2!=v[*iter].end(); iter2++) {
                                long weight=(*mp)[make_pair(*iter,*iter2)];
                                if((*retval)[*iter2]<(*retval)[*iter]+weight) {
                                        (*retval)[*iter2]=(*retval)[*iter]+weight;
                                        next.insert(*iter2);
                                }
                        }
                }
                updated.swap(next);
        }
}
