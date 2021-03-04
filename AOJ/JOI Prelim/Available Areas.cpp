//2xy+x+y=S
//(2x+1)(y+1/2)=S+1/2
//(2x+1)(2y+1)=2S+1

#include <iostream>
#include <cmath>
using namespace std;

int main(void){
  long retval = 0;
  long N;
  cin>>N;
  for(long i=0;i<N;i++){
    long long area;
    cin>>area;
    area = 2*area+1;
    bool able = false;
    for(long long i=3;i<min((long long)65570,area);i+=2){
      if(area%i==0){
        able = true;
        break;
      }
    }
    if(able==false){
      retval++;
    }
  }
  cout<<retval<<endl;

  return 0;
}
