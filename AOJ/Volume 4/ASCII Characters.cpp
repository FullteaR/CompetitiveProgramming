#include <iostream>
using namespace std;
int main(void){
  int N;
  cin>>N;
  if('A'<=(char)N and (char)N<='Z'){
    cout<<1<<endl;
  }
  else if('a'<=(char)N and (char)N<='z'){
    cout<<2<<endl;
  }
  else{
    cout<<0<<endl;
  }
  return 0;
}
