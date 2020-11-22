#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  long B[N];
  for(int i=0;i<N-1;i++){
    cin>>B[i];
  }
  B[N-1]=100010;
  long retval=0;
  for(int i=1;i<N;i++){
    retval+=min(B[i],B[i-1]);
  }
  retval+=B[0];
  cout<<retval<<endl;
  return 0;
}
