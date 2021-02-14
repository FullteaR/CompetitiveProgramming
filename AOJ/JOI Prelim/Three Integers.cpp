#include <iostream>
using namespace std;

int main(void){
  int* count = new int[3];
  for(int i=0;i<3;i++){
    count[i]=0;
  }
  for(int i=0;i<3;i++){
    int c;
    cin>>c;
    count[c]++;
  }
  if(count[1]<count[2]){
    cout<<2<<endl;
  }
  else{
    cout<<1<<endl;
  }
  return 0;
}
