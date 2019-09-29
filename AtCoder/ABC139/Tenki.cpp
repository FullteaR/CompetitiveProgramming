#include <iostream>
using namespace std;

int main(void){
  string S,T;
  cin>>S;
  cin>>T;
  int acc=0;
  for(int i=0;i<3;i++){
    if(S[i]==T[i]){
      acc+=1;
    }
  }
  cout<<acc<<endl;
  return 0;
}
