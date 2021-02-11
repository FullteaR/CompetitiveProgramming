#include <iostream>
#include <cmath>
using namespace std;

int main(void){
  double d;
  while(cin>>d){
    if(d<0)return 0;
    d*=16;
    if((long)d!=d){
      cout<<"NA"<<endl;
      continue;
    }
    long d_long=(long)d;
    if(d_long>=pow(2,16)){
      cout<<"NA"<<endl;
      continue;
    }
    string jissuu="";
    string syousuu="";
    for(long i=11;i>=4;i--){
      jissuu+=(char)(d_long/pow(2,i) + '0');
      d_long=d_long%(long)pow(2,i);
    }
    for(long i=3;i>=0;i--){
      syousuu+=(char)(d_long/pow(2,i) + '0');
      d_long=d_long%(long)pow(2,i);
    }
    cout<<jissuu<<"."<<syousuu<<endl;
  }
  return 0;
}
