#include <iostream>
using namespace std;

int grade(int pm, int pe, int pj);

int main(void){
  int n;
  int pm,pe,pj;
  while(1){
    cin>>n;
    if(n==0){break;}
    for(int i=0;i<n;i++){
      cin>>pm>>pe>>pj;
      cout<<(char)(grade(pm,pe,pj)+'A')<<endl;
    }
  }
  return 0;
}

int grade(int pm, int pe, int pj){
  if(pm==100 or pe==100 or pj==100){return 0;}
  if(pm+pe>=180){return 0;}
  if(pm+pe+pj>=240){return 0;}
  else if(pm+pe+pj>=70*3){return 1;}
  else if((pm+pe+pj>=50*3) and (pe>=80 or pm>=80)){return 1;}
  else{return 2;}
}
