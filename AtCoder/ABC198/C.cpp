#include <iostream>
#include <cmath>

using namespace std;

int main(void){
  long long R,X,Y;
  cin>>R>>X>>Y;
  //NR=>dist(X,Y);
  long long N=0;
  long long D2=pow(X,2)+pow(Y,2);
  if(pow(R,2)==D2){
    cout<<1<<endl;
    return 0;
  }
  if(pow(R,2)>D2){
    cout<<2<<endl;
    return 0;
  }
  while(pow(N*R,2)<D2){
    N++;
  }
  cout<<N<<endl;
  return 0;
}
