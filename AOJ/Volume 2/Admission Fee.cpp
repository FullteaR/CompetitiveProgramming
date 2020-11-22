#include <iostream>
using namespace std;
double cost(double x, double y, double b, double p);

int main(void){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    double x,y,b,p;
    cin>>x>>y>>b>>p;
    cout<<cost(x,y,b,p)<<endl;
  }
  return 0;
}

double cost(double x, double y, double b, double p){
  if(b>=5 and p>=2){
    return 0.8*(b*x+p*y);
  }
  else if(b>=5 and p<2){
    return min(b*x+p*y, 0.8*(b*x+2*y));
  }
  else if(b<5 and p>=2){
    return min(b*x+p*y, 0.8*(5*x+p*y));
  }
  else{
    return min(b*x+p*y, 0.8*(5*x+2*y));
  }
}
