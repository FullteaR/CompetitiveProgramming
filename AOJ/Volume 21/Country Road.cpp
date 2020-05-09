#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    int n,k;
    cin>>n>>k;
    int x[n];
    for(int j=0;j<n;j++){
      cin>>x[j];
    }
    int distance[n-1];
    for(int j=0;j<n-1;j++){
      distance[j]=x[j+1]-x[j];
    }
    sort(distance,distance+n-1);
    int length=0;
    for(int j=0;j<n-k;j++){
      length+=distance[j];
    }
    cout<<length<<endl;
  }
  return 0;
}
