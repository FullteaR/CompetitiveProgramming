#include <iostream>
using namespace std;

int main(void){
  string T,P;
  cin>>T;
  cin>>P;
  if(T.size()<P.size()){
    return 0;
  }
  for(int i=0;i<T.size()-P.size()+1;i++){
    bool flag=true;
    for(int j=0;j<P.size();j++){
      if(T[i+j]!=P[j]){
        flag=false;
        break;
      }
    }
    if(flag){
      cout<<i<<endl;
    }
  }
  return 0;
}
