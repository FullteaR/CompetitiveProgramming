#include <iostream>

using namespace std;

int team(int c, int a, int n);

int main(void){
  int Q;
  cin>>Q;
  for(int i=0;i<Q;i++){
    int c,a,n;
    cin>>c>>a>>n;
    cout<<team(c,a,n)<<endl;
  }
  return 0;
}

int team(int c, int a, int n){
  int retval=0;
  for(int tc=0;tc<=n;tc++){
    for(int ta=0;ta<=a-tc;ta++){
      int tb=c-tc-2*ta;
      if(tb<0){continue;}
      tb=tb/3;
      retval=max(retval,ta+tb+tc);
    }
  }
  return retval;
}
