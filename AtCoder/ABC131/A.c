#include <stdio.h>

int main(void){
    int S;
    scanf("%d",&S);
    if(S/1000==(S/100)%10){
        printf("Bad\n");
    }
    else if((S/100)%10==(S/10)%10){
        printf("Bad\n");
    }
    else if((S/10)%10==S%10){
        printf("Bad\n");
    }
    else{
        printf("Good\n");
    }
    return 0;
}
