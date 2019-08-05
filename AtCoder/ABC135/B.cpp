#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  int count=0;
  int p;
  for(int i=0;i<N;i++){
    cin>>p;
    if(p!=i+1){
      count++;
    }
  }
  if(count==2 or count ==0){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  return 0;
}
