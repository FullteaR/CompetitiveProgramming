#include <iostream>
using namespace std;

int main(void){
    int h1,h2;
    cin>>h1>>h2;
    int k1,k2;
    cin>>k1>>k2;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int hs=a*h1+b*h2+(h1/10)*c+(h2/20)*d;
    int ks=a*k1+b*k2+(k1/10)*c+(k2/20)*d;
    if(hs<ks){
        cout<<"kenjiro"<<endl;
    }
    else if(hs>ks){
        cout<<"hiroshi"<<endl;
    }
    else{
        cout<<"even"<<endl;
    }
    return 0;
}