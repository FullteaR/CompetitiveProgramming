#include <iostream>
using namespace std;

int main(void){
  string S;
  cin>>S;
  if(S=="RRR"){
    cout<<3<<endl;
  }
  else if(S=="RRS" or S=="SRR"){
    cout<<2<<endl;
  }
  else if(S=="SSS"){
    cout<<0<<endl;
  }
  else{
    cout<<1<<endl;
  }
  return 0;
}
