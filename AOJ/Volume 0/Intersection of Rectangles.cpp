#include <iostream>
using namespace std;

int main(void){
  double xa1,ya1,xa2,ya2,xb1,yb1,xb2,yb2;
  while(cin>>xa1>>ya1>>xa2>>ya2>>xb1>>yb1>>xb2>>yb2){
    if(xb2<xa1 or xa2<xb1){
      cout<<"NO"<<endl;
    }
    else if(yb2<ya1 or ya2<yb1){
      cout<<"NO"<<endl;
    }
    else{
      cout<<"YES"<<endl;
    }
  }
  return 0;
}
