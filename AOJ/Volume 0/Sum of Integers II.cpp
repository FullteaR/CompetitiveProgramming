#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void){
  //long table[11][101][1001];
  long **table[11];
  for(int i=0;i<=10;i++){
    table[i]=(long **)malloc(101*(sizeof(long *)));
    for(int j=0;j<=100;j++){
      table[i][j]=(long *)malloc(1001*sizeof(long));
    }
  }
  for(int i=0;i<=10;i++){
    for(int j=0;j<=100;j++){
      for(int s=0;s<=1000;s++){
        table[i][j][s]=0;
      }
    }
  }

  for(int j=0;j<=100;j++){
    table[1][j][j]=1;
  }

  for(int i=2;i<=10;i++){
    for(int j=0;j<=100;j++){
      for(int s=0;s<=1000;s++){
        if(s>=j){
        for(int k=0;k<j;k++){
            table[i][j][s]+=table[i-1][k][s-j];
          }
        }
      }
    }
  }

  int n,s;
  while(true){
    cin>>n>>s;
    if(n==0 and s==0){break;}
    long retval=0;
    for(int j=0;j<=100;j++){
      retval+=table[n][j][s];
    }
    cout<<retval<<endl;
  }
  return 0;
}
