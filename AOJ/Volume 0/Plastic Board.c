#include <stdio.h>

int main(void){
    int a,b,c;
    int rect=0;
    int dia=0;
    while(scanf("%d,%d,%d",&a,&b,&c)!=EOF){
        if(a*a+b*b==c*c){
            rect+=1;
        }
        if(a==b){
            dia+=1;
        }
    }
    printf("%d\n%d\n",rect,dia);
}
