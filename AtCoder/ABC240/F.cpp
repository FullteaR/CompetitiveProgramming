#include <iostream>
#include <cstdio>
#include <vector>
#define INF 3000000002000000000
using namespace std;

int main(void){
    long T;
    cin>>T;
    for(long t=0;t<T;t++){
        long N, M;
        cin>>N>>M;
        long retval = -1*INF;
        long value = 0;
        long plus = 0;
        for(long i=0;i<N;i++){
            long x, y;
            scanf("%ld %ld", &x, &y);
            retval = max(retval, value+plus+x);
            value += plus*y + y*(y+1)*x/2;
            retval = max(retval, value);
            plus+=x*y;
        }
        printf("%ld\n", retval);
    }
}