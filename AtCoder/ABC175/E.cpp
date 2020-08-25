#include <iostream>
using namespace std;

int main(void){
  int R,C;
  long K;
  cin>>R>>C>>K;
  long* map[R];
  for(int i=0;i<R;i++){
    map[i]=(long*)malloc(sizeof(long)*C);
  }
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      map[i][j]=0;
    }
  }
  for(int i=0;i<K;i++){
    long r,c,v;
    cin>>r>>c>>v;
    map[r-1][c-1]=v;
  }
  //long table[R][C][4];
  long** table[R];
  for(int i=0;i<R;i++){
    table[i]=(long**)malloc(sizeof(long*)*C);
    for(int j=0;j<C;j++){
      table[i][j]=(long*)malloc(sizeof(long)*4);
    }
  }
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      for(int k=0;k<4;k++){
        table[i][j][k]=0;
      }
    }
  }
  table[0][0][1]=map[0][0];

  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(j>0){
        table[i][j][0]=max(table[i][j-1][0], table[i][j][0]);
        for(int k=1;k<4;k++){
          table[i][j][k]=max(table[i][j-1][k], table[i][j-1][k-1]+map[i][j]);
        }
      }
      if(i>0){
        table[i][j][0]=max({table[i][j][0], table[i-1][j][0], table[i-1][j][1], table[i-1][j][2], table[i-1][j][3]});
        table[i][j][1]=max({table[i][j][1], table[i-1][j][0]+map[i][j], table[i-1][j][1]+map[i][j], table[i-1][j][2]+map[i][j], table[i-1][j][3]+map[i][j]});
      }
    }
  }



  cout<<max({table[R-1][C-1][0], table[R-1][C-1][1], table[R-1][C-1][2], table[R-1][C-1][3]})<<endl;

  return 0;
}
