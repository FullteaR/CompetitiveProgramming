#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
  double Sx,Sy,Gx,Gy;
  cin>>Sx>>Sy>>Gx>>Gy;
  double ans = Sx+Sy*(Gx-Sx)/(Gy+Sy);
  printf("%.16lf",ans);
  return 0;
}
