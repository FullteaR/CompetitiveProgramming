#include <iostream>
using namespace std;

int main(void){
    int N,K,A;
    cin>>N>>K>>A;
    cout<<(K+A-2)%N+1<<endl;
    return 0;
}