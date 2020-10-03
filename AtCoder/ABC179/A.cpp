#include <iostream>
using namespace std;

int main(void){
  string S;
  cin>>S;
  char last = S[S.length()-1];
  if(last=='s'){
    cout<<S<<"es"<<endl;
  }
  else{
    cout<<S<<"s"<<endl;
  }
  return 0;
}
