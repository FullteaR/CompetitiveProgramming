#include <iostream>
using namespace std;

int main(void){
  int sum=0;
  int s;
  for(int i=0;i<5;i++){
    cin>>s;
    if(s<40)s=40;
    sum+=s;
  }
  cout<<sum/5<<endl;
  return 0;
}
