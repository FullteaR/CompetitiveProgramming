#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


struct treasure{
  int v;
  int w;
};

void thief(int W, int N, vector<treasure>* v, int* retV, int* retW);

int main(void){
  int c=1;
  int W;
  int N;
  while(true){
    cin>>W;
    if(W==0)break;
    cin>>N;
    vector<treasure> v;
    for(int i=0;i<N;i++){
      int _v,w;
      scanf("%d,%d",&_v,&w);
      treasure tmp;
      tmp.v=_v;
      tmp.w=w;
      v.push_back(tmp);
    }

    int retV;
    int retW;
    thief(W,N,&v,&retV,&retW);
    cout<<"Case "<<c<<":"<<endl;
    cout<<retV<<endl;
    cout<<retW<<endl;
    c++;
  }
  return 0;
}



void thief(int W, int N, vector<treasure>* _v, int* retV, int* retW){
  auto v=*_v;
  int table[N][W+1];
  for(int i=0;i<N;i++){
    for(int j=0;j<=W;j++){
      table[i][j]=0;
    }
  }
  for(int j=0;j<=W;j++){
    if(v[0].w>j)continue;
    else{
      table[0][j]=v[0].v;
    }
  }

  for(int i=1;i<N;i++){
    for(int j=0;j<=W;j++){
      if(v[i].w>j){
        table[i][j]=table[i-1][j];
      }
      else{
        table[i][j]=max(table[i-1][j],table[i-1][j-v[i].w]+v[i].v);
      }
    }
  }

  *retV=table[N-1][W];
  for(int j=W;j>=0;j--){
    if(table[N-1][j]==*retV){
      *retW=j;
    }
  }
}
