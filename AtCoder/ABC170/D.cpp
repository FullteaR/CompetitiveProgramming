#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define SIZE 1000010

int main(void){
  int N;
  cin>>N;
  int* A=(int*)malloc(sizeof(int)*N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A,A+N);

  bool* ok=(bool*)malloc(sizeof(bool)*SIZE);
  for(int i=0;i<SIZE;i++){
    ok[i]=true;
  }
  for(int i=0;i<N;i++){
    if(!ok[A[i]]){
      continue;
    }
    if(i<N-1 and A[i]==A[i+1]){
      ok[A[i]]=false;
    }
    int k=2;
    while(k*A[i]<SIZE){
      ok[k*A[i]]=false;
      k++;
    }
  }
  int retval=0;
  for(int i=0;i<N;i++){
    if(ok[A[i]]){
      retval++;
    }
  }
  cout<<retval<<endl;
}
