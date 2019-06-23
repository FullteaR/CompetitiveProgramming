#include <stdio.h>
#include <math.h>

int prime(int x);

int main(void){
    int n;
    int x;
    int retval=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        retval+=prime(x);
    }
    printf("%d\n",retval);
    return 0;
}

int prime(int x){
    if(x==1){return 0;}
    if(x==2){return 1;}
    for(int i=2;i<sqrt(x)+1;i++){
        if ((x/i)*i==x){return 0;}
    }
    return 1;
}
