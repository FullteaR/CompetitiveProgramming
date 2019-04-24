#include<stdio.h>
#include<stdlib.h>
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
int n= 100000;
FILE *fp;
fp=fopen("array.txt","w");
fprintf(fp,"{");
for(int i=1;i<=n;i++){
  fprintf(fp,"{");
  for(int j=1;j<=n;j++){
    if(gcd(i,j)==1){
      fprintf(fp,"%d",1 );
    }
    else{
      fprintf(fp,"%d",0);
    }
    if(j!=n){
      fprintf(fp,",");
    }
    else{
      fprintf(fp,"}" );
    }
  }
  if(i!=n){
    fprintf(fp,",");
  }
  else{
    fprintf(fp,"}");
  }
}
}
