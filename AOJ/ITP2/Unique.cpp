#include <iostream>
using namespace std;

int main(void){
  long now=-100000010;
  int n;
  cin>>n;
  long a;
  for(int i=0;i<n;i++){
    cin>>a;
    if(a==now){
      ;
    }
    else{
      if(i==0){
        cout<<a;
      }
      else{
        cout<<" "<<a;
      }
      now=a;
    }
  }
  cout<<endl;
  return 0;
}
