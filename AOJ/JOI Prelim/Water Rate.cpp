#include <iostream>
using namespace std;

int main(void){
  int A,B,C,D,P;
  cin>>A;
  cin>>B;
  cin>>C;
  cin>>D;
  cin>>P;
  int X,Y;
  X=P*A;
  if(C>=P){
    Y=B;
  }
  else{
    Y=B+D*(P-C);
  }
  if(X<=Y){
    cout<<X<<endl;
  }
  else{
    cout<<Y<<endl;
  }
}
