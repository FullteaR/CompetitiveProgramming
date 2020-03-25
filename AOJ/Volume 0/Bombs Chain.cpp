#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
#define SIZE 8

struct point{
  int x;
  int y;
};

int main(void){
  int n;
  cin>>n;
  for(int data=1;data<=n;data++){
    int plane[SIZE+6][SIZE+6];
    int X,Y;
    vector<point> bombs;
    point p;
    for(int i=3;i<SIZE+3;i++){
      string input;
      cin>>input;
      for(int j=0;j<SIZE;j++){
        plane[i][j+3]=input[j]-'0';
      }
    }
    for(int i=0;i<SIZE+6;i++){
      for(int j=0;j<3;j++){
        plane[j][i]=0;
        plane[i][j]=0;
        plane[SIZE-j-1+6][i]=0;
        plane[i][SIZE-j-1+6]=0;
      }
    }
    cin>>X>>Y;
    X--;
    Y--;
    X+=3;
    Y+=3;
    p.x=X;
    p.y=Y;
    bombs.push_back(p);

    while(bombs.size()>0){
      vector<point> _bombs;
      _bombs.clear();
      for(int i=0;i<bombs.size();i++){
        point bomb=bombs[i];
        plane[bomb.y][bomb.x]=0;
        for(int j=-3;j<=3;j++){
          if(plane[bomb.y+j][bomb.x]==1){
            plane[bomb.y+j][bomb.x]=0;
            point _p;
            _p.x=bomb.x;
            _p.y=bomb.y+j;
            _bombs.push_back(_p);
          }
          if(plane[bomb.y][bomb.x+j]==1){
            plane[bomb.y][bomb.x+j]=0;
            point _p;
            _p.x=bomb.x+j;
            _p.y=bomb.y;
            _bombs.push_back(_p);
          }
        }
      }
      bombs.clear();
      copy(_bombs.begin(),_bombs.end(),back_inserter(bombs));
      /*
      for(int j=0;j<bombs.size();j++){
        cout<<bombs[j].x<<" "<<bombs[j].y<<endl;
      }
      for(int i=0;i<SIZE+6;i++){
        for(int j=0;j<SIZE+6;j++){
          cout<<plane[i][j];
        }
        cout<<endl;
      }
      */
    }
    cout<<"Data "<<data<<":"<<endl;
    for(int i=3;i<SIZE+3;i++){
      for(int j=3;j<SIZE+3;j++){
        cout<<plane[i][j];
      }
      cout<<endl;
    }

  }
  return 0;
}
