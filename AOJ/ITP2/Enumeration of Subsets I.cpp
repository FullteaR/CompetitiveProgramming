#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

void enu(long i, int n);

int main(void){
  int n;
  cin>>n;
  for(long i=0;i<pow(2,n);i++){
    enu(i,n);
  }
}


void enu(long i, int n){
  printf("%ld:",i);
  long j=0;
  while(i>0){
    if(i%2==1){
      printf(" %ld",j);
    }
    i=i/2;
    j++;
  }
  printf("\n");
}
