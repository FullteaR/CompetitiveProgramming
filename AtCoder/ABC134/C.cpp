#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  int max=0;
  bool duplicate=false;
  int A;
  int index=0;
  int second=0;
  for(int i=0;i<N;i++){
    cin>>A;
    if(A==max){
      duplicate=true;
    }
    else if(A>max){
      second=max;
      max=A;
      duplicate=false;
      index=i;
    }
    else if(A>second){
      second=A;
    }
  }
  for(int j=0;j<N;j++){
    if(duplicate){
      cout<<max<<endl;
    }
    else{
      if(index==j){
        cout<<second<<endl;
      }
      else{
        cout<<max<<endl;
      }
    }
  }
  return 0;
}
