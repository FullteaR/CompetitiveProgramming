#include <iostream>
#include <cstdio>
using namespace std;

long time2ind(long t);
long ind2time(long ind);

int main(void){
  bool* rain = new bool[60*24+10];
  for(long t=0;t<60*24+10;t++){
    rain[t]=false;
  }
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    long S,E;
    scanf("%ld-%ld",&S,&E);
    for(long ind=time2ind(S);ind<=time2ind(E);ind++){
      rain[ind]=true;
    }
  }
  bool rainy=false;
  long S,E;
  for(long ind=0;ind<=24*60;ind+=5){
    if(rainy){
      if(!rain[ind+1] and !rain[ind+2] and !rain[ind+3] and !rain[ind+4]){
        rainy=false;
        E=ind;
        printf("%04ld-%04ld\n",ind2time(S),ind2time(E));
      }
    }
    else{
      if(rain[ind] or rain[ind+1] or rain[ind+2] or rain[ind+3] or rain[ind+4]){
        rainy=true;
        S=ind;
      }
    }
  }
  if(rainy){
    printf("%04ld-2400\n",ind2time(S));
  }
  return 0;
}
long time2ind(long t){
  long h=t/100;
  long m=t%100;
  return h*60+m;
}
long ind2time(long ind){
  long h=ind/60;
  long m=ind%60;
  return h*100+m;
}
