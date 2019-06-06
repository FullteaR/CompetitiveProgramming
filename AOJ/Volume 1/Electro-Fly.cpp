#include <iostream>
using namespace std;
long GCD(long a,long b);
long LCM(long a,long b);
long fly(long a,long m,long p);

int main(void){
        int a1,m1,a2,m2,a3,m3;
        while(1) {
                cin>>a1>>m1>>a2>>m2>>a3>>m3;
                if (a1==0 and m1==0 and a2==0 and m2==0 and a3==0 and m3==0) {return 0;}
                long x,y,z;
                x=fly(a1,m1,a1%m1)+1;
                y=fly(a2,m2,a2%m2)+1;
                z=fly(a3,m3,a3%m3)+1;
                cout<<LCM(x,LCM(y,z))<<endl;

        }
}

long GCD(long a,long b){
    long A,B;
    A=min(a,b);
    B=max(a,b);
    if(A==0){return B;}
    else{
        return GCD(A,B%A);
    }
}
long LCM(long a,long b){
    return a*b/GCD(a,b);
}
long fly(long a,long m,long p){
    if(p==1){return 0;}
    else{
        return fly(a,m,(a*p)%m)+1;
    }
}
