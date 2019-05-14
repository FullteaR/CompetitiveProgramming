#include <iostream>
using namespace std;

long GCD(long a,long b);

int main(void){
    long a,b;
    long gcd,lcm;
    while(cin>>a>>b){
        gcd=GCD(a,b);
        lcm=a*b/gcd;
        cout<<gcd<<" "<<lcm<<endl;
    }
    return 0;
}


long GCD(long a,long b){
    if(min(a,b)==0){return max(a,b);}
    return GCD(min(a,b),max(a,b)%min(a,b));
}
