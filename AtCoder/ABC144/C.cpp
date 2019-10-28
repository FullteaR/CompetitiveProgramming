#include <iostream>
#include <math.h>
using namespace std;

int main(void){
  long N;
  cin>>N;
  long retval=N+1;
  for(int i=1;i<sqrt(N)+1;i++){
    if(N%i==0){
      retval=min(retval,i-2+N/i);
    }
  }
  cout<<retval<<endl;
  return 0;
}
