#include <iostream>
using namespace std;

int main(void){
  long X,L,R;
  cin>>X>>L>>R;
  if(X<L){
    cout<<L<<endl;
  }
  else if(X<R){
    cout<<X<<endl;
  }
  else{
    cout<<R<<endl;
  }
  return 0;
}
