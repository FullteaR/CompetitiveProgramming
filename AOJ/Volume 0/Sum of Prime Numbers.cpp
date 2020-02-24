#include <iostream>
#include <stdlib.h>
using namespace std;
#define limit 104750

int main(void){
  int* table=(int*)malloc(sizeof(int)*limit);
  for(int i=0;i<limit;i++){
    table[i]=1;
  }
  table[0]=0;
  table[1]=0;
  int k;
  for(int i=0;i<limit;i++){
    if(table[i]==0)continue;
      k=2;
      while(k*i<=limit){
        table[k*i]=0;
        k++;
      }
  }
  int n;
  int i,retval,counter;
  while(1){
    cin>>n;
    if(n==0){
      break;
    }
    i=0;
    retval=0;
    counter=0;
    while(counter<n){
      if(table[i]==1){
        retval+=i;
        counter++;
      }
      i++;
    }
    cout<<retval<<endl;
  }
  return 0;
}
