#include <stdio.h>
#include <stdlib.h>
#define MOD 998244353

int main(void){
  long* pow10 = (long*)malloc(sizeof(long)*200010);
  pow10[0]=1;
  for(long i=1;i<200010;i++){
    pow10[i]=(pow10[i-1]*10)%MOD;
  }


  long N,Q;
  scanf("%ld %ld",&N,&Q);
  int* S = (int*)malloc(sizeof(int)*N);
  for(int i=0;i<N;i++){
    S[i]=1;
  }
  long retval=0;
  for(long i=0;i<N;i++){
    retval+=pow10[i]*S[N-1-i];
    retval=retval%MOD;
  }
  for(long i=0;i<Q;i++){
    long L,R;
    int D;
    scanf("%ld %ld %d",&L,&R,&D);
    L--;
    R--;
    for(long j=L;j<=R;j++){
      retval-=S[j]*pow10[N-1-j];
      retval+=D*pow10[N-1-j];
      S[j]=D;
      retval=retval%MOD;
    }
    printf("%ld\n",retval);
  }
  return 0;
}
