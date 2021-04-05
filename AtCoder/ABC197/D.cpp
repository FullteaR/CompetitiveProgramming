#include <iostream>
#include <cmath>

using namespace std;

int main(void){
  int N;
  double x0,y0,xN2,yN2;
  cin>>N;
  cin>>x0>>y0;
  cin>>xN2>>yN2;
  double xc = (x0+xN2)/2;
  double yc = (y0+yN2)/2;
  double arg = 2*M_PI / N;
  double r = sqrt(pow(xc-x0,2)+pow(yc-y0,2));
  double cos0 = (x0-xc)/r;
  double sin0 = (y0-yc)/r;
  double cos1 = cos0*cos(arg)-sin0*sin(arg);
  double sin1 = sin0*cos(arg)+cos0*sin(arg);
  double x1 = xc + r*cos1;
  double y1 = yc + r*sin1;
  cout<<x1<<" "<<y1<<endl;
  return 0;
}
