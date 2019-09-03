#include <iostream>
using namespace std;

int main(void){
  int A,B,C,D,N;
  cin>>N>>A>>B>>C>>D;
  int X,Y;
  if(N%A==0){
    X=B*(N/A);
  }
  else{
    X=B*((N/A)+1);
  }
  if(N%C==0){
    Y=D*(N/C);
  }
  else{
    Y=D*((N/C)+1);
  }
  if(X<=Y){
    cout<<X<<endl;
  }
  else{
    cout<<Y<<endl;
  }
  return 0;
}
