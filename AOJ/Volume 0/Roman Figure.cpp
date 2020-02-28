#include <iostream>
using namespace std;

int main(void){
  string s;
  char c;
  int n1,n2,n;

  while(cin>>s){
    n=0;
    n1=10000;
    for(int i=0;i<s.size();i++){
      c=s[i];
      if(c=='I')n2=1;
      else if(c=='V')n2=5;
      else if(c=='X')n2=10;
      else if(c=='L')n2=50;
      else if(c=='C')n2=100;
      else if(c=='D')n2=500;
      else n2=1000;
      if(n1<n2){
        n-=2*n1;
        n+=n2;
      }
      else{
        n+=n2;
      }
      n1=n2;
    }
    cout<<n<<endl;
  }
  return 0;
}
