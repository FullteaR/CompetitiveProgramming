#include <iostream>
using namespace std;

int main(void){
  long N,M;
  cin>>N>>M;
  //x+y+z=N, 2x+3y+4z=M
  //y+2z=M-2N, y=M-2N-2z, x=N-z-y=3N-M+z

  for(long z=0;M-2*N-2*z>=0;z++){
    long x=3*N-M+z;
    long y=M-2*N-2*z;
    if(x>=0 and y>=0){
      cout<<x<<" "<<y<<" "<<z<<endl;
      return 0;
    }
  }
  cout<<"-1 -1 -1"<<endl;
  return 0;
}
