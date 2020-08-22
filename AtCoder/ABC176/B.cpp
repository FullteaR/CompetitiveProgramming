#include <iostream>
using namespace std;

int main(void){
  string N;
  cin>>N;
  long NNum=0;
  for(int i=0;i<N.size();i++){
    NNum+=N[i]-'0';
  }
  if(NNum%9==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}
