#include <iostream>
using namespace std;

void spiral(int n);

int main(void){
  int d;
  cin>>d;
  int n;
  for(int i=0;i<d;i++){
    cin>>n;
    spiral(n);
    cout<<endl;
    if(i<d-1){
      cout<<endl;
    }
  }
  return 0;
}

void spiral(int n){
  int paper[n+4][n+4];
  for(int i=0;i<n+4;i++){
    for(int j=0;j<n+4;j++){
      paper[i][j]=0;
    }
  }
  for(int i=0;i<n+4;i++){
    paper[0][i]=1;
    paper[i][0]=1;
    paper[n+3][i]=1;
    paper[i][n+3]=1;
  }

  int now_x=2;
  int now_y=n+1;
  int forward=0;
  for(int _=0;_<n*n;_++){
    if(paper[now_y-1][now_x]+paper[now_y][now_x-1]+paper[now_y+1][now_x]+paper[now_y][now_x+1]<2){
      paper[now_y][now_x]=1;
    }
    if(forward==0){
      if(paper[now_y-2][now_x]==1){
        forward=1;
      }
      else{
        now_y-=1;
      }
    }
    else if(forward==1){
      if(paper[now_y][now_x+2]==1){
        forward=2;
      }
      else{
        now_x+=1;
      }
    }
    else if(forward==2){
      if(paper[now_y+2][now_x]==1){
        forward=3;
      }
      else{
        now_y+=1;
      }
    }
    else{
      if(paper[now_y][now_x-2]==1){
        forward=0;
      }
      else{
        now_x-=1;
      }
    }
  }

  for(int i=2;i<n+2;i++){
    for(int j=2;j<n+2;j++){
      if(paper[i][j]==1){
        cout<<"#";
      }
      else{
        cout<<" ";
      }
    }
    if(i<n+1){
      cout<<endl;
    }
  }
}
