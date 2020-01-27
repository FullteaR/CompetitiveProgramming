#include <iostream>
using namespace std;

int main(void){
  int A,B,C,D,E,F;
  cin>>A>>B>>C>>D>>E>>F;
  int score=A+B+C+D;
  score-=min(min(A,B),min(C,D));
  score+=max(E,F);
  cout<<score<<endl;
  return 0;
}
