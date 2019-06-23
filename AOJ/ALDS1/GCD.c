#include <stdio.h>

int gcd(int a,int b);

int main(void){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",gcd(a,b));
}

int gcd(int a,int b){
    int m,M;
    if(a<=b){
        m=a;
        M=b;
    }
    else{
        m=b;
        M=a;
    }
    if(m==0){
        return M;
    }
    else{
        return gcd(m,M%m);
    }
}
