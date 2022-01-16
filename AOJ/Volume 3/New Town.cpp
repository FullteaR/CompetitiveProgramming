#include <iostream>
using namespace std;

int gcd(int a, int b);

int main(void){
    int W,H,C;
    cin>>W>>H>>C;
    int g = gcd(W,H);
    cout<<(W/g)*(H/g)*C<<endl;
    return 0;
}

int gcd(int a, int b){
    if(min(a,b)==0){
        return max(a,b);
    }
    return gcd(min(a,b), max(a,b)%min(a,b));
}
