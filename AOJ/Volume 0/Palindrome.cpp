#include <iostream>
using namespace std;

int main(void){
  string s;
  int retval=0;
  while(cin>>s){
    bool flag=true;
    for(int i=0;i<s.size();i++){
      if(s[i]!=s[s.size()-1-i]){
        flag=false;
        break;
      }
    }
    if(flag)retval++;

  }
  cout<<retval<<endl;
  return 0;
}
