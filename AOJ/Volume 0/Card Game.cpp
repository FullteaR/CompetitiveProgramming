#include <iostream>
#include <map>
using namespace std;

int main(void){
  int c1,c2,c3;
  while(cin>>c1>>c2>>c3){
    map<int,int> deck;
    for(int i=1;i<=10;i++){
      deck[i]=1;
    }
    deck[c1]-=1;
    deck[c2]-=1;
    deck[c3]-=1;
    double prob=0;
    for(int i=1;i<=20-c1-c2;i++){
      prob+=(double)(deck[i])/7;
    }
    if(prob>=0.5){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
