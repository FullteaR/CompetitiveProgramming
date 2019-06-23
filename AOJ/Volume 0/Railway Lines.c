#include <stdio.h>

int main(void){
    int l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,v1,v2;
    int l[10];
    int dist=0;
    double cross;
    int adv;
    while(scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&l1,&l2,&l3,&l4,&l5,&l6,&l7,&l8,&l9,&l10,&v1,&v2)!=EOF){
        dist=0;
        l[0]=l1;
        l[1]=l2;
        l[2]=l3;
        l[3]=l4;
        l[4]=l5;
        l[5]=l6;
        l[6]=l7;
        l[7]=l8;
        l[8]=l9;
        l[9]=l10;
        for(int i=0;i<10;i++){
            dist+=l[i];
        }
        cross=(double)dist*v1/(v1+v2);
        adv=0;
        for(int i=0;i<10;i++){
            if(adv<cross && adv+l[i]>=cross){
                printf("%d\n",i+1);
            }
            adv+=l[i];
        }
    }
    return 0;
}
