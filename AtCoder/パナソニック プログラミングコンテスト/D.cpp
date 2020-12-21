#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
  long N;
  cin>>N;
  long* A = new long[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A,A+N);

  long long retval=0;
  for(int i=0;i<N;i++){
    retval+=A[i]*i;
    retval-=A[i]*(N-i-1);
  }
  cout<<retval<<endl;

  return 0;
}
