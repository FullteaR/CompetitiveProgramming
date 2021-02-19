#include <iostream>
using namespace std;

int main(void){
  long N;
  cin>>N;
  int K;
  cin>>K;
  for(int i=0;i<K;i++){
    long a,b;
    cin>>a>>b;
    a--;
    b--;
    a=min(a,N-a-1);
    b=min(b,N-b-1);
    cout << min(a,b)%3+1 << endl;
  }
  return 0;
}
