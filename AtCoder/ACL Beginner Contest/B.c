#include <stdio.h>

int main(void){
  long long A,B,C,D;
  scanf("%lld %lld %lld %lld",&A,&B,&C,&D);
  if(B<C || D<A){
    printf("No\n");
  }
  else{
    printf("Yes\n");
  }
  return 0;
}
