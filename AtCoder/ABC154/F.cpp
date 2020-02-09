#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define sizes 1000005

long inv(long x){
  long res=1;
  long k=mod-2;
  long y=x;
  while(k){
    if(k&1) res=(res*y)%mod;
    y=(y*y)%mod;
    k/=2;
  }
  return res;
}





int main(void){
  long* f;
  f=(long*)malloc(sizeof(long)*sizes*2+10);
  f[0]=1;
  for(int i=1;i<sizes*2+10;i++){
    f[i]=(f[i-1]*i)%mod;
  }
  long r1,c1,r2,c2;
  cin>>r1>>c1>>r2>>c2;


  long retval=0;
  long c;
  long* invs;
  invs=(long*)malloc(sizeof(long)*sizes);
  invs[sizes-1]=inv(f[sizes-1]);
  for(long i=sizes-2;i>=min(r1,c1)-1;i--){
    invs[i]=(invs[i+1]*(i+1))%mod;
  }
  for(long i=r1;i<=r2;i++){
    for(long j=c1;j<=c2;j++){
      c=(f[i+j]*invs[i])%mod;
      c*=invs[j];
      c=c%mod;
      retval+=c;
      retval=retval%mod;
    }
  }
  cout<<retval%mod<<endl;
  return 0;
}
