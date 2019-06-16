#include <iostream>
#include <math.h>
using namespace std;

int main(void){
    double v;
    double h;
    double N;
    while(cin>>v){
        h=v*v/(2*9.8);
        N=h/5+1;
        cout<<ceil(N)<<endl;
    }
    return 0;
}
