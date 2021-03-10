#include <iostream>
using namespace std;

int main(void){
  long total;
  long price;
  while(cin>>total){
    if(total==0){
      break;
    }
    for(int i=0;i<9;i++){
      cin>>price;
      total-=price;
    }
    cout<<total<<endl;
  }
  return 0;
}
