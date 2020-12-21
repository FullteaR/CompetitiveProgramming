#include <iostream>
using namespace std;

int main(void){
  long H,W,M;
  cin>>H>>W>>M;
  long** grid = new long*[H+2];
  for(long i=0;i<H+2;i++){
    grid[i] = new long[W+2];
  }
  H+=2;
  W+=2;
  cout<<"alloc"<<endl;
  for(long i=0;i<H;i++){
    for(long j=0;j<W;j++){
      grid[i][j]=true;
    }
  }
  for(long i=0;i<W;i++){
    grid[0][i]=false;
    grid[H-1][i]=false;
  }
  for(long i=0;i<H;i++){
    grid[i][0]=false;
    grid[i][W-1]=false;
  }

  for(long i=0;i<M;i++){
    long X,Y;
    cin>>X>>Y;
    grid[X][Y]=false;
  }
  cout<<"grid"<<endl;

  long** ableRD = new long*[H];
  long** ableDR = new long*[H];
  for(long i=0;i<H;i++){
    ableRD[i] = new long[W];
    ableDR[i] = new long[W];
  }

  for(long i=0;i<H;i++){
    for(long j=0;j<W;j++){
      ableDR[i][j]=false;
      ableRD[i][j]=false;
    }
  }

  ableRD[1][1]=true;
  long i=1;
  while(grid[1][i]){
    ableRD[1][i]=true;
    i++;
  }
  for(long i2=1;i2<i;i2++){
    long j=1;
    while(grid[j][i2]){
      ableRD[j][i2]=true;
      j++;
    }
  }

  ableDR[1][1]=true;
  i=1;
  while(grid[i][1]){
    ableDR[i][1]=true;
    i++;
  }
  for(long i2=1;i2<i;i2++){
    long j=1;
    while(grid[i2][j]){
      ableDR[i2][j]=true;
      j++;
    }
  }

  long retval=0;
  for(long i=0;i<H;i++){
    for(long j=0;j<W;j++){
      if(ableRD[i][j] or ableDR[i][j]){
        retval++;
      }
    }
  }
  cout<<retval<<endl;
  return 0;

}
