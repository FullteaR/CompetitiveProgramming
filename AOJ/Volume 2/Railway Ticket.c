#include <stdio.h>

int main(void){
  int b1,b2,b3;
  scanf("%d %d %d",&b1,&b2,&b3);
  if(b1==1 && b2==1){
    printf("Open\n");
  }
  else if(b3==1){
    printf("Open\n");
  }
  else{
    printf("Close\n");
  }
  return 0;
}
