#include <iostream>
#include <algorithm>
using namespace std;

void deleteIsland(int i, int j, int** island);

int main(void){
  while(1){
    int** island=(int**)malloc(sizeof(int*)*14);
    for(int i=0;i<14;i++){
      island[i]=(int*)malloc(sizeof(int)*14);
    }
    for(int i=0;i<14;i++){
      island[0][i]=0;
      island[13][i]=0;
      island[i][0]=0;
      island[i][13]=0;
    }

    string s;
    for(int i=1;i<13;i++){
      cin>>s;
      for(int j=1;j<13;j++){
        island[i][j]=s[j-1]-'0';
      }
    }
    if(cin.eof())break;

    int count=0;
    for(int i=1;i<13;i++){
      for(int j=1;j<13;j++){
        if(island[i][j]==1){
          count++;
          deleteIsland(i,j,island);
        }
      }
    }
    cout<<count<<endl;
  }
  return 0;
}

void deleteIsland(int i, int j, int** island){
  island[i][j]=0;
  bool l,r,u,d;
  l=false;
  r=false;
  u=false;
  d=false;
  if(island[i-1][j]==1)u=true;
  if(island[i+1][j]==1)d=true;
  if(island[i][j-1]==1)l=true;
  if(island[i][j+1]==1)r=true;
  if(u)deleteIsland(i-1,j,island);
  if(d)deleteIsland(i+1,j,island);
  if(l)deleteIsland(i,j-1,island);
  if(r)deleteIsland(i,j+1,island);
}
