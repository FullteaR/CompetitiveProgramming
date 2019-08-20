#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  double A,retval;
  retval=0;
  for(int i=0;i<N;i++){
    cin>>A;
    retval+=1/A;
  }
  cout<<1/retval<<endl;
  return 0;
}
