#include <iostream>
#include <cmath>
using namespace std;

long pow(long a, long b);

int main(void) {
    long a,b,c;
    cin>>a>>b>>c;
    // log2(a) < b*log2(c) <--> a < c**b
    if(a<pow(c,b)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}

long pow(long a, long b){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        return pow(a, b/2)*pow(a, b/2);
    }
    else{
        return a*pow(a, b-1);
    }
}