#include <iostream>
using namespace std;

int cost(int water);

int main(void){
  int water;
  while(1){
    cin>>water;
    if(water==-1){return 0;}
    cout<<4280-cost(water)<<endl;
  }
}

int cost(int water){
  if(water<10){
    return 1150;
  }
  else if(water<20){
    return 1150+125*(water-10);
  }
  else if(water<30){
    return 1150+125*10+140*(water-20);
  }
  else{
    return 1150+125*10+140*10+160*(water-30);
  }
}
