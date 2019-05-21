#include <cmath>
#include <stdio.h>
using namespace std;

int main(void){
        double p=0.0;
        long long N,K;
        scanf("%lld %lld",&N,&K,stdin);
        long long kaisuu;
        for(long long i=1; i<=N; i++) {
                kaisuu=fmax((int)ceil(log(K/(double)i)/log(2)),0);
                p+=pow(0.5,kaisuu)/N;
        }
        printf("%.10lf",p);
        return 0;
}
