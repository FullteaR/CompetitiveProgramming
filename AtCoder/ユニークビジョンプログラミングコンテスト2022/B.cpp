#include <iostream>
using namespace std;

int main(void){
    long A,B,K;
    cin>>A>>B>>K;
    int count = 0;
    while(A<B){
        count++;
        A*=K;
    }
    cout<<count<<endl;
}