#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  int retval=10000;
  for(int i=0;i<N;i++){
    int T;
    cin>>T;
    retval=min(T,retval);
  }
  cout<<retval<<endl;
  return 0;
}
