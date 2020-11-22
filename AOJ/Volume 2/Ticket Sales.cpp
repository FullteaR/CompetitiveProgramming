#include <iostream>
#include <map>
using namespace std;

int main(void){
  map<char,int> d;
  d['1']=6000;
  d['2']=4000;
  d['3']=3000;
  d['4']=2000;
  char t;
  int n;
  for(int i=0;i<4;i++){
    cin>>t>>n;
    cout<<n*d[t]<<endl;
  }
  return 0;
}
