#include <iostream>
using namespace std;

int main(void){
  int p1,p2,p3,j1,j2;
  cin>>p1>>p2>>p3>>j1>>j2;
  cout<<min(p1,min(p2,p3))+min(j1,j2)-50<<endl;
  return 0;
}
