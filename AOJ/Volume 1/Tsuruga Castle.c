#include <stdio.h>

int main(void){
  int n;
  while(1){
    scanf("%d",&n);
    if(n==0)break;
    int a;
    int age[7];
    for(int i=0;i<7;i++){
      age[i]=0;
    }
    for(int i=0;i<n;i++){
      scanf("%d",&a);
      if(a>=60){
        age[6]+=1;
      }
      else{
        age[a/10]+=1;
      }
    }
    for(int i=0;i<7;i++){
      printf("%d\n",age[i]);
    }
  }
  return 0;
}
