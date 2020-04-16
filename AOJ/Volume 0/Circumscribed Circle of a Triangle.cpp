//C++で出すとWA, C++14で出すとACになる。なんで?

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main(void){
  int n;
  cin>>n;
  long double x1,y1,x2,y2,x3,y3;
  for(int i=0;i<n;i++){
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    long double a,b,c,d,px,py,R,det;
    a=x3-x1;
    b=y3-y1;
    c=x2-x1;
    d=y2-y1;
    det=a*d-b*c;
    px=(a*a*d+b*b*d-b*c*c-b*d*d)/(2*det);
    py=(-1*c*a*a-c*b*b+a*c*c+a*d*d)/(2*det);
    R=sqrt(px*px+py*py);
    printf("%.3Lf %.3Lf %.3Lf\n",round((px+x1)*1000)/1000.0,round((py+y1)*1000)/1000.0,round(R*1000)/1000.0);
  }
  return 0;
}
