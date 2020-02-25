#include <iostream>
using namespace std;

int main(void){
  int n;
  int a,b;
  long s;
  while(cin>>a>>b>>n){
    s=0;
    a=a%b;
    for(int i=0;i<n;i++){
      a*=10;
      s+=a/b;
      a=a%b;
    }
    cout<<s<<endl;
  }
  return 0;
}
