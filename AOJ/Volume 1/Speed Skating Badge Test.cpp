#include <iostream>
using namespace std;

int main(void){
  double t500,t1000;
  int r500,r1000,rank;
  while(cin>>t500>>t1000){
    if(t500<35.5)r500=0;
    else if(t500<37.5)r500=1;
    else if(t500<40)r500=2;
    else if(t500<43)r500=3;
    else if(t500<50)r500=4;
    else if(t500<55)r500=5;
    else if(t500<70)r500=6;
    else r500=7;
    if(t1000<71)r1000=0;
    else if(t1000<77)r1000=1;
    else if(t1000<83)r1000=2;
    else if(t1000<89)r1000=3;
    else if(t1000<105)r1000=4;
    else if(t1000<116)r1000=5;
    else if(t1000<148)r1000=6;
    else r1000=7;
    rank=max(r500,r1000);
    switch (rank) {
      case 0:
        cout<<"AAA"<<endl;
        break;
      case 1:
        cout<<"AA"<<endl;
        break;
      case 2:
        cout<<"A"<<endl;
        break;
      case 3:
        cout<<"B"<<endl;
        break;
      case 4:
        cout<<"C"<<endl;
        break;
      case 5:
        cout<<"D"<<endl;
        break;
      case 6:
        cout<<"E"<<endl;
        break;
      case 7:
        cout<<"NA"<<endl;
        break;
    }
  }
  return 0;
}
