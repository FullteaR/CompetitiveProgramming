#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){
  int N,K;
  cin>>N>>K;
  double E[N];
  double p;
  for(int i=0;i<N;i++){
    cin>>p;
    E[i]=(p+1.0)/2;
  }
  double s=0;
  for(int i=0;i<K;i++){
    s+=E[i];
  }
  double retval=s;
  for(int i=0;i<N-K;i++){
    s-=E[i];
    s+=E[i+K];
    retval=max(s,retval);
  }
  printf("%.16f\n",retval);
  return 0;
}
