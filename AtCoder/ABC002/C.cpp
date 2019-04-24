#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int xa,ya,xb,yb,xc,yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    xb=xb-xa;
    xc=xc-xa;
    yb=yb-ya;
    yc=yc-ya;
    cout<<fixed<<(abs(xb*yc-xc*yb))/2.0<<endl;//fuckin!
    return 0;
}
