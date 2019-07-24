#include <iostream>
using namespace std;

int main(void){
  int N,D;
  cin>>N>>D;
  int checkable=2*D+1;
  if(N%checkable==0){
    cout<<N/checkable<<endl;
  }
  else{
    cout<<N/checkable+1<<endl;
  }
  return 0;
}
