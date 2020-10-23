#include <stdio.h>

int main(void){
  int retval=0;
  for(int i=0;i<10;i++){
    int s;
    scanf("%d",&s);
    retval+=s;
  }
  printf("%d\n",retval);
  return 0;
}
