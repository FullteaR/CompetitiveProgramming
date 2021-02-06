#include <iostream>
using namespace std;
#define mod 1000000007

int main(void){
  long H,W;
  cin>>H>>W;
  H+=2;
  W+=2;
  bool** a = new bool*[H];
  long** table = new long*[H];
  for(long i=0;i<H;i++){
    table[i]=new long[W];
    a[i]=new bool[W];
    for(long j=0;j<W;j++){
      table[i][j]=0;
      a[i][j]=false;
    }
  }
  for(long i=1;i<H-1;i++){
    for(long j=1;j<W-1;j++){
      char c;
      cin>>c;
      a[i][j]=(c=='.');
    }
  }
  table[1][1]=1;
  for(long i=1;i<H-1;i++){
    for(long j=1;j<W-1;j++){
      if(a[i-1][j]){
        table[i][j]+=table[i-1][j];
      }
      if(a[i][j-1]){
        table[i][j]+=table[i][j-1];
      }
      table[i][j]=table[i][j]%mod;
    }
  }
  cout<<table[H-2][W-2]%mod<<endl;
  return 0;
}
