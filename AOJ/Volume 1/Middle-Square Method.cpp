#include <iostream>
using namespace std;

int random(int seed);

int main(void){
  int n;
  cin>>n;
  int x;
  for(int c=0;c<n;c++){
    cout<<"Case "<<c+1<<":"<<endl;
    cin>>x;
    for(int i=0;i<10;i++){
      x=random(x);
      cout<<x<<endl;
    }
  }
  return 0;
}


int random(int seed){
  int retval;
  retval=(seed*seed)/100;
  retval=retval%10000;
  return retval;
}
