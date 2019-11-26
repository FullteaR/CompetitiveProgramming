#include <iostream>
#include <algorithm>
using namespace std;

int d(long N);
long long price(long N,long A,long B);

int main(void){
  long A,B;
  long long X;
  cin>>A>>B>>X;
  long u,d,mid;
  d=-10;
  u=10000000010;
  while(u-d>5){
    mid=(u+d)/2;
    if(price(mid,A,B)<X){
      d=mid;
    }
    else{
      u=mid;
    }
  }
  long max=d;
  for(long i=d-100;i<u+100;i++){
    if(price(i,A,B)<=X){
      max=i;
    }
  }
  if(max>1000000000){
    max=1000000000;
  }
  if(max<0){
    max=0;
  }
  cout<<max<<endl;
  return 0;
}


int d(long N){
  int retval=0;
  for(int i=0;i<20;i++){
    retval+=(N>0);
    N=N/10;
  }
  return retval;
}
long long price(long N,long A,long B){
  return N*A+B*d(N);
}
