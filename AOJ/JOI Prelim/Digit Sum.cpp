#include <iostream>
#define SIZE 1000010
using namespace std;

long convert(long n);

int main(void){
  long N;
  cin>>N;
  long* table = new long[SIZE+100];
  for(long i=0;i<SIZE;i++){
    table[i]=1;
  }
  for(long i=0;i<SIZE;i++){
    table[convert(i)]+=table[i];
  }
  cout<<table[N]<<endl;
  return 0;
}

long convert(long n){
  long retval = n;
  while(n>0){
    retval+=n%10;
    n=n/10;
  }
  return retval;
}
