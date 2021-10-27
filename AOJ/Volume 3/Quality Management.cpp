#include <iostream>
#include <utility>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    long C,N;
    cin>>C>>N;
    string* p = new string [N];
    for(long i=0;i<N;i++){
        cin>>p[i];
    }
    set<pair<long,long> > ud, lr;
    ud.clear();
    lr.clear();

    for(long i=0;i<N/2;i++){
        for(long j=0;j<N;j++){
            if(p[i][j]!=p[N-i-1][j]){
                ud.insert(make_pair(i,j));
            }
        }
    }
    for(long i=0;i<N;i++){
        for(long j=0;j<N/2;j++){
            if(p[i][j]!=p[i][N-1-j]){
                lr.insert(make_pair(i,j));
            }
        }
    }
    long retval;
    if(ud.empty() and lr.empty()){
        retval=1;
    }
    else{
        retval=0;
    }
    for(long i=0;i<C-1;i++){
        long D;
        cin>>D;
        for(long j=0;j<D;j++){
            long r,c;
            cin>>r>>c;
            pair<long,long> changeud, changelr;
            r--;
            c--;
            changeud = make_pair(min(N-1-r,r),c);
            if(ud.find(changeud)==ud.end()){
                ud.insert(changeud);
            }
            else{
                ud.erase(changeud);
            }
            changelr = make_pair(r,min(N-1-c,c));
            if(lr.find(changelr)==lr.end()){
                lr.insert(changelr);
            }
            else{
                lr.erase(changelr);
            }
        }
        if(ud.empty() and lr.empty()){
            retval++;
        }
    }
    cout<<retval<<endl;
    return 0;
}