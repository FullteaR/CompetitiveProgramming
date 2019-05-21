#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


int main(void){
    int n;
    cin>>n;

    int base[4]={0};
    int score=0;
    int out=0;
    char s[100];
    while(scanf("%s",s,stdin)!=EOF){
        if(strcmp(s,"HIT")==0){
            score+=base[3];
            base[3]=base[2];
            base[2]=base[1];
            base[1]=1;
        }
        if(strcmp(s,"HOMERUN")==0){
            score+=(base[3]+base[2]+base[1]+1);
            base[1]=0;
            base[2]=0;
            base[3]=0;
        }
        if(strcmp(s,"OUT")==0){
            out+=1;
            if(out==3){
                out=0;
                base[1]=0;
                base[2]=0;
                base[3]=0;
                cout<<score<<endl;
                score=0;
            }
        }
    }
    return 0;
}
