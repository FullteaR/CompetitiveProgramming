#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main(void){
  long long S;
  cin>>S;
  if(S==1000000000000000000){
    printf("0 0 1000000000 0 0 1000000000\n");
  }
  else{
  long long s = (long long)sqrt(S);
  printf("0 0 %lld %lld 1 %lld\n",s+1,(s+1)*(s+1)-S,s+1);
}
return 0;
}
