#include <stdio.h>
#include <math.h>
long double tanri(long double r, long double y);
long double fukuri(long double r, long double y);
long double calc(long double r, long double y, int t);


int main(void){
  int n,y;
  while(1){
    scanf("%d",&n);
    if(n==0){return 0;}
    scanf("%d",&y);
    long double Money=0;
    int B;
    for(int i=0;i<n;i++){
      int b,t;
      long double r;
      scanf("%d %Lf %d",&b,&r,&t);
      long double money=calc(r,y,t);
      if(Money<money){
        Money=money;
        B=b;
      }
    }
    printf("%d\n",B);
  }
}

long double tanri(long double r, long double y){
  return 1+(y*r/100.0);
}
long double fukuri(long double r, long double y){
  return pow(1+r/100.0,y);
}
long double calc(long double r, long double y, int t){
  if(t==1){
    return tanri(r,y);
  }
  else if(t==2){
    return fukuri(r,y);
  }
}
