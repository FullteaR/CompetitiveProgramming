#include <iostream>
using namespace std;

int main(void){
  int A0,B0,C0;
  cin>>A0>>B0>>C0;

  double** table[110][110];
  for(int i=0;i<110;i++){
    for(int j=0;j<110;j++){
      table[i][j]=new double*[110];
      for(int k=0;k<110;k++){
        table[i][j][k]=new double[310];
        for(int l=0;l<310;l++){
          table[i][j][k][l]=0.0;
        }
      }
    }
  }
  table[A0][B0][C0][0]=1;
  for(int n=1;n<=300;n++){
    for(int b=B0;b<=100;b++){
      for(int c=C0;c<=100;c++){
        long a=A0+B0+C0+n-b-c;
        if(a<0 or a>100){
          continue;
        }
        table[a][b][c][n]=0;
        if(a>0){
          table[a][b][c][n]+=(a-1)*table[a-1][b][c][n-1]/(a+b+c-1);
        }
        if(b>0){
          table[a][b][c][n]+=(b-1)*table[a][b-1][c][n-1]/(a+b+c-1);
        }
        if(c>0){
          table[a][b][c][n]+=(c-1)*table[a][b][c-1][n-1]/(a+b+c-1);
        }
      }
    }
  }

  double exp = 0;
  for(int n=0;n<310;n++){
    int a=100;
    for(int b=B0;b<100;b++){
      int c=A0+B0+C0+n-a-b;
      if(c<C0 or c>=100){
        continue;
      }
      exp+=table[a][b][c][n]*n;
    }
    int b=100;
    for(int c=C0;c<100;c++){
      int a=A0+B0+C0+n-c-b;
      if(a<A0 or a>=100){
        continue;
      }
      exp+=table[a][b][c][n]*n;
    }
    int c=100;
    for(int b=B0;b<100;b++){
      int a=A0+B0+C0+n-c-b;
      if(a<A0 or a>=100){
        continue;
      }
      exp+=table[a][b][c][n]*n;
    }
  }
  cout<<exp<<endl;
}
