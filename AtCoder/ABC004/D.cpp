#include <iostream>
#include <cassert>
using namespace std;

long dist(int G_L, int R, int G, int B);
long move(int L, int c, int R);

int main(void){
  int R,G,B;
  cin>>R>>G>>B;
  long retval=10000000010;


  for(int G_L=-400;G_L<400;G_L++){
    retval=min(dist(G_L,R,G,B), retval);
  }
  cout<<retval<<endl;

}


long dist(int G_L, int R, int G, int B){
  int G_R=G_L+G-1;
  int R_R=min(G_L-1, -100+(R-1)/2);
  int R_L=R_R-R+1;
  int B_L=max(G_R+1, 100-(B-1)/2);
  int B_R=B_L+B-1;
  return move(R_L,-100,R_R)+move(G_L,0,G_R)+move(B_L,100,B_R);
}

long move(int L, int c, int R){
  assert(L<R);
  long count = 0;
  for(int i=L;i<=R;i++){
    count+=abs(c-i);
  }
  return count;
}
