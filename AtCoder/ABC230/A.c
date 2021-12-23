#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    if(N>=42){
        N++;
    }
    printf("AGC%03d\n", N);
    return 0;
}