#include <iostream>
using namespace std;

int main(void){
  int n;
  while(cin>>n){
    if(n==0){
      break;
    }
    long p,d1,d2;
    long id=0;
    long dist=0;
    for(int i=0;i<n;i++){
      cin>>p>>d1>>d2;
      if(dist<d1+d2){
        dist=d1+d2;
        id=p;
      }
    }
    cout<<id<<" "<<dist<<endl;
  }
  return 0;
}
