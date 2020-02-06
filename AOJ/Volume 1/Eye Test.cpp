#include <iostream>
using namespace std;

int main(void){
  double l,r;
  double la=0;
  double ra=0;
  double lb=0;
  double rb=0;
  double lc=0;
  double rc=0;
  double ld=0;
  double rd=0;
  while(cin>>l>>r){
    if(l>=1.1)la+=1;
    else if(l>=0.6)lb+=1;
    else if(l>=0.2)lc+=1;
    else ld+=1;
    if(r>=1.1)ra+=1;
    else if(r>=0.6)rb+=1;
    else if(r>=0.2)rc+=1;
    else rd+=1;
  }
  cout<<la<<" "<<ra<<endl;
  cout<<lb<<" "<<rb<<endl;
  cout<<lc<<" "<<rc<<endl;
  cout<<ld<<" "<<rd<<endl;
  return 0;
}
