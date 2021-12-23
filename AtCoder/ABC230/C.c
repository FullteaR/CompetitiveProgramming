#include <stdio.h>

char check(long long x, long long y, long long A, long long B, long long N);
long long max(long long A, long long B);
long long min(long long A, long long B);

int main(void){
    long long N,A,B;
    long long P,Q,R,S;
    scanf("%lld %lld %lld", &N, &A, &B);
    scanf("%lld %lld %lld %lld", &P, &Q, &R, &S);
    for(long long i=P;i<=Q;i++){
        for(long long j=R;j<=S;j++){
            printf("%c", check(i, j, A, B, N));
        }
        printf("\n");
    }
}

char check(long long x, long long y, long long A, long long B, long long N){
    long long k;
    if(B-A == y-x){
        k = x - A;
        if(max(1-A,1-B)<=k & k<=min(N-A, N-B)){
            return '#';
        }
    }
    if(A+B == x+y){
        k = x - A;
        if(max(1-A, B-N)<=k & k<=min(N-A,B-1)){
            return '#';
        }
    }

    return '.';
}

long long max(long long A, long long B){
    if(A<B){
        return B;
    }
    else{
        return A;
    }
}
long long min(long long A, long long B){
    if(A<B){
        return A;
    }
    else{
        return B;
    }
}