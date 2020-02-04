#include <stdio.h>

int main(void){
  int n;
  scanf("%d",&n);
  long v;
  long sum=0;
  for(int i=0;i<n;i++){
    scanf("%ld",&v);
    sum+=v;
  }
  printf("%ld\n",sum/n);
  return 0;
}
