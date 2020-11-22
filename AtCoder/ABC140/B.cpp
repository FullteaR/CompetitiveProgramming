#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  int A[N];
  int B[N];
  int C[N-1];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  int score=0;
  for(int i=0;i<N;i++){
    cin>>B[i];
    score+=B[i];
  }
  for(int i=0;i<N-1;i++){
    cin>>C[i];
  }

  for(int i=0;i<N-1;i++){
    if(A[i]+1==A[i+1]){
      score+=C[A[i]-1];
    }
  }
  cout<<score<<endl;
  return 0;
}
