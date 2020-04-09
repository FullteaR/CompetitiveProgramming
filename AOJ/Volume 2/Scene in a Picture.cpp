#include <iostream>
#include <algorithm>
using namespace std;
#define INF 100000

struct point{
  int x;
  int y;
};

void find(int** w,int** p, int n, int m, point* retval);

bool match(int i, int j, int** w, int** p, int m);

int main(void){
  int n,m;
  while(true){
    cin>>n>>m;
    if(n==0 and m==0){break;}
    int** w=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
      w[i]=(int*)malloc(sizeof(int)*n);
      for(int j=0;j<n;j++){
        cin>>w[i][j];
      }
    }
    int** p=(int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++){
      p[i]=(int*)malloc(sizeof(int)*m);
      for(int j=0;j<m;j++){
        cin>>p[i][j];
      }
    }
    point retval;
    find(w,p,n,m,&retval);
    if(retval.x==INF and retval.y==INF){
      cout<<"NA"<<endl;
    }
    else{
      cout<<retval.x+1<<" "<<retval.y+1<<endl;
    }
  }
}

void find(int** w,int** p, int n, int m, point* retval){
  retval->x=INF;
  retval->y=INF;

  int** p1=p;
  int** p2=(int**)malloc(sizeof(int*)*m);
  for(int i=0;i<m;i++){
    p2[i]=(int*)malloc(sizeof(int)*m);
    for(int j=0;j<m;j++){
      p2[i][j]=p1[m-1-j][i];
    }
  }
  int** p3=(int**)malloc(sizeof(int*)*m);
  for(int i=0;i<m;i++){
    p3[i]=(int*)malloc(sizeof(int)*m);
    for(int j=0;j<m;j++){
      p3[i][j]=p2[m-1-j][i];
    }
  }

  int** p4=(int**)malloc(sizeof(int*)*m);
  for(int i=0;i<m;i++){
    p4[i]=(int*)malloc(sizeof(int)*m);
    for(int j=0;j<m;j++){
      p4[i][j]=p3[m-1-j][i];
    }
  }

  for(int i=0;i<=n-m;i++){
    for(int j=0;j<=n-m;j++){
      if(match(i,j,w,p1,m)){
        for(int _y=0;_y<m;_y++){
          for(int _x=0;_x<m;_x++){
            if(p1[_y][_x]!=-1){
              int y=_y+i;
              int x=_x+j;
              if(retval->y>y or (retval->y==y and retval->x>x)){
                retval->y=y;
                retval->x=x;
              }
            }
          }
        }
      }
      if(match(i,j,w,p2,m)){
        for(int _y=0;_y<m;_y++){
          for(int _x=0;_x<m;_x++){
            if(p2[_y][_x]!=-1){
              int y=_y+i;
              int x=_x+j;
              if(retval->y>y or (retval->y==y and retval->x>x)){
                retval->y=y;
                retval->x=x;
              }
            }
          }
        }
      }
      if(match(i,j,w,p3,m)){
        for(int _y=0;_y<m;_y++){
          for(int _x=0;_x<m;_x++){
            if(p3[_y][_x]!=-1){
              int y=_y+i;
              int x=_x+j;
              if(retval->y>y or (retval->y==y and retval->x>x)){
                retval->y=y;
                retval->x=x;
              }
            }
          }
        }
      }
      if(match(i,j,w,p4,m)){
        for(int _y=0;_y<m;_y++){
          for(int _x=0;_x<m;_x++){
            if(p4[_y][_x]!=-1){
              int y=_y+i;
              int x=_x+j;
              if(retval->y>y or (retval->y==y and retval->x>x)){
                retval->y=y;
                retval->x=x;
              }
            }
          }
        }
      }
    }
  }
}

bool match(int i, int j, int** w, int** p, int m){
  for(int y=0;y<m;y++){
    for(int x=0;x<m;x++){
      if(p[y][x]!=-1 and p[y][x]!=w[y+i][x+j]){return false;}
    }
  }
  return true;
}
