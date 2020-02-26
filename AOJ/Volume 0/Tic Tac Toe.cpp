#include <iostream>
using namespace std;

int main(void){
  string s;
  while(cin>>s){
    if(s[0]==s[1] && s[1]==s[2] && s[0]!='s')cout<<s[0]<<endl;
    else if(s[3]==s[4] && s[4]==s[5] && s[3]!='s')cout<<s[3]<<endl;
    else if(s[6]==s[7] && s[7]==s[8] && s[6]!='s')cout<<s[6]<<endl;
    else if(s[0]==s[3] && s[3]==s[6] && s[0]!='s')cout<<s[0]<<endl;
    else if(s[1]==s[4] && s[4]==s[7] && s[1]!='s')cout<<s[1]<<endl;
    else if(s[2]==s[5] && s[5]==s[8] && s[2]!='s')cout<<s[2]<<endl;
    else if(s[0]==s[4] && s[4]==s[8] && s[0]!='s')cout<<s[0]<<endl;
    else if(s[2]==s[4] && s[4]==s[6] && s[2]!='s')cout<<s[2]<<endl;
    else cout<<'d'<<endl;
  }
  return 0;
}
