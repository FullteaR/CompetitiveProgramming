#include <iostream>
using namespace std;

int main(void){
  long long A;
  double B;
  cin>>A>>B;
  B=100*B;
  B=(long long)B;
  cout<<A*B/100<<endl;
  return 0;
}
