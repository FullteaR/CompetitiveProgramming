#include <iostream>
using namespace std;

int main(void){
  int n;
  int a,b;
  while(1){
    cin>>n;
    int scoreA=0;
    int scoreB=0;
    if(n==0){return 0;}
    for(int i=0;i<n;i++){
      cin>>a>>b;
      if(a>b){
        scoreA+=(a+b);
      }
      else if(a<b){
        scoreB+=(a+b);
      }
      else{
        scoreA+=a;
        scoreB+=b;
      }
    }
    cout<<scoreA<<" "<<scoreB<<endl;
  }
}
