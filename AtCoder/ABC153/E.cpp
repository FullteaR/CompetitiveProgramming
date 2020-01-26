#include <iostream>
using namespace std;

int Min(int a,int b,int c);
#define inf 1000000010;

int main(void){
  int N,H;
  cin>>H>>N;
  int tables[N+1][H+1];
  for(int i=0;i<N+1;i++){
    for(int j=0;j<H+1;j++){
      tables[i][j]=0;
    }
  }
  int A[N];
  int B[N];

  for(int i=1;i<H+1;i++){
    tables[0][i]=inf;
  }

  for(int i=0;i<N;i++){
    cin>>A[i]>>B[i];
  }

  for(int i=1;i<N+1;i++){
    for(int j=0;j<H+1;j++){
      if(j>=A[i-1]){
        tables[i][j]=Min(tables[i-1][j],tables[i-1][j-A[i-1]]+B[i-1],tables[i][j-A[i-1]]+B[i-1]);
      }
      else{
        tables[i][j]=min(tables[i-1][j],tables[i][0]+B[i-1]);
      }

    }
  }

  cout<<tables[N][H]<<endl;
  return 0;
}

int Min(int a,int b,int c){
  int retval=inf;
  int values[3]={a,b,c};
  for(int i=0;i<3;i++){
    retval=min(retval,values[i]);
  }
  return retval;
}
