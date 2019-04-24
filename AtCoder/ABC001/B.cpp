#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){
    double m=0;
    int VV=0;
    cin>>m;
    m=m/1000.0;

    if(m<0.1){

    }
    else if(m<=5){
        VV=m*10;
    }
    else if(m<=30){
        VV=m+50;
    }
    else if(m<=70){
        VV=80+(m-30)/5;
    }
    else{
        VV=89;
    }
    printf("%02d\n",VV);
}
