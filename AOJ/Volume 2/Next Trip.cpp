#include <iostream>
using namespace std;
#define NA 13

int main(void){
  int L;
  while(true){
    cin>>L;
    if(L==0){break;}
    int money=0;
    int retval=NA;
    int M,N;
    for(int month=1;month<=12;month++){
      cin>>M>>N;
      money+=M-N;
      if(money>=L){
        retval=min(retval,month);
      }
    }
    if(retval==NA){
      cout<<"NA"<<endl;
    }
    else{
      cout<<retval<<endl;
    }
  }
  return 0;
}
