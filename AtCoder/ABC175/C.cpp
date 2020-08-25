#include <iostream>
#define INF 10000000000000100
using namespace std;

int main(void){
  long long X,K,D;
  cin>>X>>K>>D;

  long long a = K/2 - (X/D)/2;

  long long retval=INF;
  for(long long i=-10;i<10;i++){
    long long _a = a+i;
    long long _b=K-_a;
    if(_a>=0 and _b>=0){
      retval=min(abs(X+_a*D-_b*D), retval);
    }
  }
  if(retval==INF){
    retval=min(abs(X+K*D),abs(X-K*D));
  }
  cout<<retval<<endl;

  return 0;
}
