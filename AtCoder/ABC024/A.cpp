#include <iostream>
using namespace std;

int main(void){
  long A,B,C,K,S,T;
  cin>>A>>B>>C>>K;
  cin>>S>>T;
  long fee=S*A+T*B;
  if(S+T>=K){
    fee-=(S+T)*C;
  }
  cout<<fee<<endl;
  return 0;
}
