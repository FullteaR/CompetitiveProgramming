#include <stdio.h>

long long gcd(long long a, long long b);

int main(void){
    long long A,B,C,D;
    scanf("%lld %lld %lld %lld",&A,&B,&C,&D);
    long long LCM=C*D/gcd(C,D);
    long long  retval = B-A-(B/C + B/D - B/LCM - ((A-1)/C+(A-1)/D - (A-1)/LCM))+1;
    printf("%lld\n",retval);
}

long long gcd(long long a, long long b){
    long long m,M;
    if(a>=b){
        m=b;
        M=a;
    }
    else{
        m=a;
        M=b;
    }
    if(m==0){return M;}
    else{return gcd(m,M%m);}
}
