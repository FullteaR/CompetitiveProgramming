#include <iostream>

using namespace std;

int main(void){
  int n,m;
  while(1){
    cin>>n>>m;
    if(n==0 && m==0)break;

    int people[n];
    for(int i=0;i<n;i++){
      people[i]=1;
    }
    int count=0;
    int ind=n-1;
    int rest=n;
    while(rest>1){
      ind=(ind+1)%n;
      if(people[ind]==1){
        count+=1;
        if(count==m){
          rest-=1;
          count=0;
          people[ind]=0;
        }
      }
    }
    for(int i=0;i<n;i++){
      if(people[i]==1){
        cout<<i+1<<endl;
      }
    }
  }
  return 0;
}
