#include <iostream>
#include <cmath>
using namespace std;

int main(void){
  int m,n;
  double v;
  double area1=0;
  double area2=0;
  double angle1,angle2;
  while(1){
    area1=0;
    area2=0;
    angle1=360;
    angle2=360;
    cin>>n;
    if(n==0)break;
    for(int i=0;i<n-1;i++){
      cin>>v;
      angle1-=v;
      v=2*v*M_PI/360;
      area1+=sin(v)/2;
    }
    area1+=sin(2*angle1*M_PI/360)/2;
    cin>>m;
    for(int i=0;i<m-1;i++){
      cin>>v;
      angle2-=v;
      v=2*v*M_PI/360;
      area2+=sin(v)/2;
    }
    area2+=sin(2*angle2*M_PI/360)/2;
    if(abs(area1-area2)<0.00000001){
      cout<<0<<endl;
    }
    else if(area1>area2){
      cout<<1<<endl;
    }
    else{
      cout<<2<<endl;
    }
  }
  return 0;

}
