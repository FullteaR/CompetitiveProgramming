#include <iostream>
#include <cmath>
using namespace std;

long long convert(long long n, long long k);

int main(void){
    long long K;
    long long A,B;
    cin>>K;
    cin>>A>>B;
    cout<<convert(A,K)*convert(B,K)<<endl;
    return 0;
}

long long convert(long long n, long long k){
    long long retval=0;
    long long i=0;
    while(n!=0){
        retval+=pow(k,i)*(n%10);
        n=n/10;
        i++;
    }
    return retval;
}