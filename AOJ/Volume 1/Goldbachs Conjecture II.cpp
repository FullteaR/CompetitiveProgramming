//1のソースコードをコピペしたら通りましたが...

#include <iostream>
#include <stdlib.h>
using namespace std;
#define limit 1000010

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
  while(1){
    cin>>n;
    if(n==0)break;
    int retval=0;
    for(int i=1;i<=n/2;i++){
      if(table[i]==1 && table[n-i]==1){
        retval++;
      }
    }
    cout<<retval<<endl;
  }

  return 0;
}
