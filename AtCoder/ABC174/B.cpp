#include <iostream>
using namespace std;

int main(void){
  long N, D;
  cin>>N>>D;
  long retval=0;
  long X, Y;
  for(long i=0;i<N;i++){
    cin>>X>>Y;
    if(X*X+Y*Y<=D*D){
      retval++;
    }
  }
  cout<<retval<<endl;
}
