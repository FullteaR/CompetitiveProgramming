#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void){
  int N;
  cin>>N;
  int cnt=0;
  int max=0;
  int A;
  for(int i=0;i<N;i++){
    cin>>A;
    if(A==1){
      cnt+=1;
    }
    else{
      if(cnt>max){
        max=cnt;
      }
      cnt=0;
    }
  }
  if(cnt>max){
    max=cnt;
  }
  cout<<max+1<<endl;
  return 0;
}
