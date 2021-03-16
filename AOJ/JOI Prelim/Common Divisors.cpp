#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
  int n;
  cin>>n;
  if(n==2){
    long a,b;
    cin>>a>>b;
    for(long i=1;i<100000010;i++){
      if(a%i==0 and b%i==0){
        printf("%ld\n",i);
      }
    }
  }
  if(n==3){
    long a,b,c;
    cin>>a>>b>>c;
    for(long i=1;i<100000010;i++){
      if(a%i==0 and b%i==0 and c%i==0){
        printf("%ld\n",i);
      }
    }
  }
  return 0;
}
