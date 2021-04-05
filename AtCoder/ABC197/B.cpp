#include <iostream>

using namespace std;

int main(void){
  int H,W,X,Y;
  cin>>H>>W>>X>>Y;
  bool mp[H+2][W+2];
  for(int j=0;j<W+2;j++){
    mp[0][j]=false;
    mp[H+1][j]=false;
  }
  for(int i=0;i<H+2;i++){
    mp[i][0]=false;
    mp[i][W+1]=false;
  }
  for(int i=0;i<H;i++){
    string s;
    cin>>s;
    for(int j=0;j<W;j++){
      mp[i+1][j+1]=(s[j]=='.');
    }
  }

  int count=1;
  int _X, _Y;
  _X = X;
  while(mp[_X-1][Y]){
    count+=1;
    _X--;
  }
  _X = X;
  while(mp[_X+1][Y]){
    count+=1;
    _X++;
  }

  _Y=Y;
  while(mp[X][_Y-1]){
    count+=1;
    _Y--;
  }
  _Y=Y;
  while(mp[X][_Y+1]){
    count+=1;
    _Y++;
  }

  cout<<count<<endl;
  return 0;
}
