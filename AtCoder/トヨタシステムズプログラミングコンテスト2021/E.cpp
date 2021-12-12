#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;
using namespace std;
#define MOD 998244353

Bint pow(Bint a, Bint b, Bint mod);


int main(void){
    Bint N,K,M;
    cin>>N>>K>>M;
    if(M%MOD==0){
        cout<<0<<endl;
        return 0;
    }
    //cout<<M**(K**N)<<endl;
    //M**(K**N) % MOD = M**(K**N %(MOD-1)) %MOD
    Bint e = pow(K,N,MOD-1);
    cout<<pow(M,e,MOD)<<endl;
    return 0;
}

Bint pow(Bint a, Bint b, Bint mod){
    if(b==0){
        return 1;
    }
    else if(b%2==1){
        return (a*pow(a,b-1,mod))%mod;
    }
    else{
        Bint d = pow(a, b/2, mod);
        return (d*d)%mod;
    }
}