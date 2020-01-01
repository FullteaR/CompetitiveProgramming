#include <iostream>
#include <math.h>
using namespace std;

void toBit(unsigned long x);



int main(void){
  unsigned long a,b;
  cin>>a>>b;
  toBit(a&b);
  toBit(a|b);
  toBit(a^b);
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
