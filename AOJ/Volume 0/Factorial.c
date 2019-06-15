#include <stdio.h>

long long fact(long long n);

int main(void){
    long long n;
    scanf("%lld",&n);
    printf("%lld\n",fact(n));
    return 0;
}

long long fact(long long n){
    if(n==1) return 1;
    return n*fact(n-1);
}
