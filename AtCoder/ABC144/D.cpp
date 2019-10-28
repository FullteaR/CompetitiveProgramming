#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main(void){
  cout<<fixed<<setprecision(10);
  long double pi=acos(-1);
  int a,b,x;
  cin>>a>>b>>x;
  long double k, retval;
  if(a*a*b/2<x){
    k=2.0*x/(a*a)-b;
    retval=atan((b-k)/a)*180.0/pi;
  }
  else{
    k=2.0*x/(a*b);
    retval=atan(b/k)*180.0/pi;
  }
  cout<<retval<<endl;
  return 0;
}
