#include <iostream>
using namespace std;

long convert(long n);

int main(void){
  long n;
  while(1){
    cin>>n;
    if(n==-1)break;
    cout<<convert(n)<<endl;
  }
  return 0;
}

long convert(long n){
  long base=1;
  long retval=0;
  while(n>0){
    retval+=base*(n%4);
    base*=10;
    n=n/4;
  }
  return retval;
}
