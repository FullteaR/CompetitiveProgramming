#include <iostream>
using namespace std;

int main(void){
  string S,T;
  cin>>S;
  cin>>T;
  int retval=0;
  for(int i=0;i<S.size();i++){
    if(S[i]!=T[i]){
      retval++;
    }
  }
  cout<<retval<<endl;
  return 0;
}
