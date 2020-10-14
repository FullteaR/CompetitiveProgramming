#include <stdio.h>

int main(void){
  while(1){
    long t,n;
    scanf("%ld",&t);
    if(t==0){
      break;
    }
    scanf("%ld",&n);
    for(int i=0;i<n;i++){
      long s,f;
      scanf("%ld %ld",&s,&f);
      t-=(f-s);
    }
    if(t<=0){
      printf("OK\n");
    }
    else{
      printf("%ld\n",t);
    }
  }
  return 0;
}
