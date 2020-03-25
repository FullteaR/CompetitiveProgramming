#include <iostream>
#include <cmath>
using namespace std;

bool orthogonal(double xa, double ya, double xb, double yb, double xc, double yc, double xd, double yd);

int main(void){
  double xa,ya,xb,yb,xc,yc,xd,yd;
  while(cin>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd){
    if(orthogonal(xa,ya,xb,yb,xc,yc,xd,yd)){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}

bool orthogonal(double xa, double ya, double xb, double yb, double xc, double yc, double xd, double yd){
  if(abs((yd-yc)*(yb-ya)+(xd-xc)*(xb-xa))<0.00000000001){
    return true;
  }
  else{
    return false;
  }

}
