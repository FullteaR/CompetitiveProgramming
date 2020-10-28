#include <iostream>
#include <algorithm>
using namespace std;

int calc(int N);

int main(void){
  while(1){
    int N;
    cin>>N;
    if(N==0){return 0;}
    int retval=calc(N);
    if(retval>=0){
      cout<<retval<<endl;
    }
    else{
      cout<<"NA"<<endl;
    }
  }
}

int calc(int N){
  if(N==0){
    return -65535;
  }
  if(N==6174){
    return 0;
  }
  int array[4]={N%10,(N/10)%10,(N/100)%10,(N/1000)%10};
  sort(array, array+4);
  int L=array[3]*1000+array[2]*100+array[1]*10+array[0];
  int S=array[0]*1000+array[1]*100+array[2]*10+array[3];
  return calc(L-S)+1;
}
