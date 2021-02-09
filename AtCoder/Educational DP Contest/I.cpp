#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
  long N;
  cin>>N;
  double* p = new double[N];
  for(long i=0;i<N;i++){
    cin>>p[i];
  }
  double** table = new double*[N+1];
  for(long i=0;i<=N;i++){
    table[i]=new double[N+1];
  }
  //table[i][j]=コイン1~iを投げたとき、表がj枚出る確率

  table[0][0]=1;
  for(long j=1;j<=N;j++){
    table[0][j]=0;
  }
  for(long i=1;i<=N;i++){
    for(long j=0;j<=N;j++){
      table[i][j]=table[i-1][j-1]*p[i-1]+table[i-1][j]*(1-p[i-1]);
    }
  }
  double prob=0;
  for(long j=N/2+1;j<=N;j++){
    prob+=table[N][j];
  }
  printf("%.10lf\n",prob);
  return 0;
}
