#include <iostream>
#include <ios>
#include <iomanip>
using namespace std;

int main(void){
  int a;
  int student;
  cout<<setfill('0')<<right;
  while(cin>>a){
    student=a%39;
    if(student==0){
      student=39;
    }
    cout<<"3C"<<setw(2)<<student<<endl;
  }
  return 0;
}
