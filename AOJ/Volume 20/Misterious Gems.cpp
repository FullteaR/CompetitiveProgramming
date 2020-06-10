#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool solve(bool** gems, vector<pair<char,int> >* v);

int main(void){
  while(1){
    int N,M;
    cin>>N;
    if(N==0){
      break;
    }
    bool* gems[21];
    for(int i=0;i<=20;i++){
      gems[i]=(bool*)malloc(21*sizeof(bool));
    }
    for(int i=0;i<=20;i++){
      for(int j=0;j<=20;j++){
        gems[i][j]=false;
      }
    }
    for(int i=0;i<N;i++){
      int x,y;
      cin>>x>>y;
      gems[20-y][x]=true;
    }
    cin>>M;
    vector<pair<char,int> > v;
    for(int i=0;i<M;i++){
      char d;
      int l;
      cin>>d>>l;
      pair<char,int> p=make_pair(d,l);
      v.push_back(p);
    }
    if(solve(gems,&v)) {
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
  return 0;
}

bool solve(bool** gems, vector<pair<char,int> >* _v){
  auto v=*_v;
  auto point=make_pair(10,10);
  gems[10][10]=false;
  for(auto iter=v.begin();iter!=v.end();iter++){
    if(iter->first=='S'){
      int X=point.first;
      int y_goal=point.second+iter->second;
      for(int y=min(point.second,y_goal);y<=max(point.second,y_goal);y++){
        gems[y][X]=false;
      }
      gems[y_goal][X]=false;
      point.second=y_goal;
    }
    else if(iter->first=='N'){
      int X=point.first;
      int y_goal=point.second-iter->second;
      for(int y=min(point.second,y_goal);y<=max(point.second,y_goal);y++){
        gems[y][X]=false;
      }
      gems[y_goal][X]=false;
      point.second=y_goal;
    }
    else if(iter->first=='E'){
      int Y=point.second;
      int x_goal=point.first+iter->second;
      for(int x=min(point.first,x_goal);x<=max(point.first,x_goal);x++){
        gems[Y][x]=false;
      }
      gems[Y][x_goal]=false;
      point.first=x_goal;
    }
    else if(iter->first=='W'){
      int Y=point.second;
      int x_goal=point.first-iter->second;
      for(int x=min(point.first,x_goal);x<=max(point.first,x_goal);x++){
        gems[Y][x]=false;
      }
      gems[Y][x_goal]=false;
      point.first=x_goal;
    }
  }
  for(int x=0;x<=20;x++){
    for(int y=0;y<=20;y++){
      if(gems[y][x]){
        return false;
      }
    }
  }
  return true;
}
