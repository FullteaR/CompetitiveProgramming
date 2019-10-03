#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void){
  int N,K;
  cin>>N>>K;
  int h;
  int getOn=0;
  for(int i=0;i<N;i++){
    cin>>h;
    if(h>=K){
      getOn+=1;
    }
  }
  cout<<getOn<<endl;
  return 0;
}
