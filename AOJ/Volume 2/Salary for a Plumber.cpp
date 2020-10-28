#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
  while(1){
    long n;
    cin>>n;
    if(n==0){return 0;}
    long p=0;
    long* j = new long[n-1];
    for(int i=0;i<n;i++){
      long pi;
      cin>>pi;
      p+=pi;
    }
    for(int i=0;i<n-1;i++){
      cin>>j[i];
    }
    sort(j,j+n-1);
    reverse(j,j+n-1);
    long pipe_count = n;
    long retval = p*pipe_count;
    for(int i=0;i<n-1;i++){
      p+=j[i];
      pipe_count--;
      retval=max(retval,p*pipe_count);
    }
    cout<<retval<<endl;
  }
}
