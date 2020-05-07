#include <iostream>
#include <stdlib.h>
using namespace std;

long _change(long n);
long change(long n);


int main(void){
  long n;
  cin>>n;
  cout<<change(n)<<endl;
  return 0;
}

long _change(long n){
  long retval=0;
  retval+=n/10;
  n=n%10;
  retval+=n/5;
  n=n%5;
  retval+=n;
  return retval;
}

long change(long n){
  long retval=10000000010;
  long count=0;
  while(n>=0){
    retval=min(retval,_change(n)+count);
    n-=25;
    count++;
  }
  return retval;
}
