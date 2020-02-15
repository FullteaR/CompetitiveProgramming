#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Path{
  int a;
  int b;
  int d;

  bool operator<(const Path &another) const{
    return d<another.d;
  }
}typedef path;

int main(void){
  int n;
  int m;
  int a,b,d;
  vector<path> p;
  int lantern;
  while(1){
    cin>>n;
    if(n==0)break;
    cin>>m;
    for(int i=0;i<m;i++){
      scanf("%d,%d,%d",&a,&b,&d);
      path _p;
      _p.a=a;
      _p.b=b;
      _p.d=d;
      p.push_back(_p);
    }
    int group[n];
    for(int i=0;i<n;i++){
      group[i]=i;
    }
    lantern=0;
    sort(p.begin(),p.end());
    for(int i=0;i<m;i++){
      if(group[p[i].a]!=group[p[i].b]){
        lantern+=p[i].d/100-1;
        int g=group[p[i].a];
        for(int j=0;j<n;j++){
          if(group[j]==g){
            group[j]=group[p[i].b];
          }
        }
      }

    }
    cout<<lantern<<endl;
    p.clear();
  }
  return 0;
}
