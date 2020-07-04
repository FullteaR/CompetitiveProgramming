#include <iostream>
#include <cstdlib>
using namespace std;

int main(void){
 long N;
 cin>>N;
 long retval=0;
 for(long i=1;i<=N;i++){
   long n=N/i;
   retval+=i*n*(n+1)/2;
 }
 cout<<retval<<endl;
 return 0;
}
