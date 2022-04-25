#include <iostream>
#include <map>
using namespace std;

struct Point{
    long x;
    long y;
}typedef Point;

long gcd(long a, long b){
    if(min(a,b)==0){
        return max(a,b);
    }
    return gcd(min(a,b), max(a,b)%min(a,b));
}


int main(void){
    long N,K;
    cin>>N>>K;
    if(K==1){
        cout<<"Infinity"<<endl;
        return 0;
    }
    Point* points = new Point[N];
    for(long i=0;i<N;i++){
        long x,y;
        cin>>x>>y;
        points[i].x=x;
        points[i].y=y;
    }
    map<long, long> retval;
    retval.clear();
    for(long n=K;n<=N;n++){
        retval[n] = 0;
    }
    for(long i=0;i<N;i++){
        for(long j=i+1;j<N;j++){
            Point p1 = points[i];
            Point p2 = points[j];
            long count = 0;
            for(long k=0;k<N;k++){
                Point p3 = points[k];
                if((p2.x-p1.x)*(p3.y-p1.y) == (p2.y-p1.y)*(p3.x-p1.x)){
                    count++;
                }
            }
            if(count>=K){
                retval[count]+=1;
            }
        }
    }
    long _retval = 0;
    for(long k=K;k<=N;k++){
        _retval += retval[k]*2/(k*(k-1));
    }
    cout<<_retval<<endl;
}