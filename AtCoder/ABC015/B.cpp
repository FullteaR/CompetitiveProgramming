#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  int S=0;
  int c=0;
  for(int i=0;i<N;i++){
    int A;
    cin>>A;
    if(A!=0){
      S+=A;
      c++;
    }
  }
  if(S%c==0){
    cout<<S/c<<endl;
  }
  else{
    cout<<S/c+1<<endl;
  }
  return 0;
}
