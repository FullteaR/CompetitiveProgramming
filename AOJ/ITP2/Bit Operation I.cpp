#include <iostream>
#include <math.h>
using namespace std;

void toBit(unsigned long x);



int main(void){
  unsigned long x;
  cin>>x;
  toBit(x);
  toBit(pow(2,32)-1-x);
  toBit(2*x);
  toBit(x/2);
  return 0;
}

void toBit(unsigned long x){
  x=x%((unsigned long)pow(2,32));
  for(int i=31;i>=0;i--){
    if(pow(2,i)<=x){
      cout<<1;
      x-=pow(2,i);
    }
    else{
      cout<<0;
    }
  }
  cout<<endl;
}
