#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdio>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;

struct wall{
    long L;
    long R;
    long n;
    bool exist;

}typedef wall;

bool compL(wall *w1, wall *w2);
bool compR(wall *w1, wall *w2);

int main(void){
    long N,D;
    cin>>N>>D;
    vector<wall> walls;
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for(long i=0;i<N;i++){
        long L,R;
        scanf("%ld %ld",&L,&R);
        wall w;
        w.L = L;
        w.R = R;
        w.n = i;
        w.exist = true;

        walls.push_back(w);
    }

    vector<wall*> walls_oreder_by_L, walls_oreder_by_R;
    walls_oreder_by_L.clear();
    walls_oreder_by_R.clear();
    for(long i=0;i<N;i++){
        walls_oreder_by_L.push_back(&(walls[i]));
        walls_oreder_by_R.push_back(&(walls[i]));
    }
    sort(walls_oreder_by_L.begin(), walls_oreder_by_L.end(), compL);
    sort(walls_oreder_by_R.begin(), walls_oreder_by_R.end(), compR);
    long retval = 0;
    long walls_counts = N;
    for(long i=0;i<N;i++){
        wall* w_base = walls_oreder_by_R[i];
        if(w_base->exist == false){
            continue;
        }
        long L,R;
        L = w_base->L;
        R = w_base->R;
        w_base->exist=false;
        walls_counts--;
        retval++;
        for(long i=0;i<N;i++){
            wall* w = walls_oreder_by_L[i];
            if(w->L > R+D-1){
                break;
            }
            if(w->exist == false or w->R<R){
                continue;
            }
            w->exist=false;
            walls_counts--;

        }
        if(walls_counts==0){
            cout<<retval<<endl;
            return 0;
        }
    }
    cout<<retval<<endl;
    return 0;
}

bool compL(wall *w1, wall *w2){
    return w1->L < w2->L;
}
bool compR(wall *w1, wall *w2){
    return w1->R < w2->R;
}
