#include <iostream>
using namespace std;

int main(void){
  long N;
  cin>>N;
  int* A = new int[N];
  for(long i=0;i<N;i++){
    cin>>A[i];
  }
  long sqSum = 0;
  long Sum=0;
  for(long i=0;i<N;i++){
    sqSum+=A[i]*A[i];
    Sum+=A[i];
  }
  long AiAj=0;
  for(long i=0;i<N;i++){
    AiAj+=A[i]*Sum;
  }

  long retval=2*N*sqSum-2*AiAj;


  cout<<retval/2<<endl;
  return 0;
}
