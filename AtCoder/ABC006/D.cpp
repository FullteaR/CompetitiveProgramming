#include <iostream>
using namespace std;
#define INF 30010

int main(void){
  unsigned short N;
  cin>>N;
  unsigned short** table = new unsigned short*[N+1];
  for(unsigned short i=0;i<=N;i++){
    table[i] = new unsigned short[N+1];
    for(unsigned short j=0;j<=N;j++){
      table[i][j]=INF;
    }
  }
  for(unsigned short i=0;i<=N;i++){
    table[i][0]=i;
    table[0][i]=i;
  }
  unsigned short* c=new unsigned short[N];
  for(unsigned short i=0;i<N;i++){
    cin>>c[i];
  }


  for(unsigned short i=1;i<=N;i++){
    for(unsigned short j=1;j<=N;j++){
      table[i][j]=min(table[i-1][j],table[i][j-1])+1;
      if(c[i-1]==j){
        table[i][j]=min(table[i][j],table[i-1][j-1]);
      }
    }
  }
  cout<<table[N][N]/2<<endl;
  return 0;
}
