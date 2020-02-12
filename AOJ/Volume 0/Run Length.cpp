#include <iostream>

using namespace std;

int main(void){
  string s;
  char last='@';
  int n;
  while(cin>>s){
    for(int i=0;i<(int)s.length();i++){
      if(s[i]!='@'){
        last=s[i];
        cout<<s[i];
      }
      else{
        i++;
        n=s[i]-'0';
        i++;
        for(int j=0;j<n;j++){
          cout<<s[i];
        }
      }
    }
    cout<<endl;
  }
  return 0;
}
