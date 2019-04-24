#include <stdio.h>

int gcd(int a,int b){
  int M,m;
  if(a>=b){
M=a;
 m=b;
  }
  else{
M=b;
m=a;
  }
  if(m==0){
    return M;
  }
  else{
    return gcd(m,M%m);
  }
}

int main(void){
  int N,M;
  scanf("%d %d",&N,&M);
  int a[100000];
  int _a;
  for(int i=0;i<N;i++){
    scanf("%d",&_a);
    a[i]=_a;
  }
int result;
  for(int i=1;i<=M;i++){
    result=0;
    for(int j=0;j<N;j++){
      if(gcd(a[j],i)==1){
        result++;
      }
    }
    printf("%d\n",result);
  }
}
