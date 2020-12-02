#include <iostream>
#include <algorithm>
#define INF 10000100
using namespace std;

long rotR(long s1, long s2, long N);
long rotL(long s1, long s2, long N);
int main(void){
        long N,M,p;
        cin>>N>>M>>p;
        long* d = new long[M];
        for(int i=0; i<M; i++) {
                cin>>d[i];
        }
        sort(d,d+M);
        long retval = INF;
        for(int i=0; i<M; i++) {
                long distanceLR = 0;
                distanceLR += rotL(p,d[i], N) + rotR(d[i],d[(i-1)%M], N);
                retval = min(retval, distanceLR);
                long distanceRL = 0;
                distanceRL+=rotR(p,d[i], N) + rotL(d[i],d[(i+1)%M], N);
                retval = min(retval, distanceRL);
        }
        if(p<d[0]) {
                retval = min(retval,rotR(p,d[M-1],N));
                retval = min(retval,rotL(p,d[0],N));
        }
        else if(d[M-1]<p) {
                retval = min(retval,rotR(p,d[M-1],N));
                retval = min(retval,rotL(p,d[0],N));
        }
        else{
                for(int i=0; i<M-1; i++) {
                        if(d[i]<p and p<d[i+1]) {
                                retval = min(retval,rotR(p,d[i],N));
                                retval = min(retval,rotL(p,d[i+1],N));
                        }
                }
        }
        cout<<retval<<endl;
        return 0;
}

long rotR(long s1, long s2, long N){
        if(s2>s1) {
                return (s2-s1)*100;
        }
        else{
                return (s2+N-s1)*100;
        }
}
long rotL(long s1, long s2, long N){
        if(s1>s2) {
                return (s1-s2)*100;
        }
        else{
                return (s1+N-s2)*100;
        }
}
