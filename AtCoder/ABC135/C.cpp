#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void){
  int N;
  cin>>N;
  int* A = (int*)malloc(sizeof(int)*(N+1));
  int* B = (int*)malloc(sizeof(int)*N);
  for(int i=0;i<N+1;i++){
    cin>>A[i];
  }
  for(int i=0;i<N;i++){
    cin>>B[i];
  }
  long long kill=0;
  int rest=0;
  for(int i=0;i<N;i++){
    if(A[i]<=rest){
      kill+=A[i];
      rest=B[i];
    }
    else if(A[i]<=rest+B[i]){
      kill+=A[i];
      rest=rest+B[i]-A[i];
    }
    else{
      kill=kill+rest+B[i];
      rest=0;
    }
  }
  kill+=min(rest,A[N]);
  cout<<kill<<endl;
  return 0;
}
