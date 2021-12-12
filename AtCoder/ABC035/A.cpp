#include <iostream>
using namespace std;
int gcd(int a, int b);

int main(void){
    int W, H;
    cin>>W>>H;
    int g = gcd(W,H);
    if(W/g==16){
        cout<<"16:9"<<endl;
    }
    else{
        cout<<"4:3"<<endl;
    }
    return 0;
}

int gcd(int a, int b){
    int m = min(a,b);
    int M = max(a,b);
    if(m==0){return M;};
    return gcd(m, M%m);
}