#include <stdio.h>

int main(void){
    int N,L;
    scanf("%d %d",&N,&L);
    int taste=0;
    if(L<=0 && L+N-1>=0){
        for(int i=1;i<=N;i++){
            taste+=L+i-1;
        }
    }
    else if(L+N-1<0){
        for(int i=1;i<=N-1;i++){
            taste+=L+i-1;
        }
    }
    else{
        for(int i=2;i<=N;i++){
            taste+=L+i-1;
        }
    }
    printf("%d\n",taste);
    return 0;
}
