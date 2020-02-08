#include <iostream>
#include <cmath>
using namespace std;

double bmi(double w, double h);

int main(void){
  int n;
  double p,h,w;
  double delta;
  double retval=10000;
  while(1){
    cin>>n;
    if(n==0)break;
    delta=10000000;
    for(int i=0;i<n;i++){
      cin>>p>>h>>w;
      if(abs(bmi(w,h)-22)<delta){
        delta=abs(bmi(w,h)-22);
        retval=p;
      }
    }
    cout<<retval<<endl;
  }
  return 0;
}

double bmi(double w, double h){
  return w/((h/100)*(h/100));
}
