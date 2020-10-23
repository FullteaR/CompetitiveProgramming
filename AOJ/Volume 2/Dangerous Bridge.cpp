#include <iostream>
using namespace std;
#define LIMIT 150

struct person{
  int a;
  int b;
  int m;
}typedef person;

int main(void){
  int n;
  while(1){
    cin>>n;
    if(n==0){return 0;}
    person persons[n];
    for(int i=0;i<n;i++){
      int m,a,b;
      cin>>m>>a>>b;
      persons[i].m=m;
      persons[i].a=a;
      persons[i].b=b;
    }
    bool ok=true;
    for(int i=0;i<n;i++){
      int t=persons[i].a;
      int weight_sum=0;
      for(int j=0;j<n;j++){
        person p=persons[j];
        if(p.a<=t and t<p.b){
          weight_sum+=p.m;
        }
      }
      if(weight_sum>LIMIT){
        ok=false;
        break;
      }
    }
    if(ok){
      cout<<"OK"<<endl;
    }
    else{
      cout<<"NG"<<endl;
    }
  }
  return 0;
}
