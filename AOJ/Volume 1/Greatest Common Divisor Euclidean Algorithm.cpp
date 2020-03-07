#include <iostream>
using namespace std;

struct result{
  int step;
  int gcd;
};

void gcd(int a, int b, result* r);

int main(void){
  int a,b;
  result r;
  while(1){
    cin>>a>>b;
    if(a==0 and b==0)break;
    gcd(a,b,&r);
    cout<<r.gcd<<" "<<r.step<<endl;
  }
  return 0;
}

void gcd(int _a, int _b, result* r){
  int step=0;
  int a=min(_a,_b);
  int b=max(_a,_b);
  while(a!=0){
    int tmp=b%a;
    b=a;
    a=tmp;
    step+=1;
  }
  r->step=step;
  r->gcd=b;
}
