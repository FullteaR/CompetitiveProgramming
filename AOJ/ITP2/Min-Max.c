#include <stdio.h>

int main(void){
  int a,b,c;
  int min,max;
  scanf("%d %d %d",&a,&b,&c);
  if(a<=b && b<=c){
    min=a;
    max=c;
  }
  else if(a<=c && c<=b){
    min=a;
    max=b;
  }
  else if(b<=a && a<=c){
    min=b;
    max=c;
  }
  else if(b<=c && c<=a){
    min=b;
    max=a;
  }
  else if(c<=a && a<=b){
    min=c;
    max=b;
  }
  else{
    min=c;
    max=a;
  }
  printf("%d %d\n",min,max);
  return 0;
}
