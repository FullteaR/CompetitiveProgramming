#include <iostream>
using namespace std;

int main(void){
  string S;
  cin>>S;
  if(S[2]==S[3] and S[4]==S[5]){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}
