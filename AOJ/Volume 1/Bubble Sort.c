#include <stdio.h>
#include <stdlib.h>


int sort(int* Array, int n);

int main(void){
  while(1){
    int n,a;
    scanf("%d",&n);
    if(n==0){break;}
    int* Array=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
      scanf("%d",&a);
      Array[i]=a;
    }
    int retval=sort(Array,n);
    printf("%d\n",retval);
  }
  return 0;
}


int sort(int* Array, int n){
  int swap=0;
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<i;j++){
      if(Array[j]>Array[j+1]){
        int tmp=Array[j];
        Array[j]=Array[j+1];
        Array[j+1]=tmp;
        swap++;
      }
    }
  }
  return swap;
}
