#include <stdio.h>

int main(void){
  int n;
  int retval;
  while(1){
    scanf("%d",&n);
    if(n==0)break;
    retval=0;
    while(n>0){
      n=n/5;
      retval+=n;
    }
    printf("%d\n",retval);
  }
  return 0;
}
