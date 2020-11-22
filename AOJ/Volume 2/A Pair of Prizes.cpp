#include <iostream>
using namespace std;

int main(void){
  long N;
  while(cin>>N){
    if(N==0){break;}
    long* k = new long[N];
    for(long i=0;i<N;i++){
      cin>>k[i];
    }
    long require=1;
    long total=0;
    for(long i=0;i<N;i++){
      if(k[i]>0){
        require++;
        total+=k[i];
      }
    }
    if(total<require){
      cout<<"NA"<<endl;
    }
    else{
      cout<<require<<endl;
    }
  }
  return 0;
}
