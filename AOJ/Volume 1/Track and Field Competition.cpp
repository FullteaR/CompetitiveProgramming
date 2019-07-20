#include <iostream>
using namespace std;

int main(void){
  int p;
  double t;
  double t7,t8;
  t7=100000000;
  t8=100000000;
  int p7,p8;
  for(int i=0;i<3;i++){
    int p1,p2,p3,p4;
    double t1,t2,t3,t4;
    t1=100000000;
    t2=100000000;
    t3=100000000;
    t4=100000000;
    for(int j=0;j<8;j++){
      cin>>p>>t;
      if(t<t1){
        t4=t3;
        t3=t2;
        t2=t1;
        t1=t;
        p4=p3;
        p3=p2;
        p2=p1;
        p1=p;
      }
      else if(t<t2){
        t4=t3;
        t3=t2;
        t2=t;
        p4=p3;
        p3=p2;
        p2=p;
      }
      else if(t<t3){
        t4=t3;
        t3=t;
        p4=p3;
        p3=p;
      }
      else if(t<t4){
        t4=t;
        p4=p;
      }
    }
    cout<<p1<<" "<<t1<<endl;
    cout<<p2<<" "<<t2<<endl;
    if(t4<t7){
      t7=t3;
      p7=p3;
      t8=t4;
      p8=p4;
    }
    else if(t4<t8){
      if(t3<t7){
        t7=t3;
        p7=p3;
        t8=t4;
        p8=p4;
      }
      else{
        t8=t4;
        p8=p4;
      }
    }
    else if(t3<t7){
      t8=t7;
      p8=p7;
      t7=t3;
      p7=p3;
    }
    else if(t3<t8){
      t8=t3;
      p8=p3;
    }
  }
  cout<<p7<<" "<<t7<<endl;
  cout<<p8<<" "<<t8<<endl;
}
