#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  int H[N+1];
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  H[N]=1000000010;
  int ans=0;
  int cnt=0;
  for(int i=1;i<=N;i++){
    if(H[i-1]>=H[i]){
      cnt+=1;
    }
    else{
      ans=max(cnt,ans);
      cnt=0;
    }
  }
  cout<<ans<<endl;
  return 0;
}
