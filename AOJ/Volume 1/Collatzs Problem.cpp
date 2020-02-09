#include <iostream>
using namespace std;

int collatz(int n);

int main(void){
  int n;
  while(1){
    cin>>n;
    if(n==0)break;
    cout<<collatz(n)<<endl;
  }
  return 0;
}

int collatz(int n){
  int retval=0;
  while(n!=1){
    if(n%2==0){
      n=n/2;
    }
    else{
      n=3*n+1;
    }
    retval+=1;
  }
  return retval;
}
