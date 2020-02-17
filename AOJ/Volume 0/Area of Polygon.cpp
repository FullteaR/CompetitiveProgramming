#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

double triangle(double p1x,double p1y,double p2x,double p2y, double p3x, double p3y);

struct Point{
  double x;
  double y;
}typedef point;

int main(void){
  double x,y;
  vector<point> v;
  while(scanf("%lf,%lf",&x,&y)!=EOF){
    point p;
    p.x=x;
    p.y=y;
    v.push_back(p);
  }
  int n=v.size();
  double area=0;
  for(int i=1;i<n-1;i++){
    area+=triangle(v[0].x,v[0].y,v[i].x,v[i].y,v[i+1].x,v[i+1].y);
  }
  cout<<abs(area)<<endl;
  return 0;
}


double triangle(double p1x,double p1y,double p2x,double p2y, double p3x, double p3y){
  p2x-=p1x;
  p3x-=p1x;
  p2y-=p1y;
  p3y-=p1y;
  return -1*((double)(p2x*p3y-p3x*p2y))/2;
}
