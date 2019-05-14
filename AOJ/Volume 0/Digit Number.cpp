#include <iostream>
using namespace std;

int digit(int n){
        int digit=0;
        while(n>0) {
                digit+=1;
                n=n/10;
        }
        return digit;
}

int main(void){
        int a,b;
        while(cin>>a>>b) {
                cout<<digit(a+b)<<endl;
        }
        return 0;
}
