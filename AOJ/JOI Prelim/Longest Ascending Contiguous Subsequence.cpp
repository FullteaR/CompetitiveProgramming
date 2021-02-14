#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  int* A = new int[N+1];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  A[N]=-1;
  N++;
  int retval=1;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(A[j-1]>A[j]){
        retval=max(retval,j-i);
        break;
      }
    }
  }
  cout<<retval<<endl;
  return 0;
}
