#include <iostream>
#include <cassert>
using namespace std;

long log2(long n);
long railway(long s, long d, long* pow2);

int main(void){
  int N;
  cin>>N;
  long* pow2=new long[36];
  pow2[0]=1;
  for(int i=1;i<36;i++){
    pow2[i] = pow2[i-1]*2;
    assert(pow2[i]>0);
  }
  for(int i=0;i<N;i++){
    long s,d;
    cin>>s>>d;
    cout<<railway(s,d,pow2)<<endl;
  }
  return 0;
}


long railway(long s, long d, long* pow2){
  assert(s<=d);
  if(s==d){return 0;}
  long n=log2(s);
  while(pow2[n]+s>d){
    n--;
  }
  return 1+railway(s+pow2[n],d, pow2);
}


long log2(long n){
  if(n==0){return 35;/*50 means inf cuz d<2**50*/}
  long retval=0;
  while(n%2==0){
    retval++;
    n=n/2;
  }
  return retval;
}
