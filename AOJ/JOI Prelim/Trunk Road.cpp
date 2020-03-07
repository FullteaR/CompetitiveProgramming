#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

int calc(int i, int j, int** A,int H,int W);

int main(void){
  int H,W;
  cin>>H>>W;
  int** A;
  A=(int**)malloc(sizeof(int*)*H);
  for(int i=0;i<H;i++){
    A[i]=(int*)malloc(sizeof(int)*W);
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>A[i][j];
    }
  }
  int retval=1000100;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      retval=min(calc(i,j,A,H,W),retval);
    }
  }
  cout<<retval<<endl;
  return 0;
}

int calc(int i, int j, int** A,int H,int W){
  int retval=0;
  for(int n=0;n<W;n++){
    for(int m=0;m<H;m++){
      retval+=min(abs(i-m),abs(j-n))*A[m][n];
    }
  }
  return retval;
}
