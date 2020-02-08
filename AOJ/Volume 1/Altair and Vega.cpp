#include <iostream>
#include <cmath>
using namespace std;

struct Point{
  int x;
  int y;
}typedef point;

bool contain(point* p1, point* p2, point* p3, point* p);

int main(void){
  int n;
  cin>>n;
  int xp1,yp1,xp2,yp2,xp3,yp3,xk,yk,xs,ys;
  point p1,p2,p3,pk,ps;
  bool s,k;
  for(int i=0;i<n;i++){
    cin>>xp1>>yp1>>xp2>>yp2>>xp3>>yp3>>xk>>yk>>xs>>ys;
    p1.x=xp1;
    p1.y=yp1;
    p2.x=xp2;
    p2.y=yp2;
    p3.x=xp3;
    p3.y=yp3;
    pk.x=xk;
    pk.y=yk;
    ps.x=xs;
    ps.y=ys;
    s=contain(&p1,&p2,&p3,&ps);
    k=contain(&p1,&p2,&p3,&pk);
    if(s==k){
      cout<<"NG"<<endl;
    }
    else{
      cout<<"OK"<<endl;
    }
  }
  return 0;
}

bool contain(point* p1, point* p2, point* p3, point* p){
  int z1=0;
  int z2=0;
  z1+=(p1->x-p->x)*(p2->y-p->y)-(p2->x-p->x)*(p1->y-p->y);
  z2+=abs((p1->x-p->x)*(p2->y-p->y)-(p2->x-p->x)*(p1->y-p->y));
  z1+=(p2->x-p->x)*(p3->y-p->y)-(p3->x-p->x)*(p2->y-p->y);
  z2+=abs((p2->x-p->x)*(p3->y-p->y)-(p3->x-p->x)*(p2->y-p->y));
  z1+=(p3->x-p->x)*(p1->y-p->y)-(p1->x-p->x)*(p3->y-p->y);
  z2+=abs((p3->x-p->x)*(p1->y-p->y)-(p1->x-p->x)*(p3->y-p->y));
  if(abs(z1)==z2){
    return true;
  }
  else{
    return false;
  }
}
