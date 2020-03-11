#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define crossNum 110




int main(void){
  long a,b,odd;
  long cross[crossNum];
  for(int i=0;i<crossNum;i++){
    cross[i]=0;
  }
  while(cin>>a>>b){
    if(a>0 or b>0){
      cross[a]++;
      cross[b]++;
    }
    else{
      odd=0;
      for(int i=0;i<crossNum;i++){
        if(cross[i]%2==1){
          odd++;
        }
      }
      if(odd==2 and cross[1]%2==1 and cross[2]%2==1){
        cout<<"OK"<<endl;
      }
      else{
        cout<<"NG"<<endl;
      }

      for(int i=0;i<crossNum;i++){
        cross[i]=0;
      }
    }
  }
  return 0;
}
