#include <iostream>
using namespace std;

int main(void){
    int A,B,C;
    cin>>A>>B>>C;
    int coin_per_week=7*A+B;
    int day=0;

    day=(C/coin_per_week)*7;
    int rest=C%coin_per_week;
    if(rest==0){;}
    else if(rest<=A){day+=1;}
    else if(rest<=2*A){day+=2;}
    else if(rest<=3*A){day+=3;}
    else if(rest<=4*A){day+=4;}
    else if(rest<=5*A){day+=5;}
    else if(rest<=6*A){day+=6;}
    else{day+=7;}
    cout<<day<<endl;
    return 0;
}
