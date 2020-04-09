#include <iostream>
using namespace std;

long convert(long n);

int main(void){
  long n;
  while(true){
    cin>>n;
    if(n==0)break;
    cout<<convert(n)<<endl;
  }
  return 0;
}

long convert(long n){
  long order=1;
  long retval=0;
  while(n>0){
    int mod=n%8;
    if(mod>=5){
      mod+=2;
    }
    else if(mod>=4){
      mod+=1;
    }
    retval+=order*mod;
    n=n/8;
    order=order*10;
  }
  return retval;
}
