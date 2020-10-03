#include <iostream>
using namespace std;

int main(void){
  long N;
  cin>>N;
  long retval=0;
  for(long i=1;i<=N;i++){
    if(i*i<N){
      retval+=1;
    }
    for(long j=i+1;j<=(N/i)+20;j++){
      if(i*j<N){
        retval+=2;
      }
    }
  }
  cout<<retval<<endl;
  return 0;
}
