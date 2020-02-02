#include <iostream>
using namespace std;

int main(void){
  int N,M;
  cin>>N>>M;
  int A[N];
  int tmp;
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  for(int k=1;k<=M;k++){
    for(int i=0;i<N-1;i++){
      if(A[i]%k>A[i+1]%k){
        tmp=A[i];
        A[i]=A[i+1];
        A[i+1]=tmp;
      }
    }
  }
  for(int i=0;i<N;i++){
    cout<<A[i]<<endl;
  }
  return 0;
}
