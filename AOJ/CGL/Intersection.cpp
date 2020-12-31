#include <iostream>
#include <cstdio>
#include <utility>

using namespace std;

bool intersection(pair<double, double> *a, pair<double, double> *b, pair<double, double> *x, pair<double, double>*y);

int main(void){
  double x1,y1,x2,y2,x3,y3,x4,y4;
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    auto a=make_pair(x1,y1);
    auto b=make_pair(x2,y2);
    auto c=make_pair(x3,y3);
    auto d=make_pair(x4,y4);
    if(intersection(&a,&b,&c,&d)){
      cout<<1<<endl;
    }
    else{
      cout<<0<<endl;
    }
  }
  return 0;
}


bool intersection(pair<double, double> *a, pair<double, double> *b, pair<double, double> *x, pair<double, double>*y){


  double det=(b->first-a->first)*(y->second-x->second)-(b->second-a->second)*(y->first-x->first);
  if(det==0){//平行
    if(a->first*b->second-b->first*a->second!=x->first*y->second-y->first*x->second){
      return false;
    }
    double p,q,r,s;
    if(a->first==b->first){
      p=min(a->second,b->second);
      q=max(a->second,b->second);
      r=min(x->second,y->second);
      s=max(x->second,y->second);
    }
    else{
      p=min(a->first,b->first);
      q=max(a->first,b->first);
      r=min(x->first,y->first);
      s=max(x->first,y->first);
    }
    if(q<r or s<p){
      return 0;
    }
    else{
      return 1;
    }
  }

  else{
    double m,n;
    double k1,k2;
    m=((x->first-y->first)*(a->first*b->second-b->first*a->second)+(b->first-a->first)*(x->first*y->second-y->first*x->second))/det;
    n=((x->second-y->second)*(a->first*b->second-b->first*a->second)+(b->second-a->second)*(x->first*y->second-y->first*x->second))/det;

    if(a->first==b->first){
      k1 = (n-a->second)/(b->second-a->second);
    }
    else{
      k1 = (m-a->first)/(b->first-a->first);
    }
    if(k1<0 or 1<k1){
      return false;
    }

    if(x->first==y->first){
      k2 = (n-x->second)/(y->second-x->second);
    }
    else{
      k2 = (m-x->first)/(y->first-x->first);
    }
    if(k2<0 or 1<k2){
      return false;
    }
    return true;
  }
}
