#include <iostream>
#include <utility>
using namespace std;

int main(void){
  int H;
  int W;
  cin>>H>>W;
  char** masu = new char*[H];
  pair<int,int>** counts = new pair<int,int>* [H];
  for(int i=0;i<H;i++){
    masu[i] = new char[W];
    counts[i] = new pair<int,int>[W];
    for(int j=0;j<W;j++){
      cin>>masu[i][j];
      counts[i][j] = make_pair(0,0);
    }
  }
  for(int j=0;j<W;j++){
    int count=0;
    for(int i=H-1;i>=0;i--){
      if(masu[i][j]=='I'){
        count++;
      }
      else if(masu[i][j]=='J'){
        counts[i][j].first=count;
      }
    }
  }
  for(int i=0;i<H;i++){
    int count=0;
    for(int j=W-1;j>=0;j--){
      if(masu[i][j]=='O'){
        count++;
      }
      else if(masu[i][j]=='J'){
        counts[i][j].second=count;
      }
    }
  }
  long retval=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      retval+=counts[i][j].first*counts[i][j].second;
    }
  }
  cout<<retval<<endl;
  return 0;
}
