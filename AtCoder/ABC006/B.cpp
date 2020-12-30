#include <iostream>
using namespace std;
#define mod 10007

int main(void){
  long* a = new long[1000100];
  a[0]=1;
  a[1]=0;
  a[2]=0;
  a[3]=1;
  for(long i=4;i<1000100;i++){
    a[i]=(a[i-1]+a[i-2]+a[i-3])%mod;
  }
  long n;
  cin>>n;
  cout<<a[n]%mod<<endl;

  return 0;
}
