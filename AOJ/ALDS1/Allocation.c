#include <stdio.h>
#include <stdlib.h>


int able(int p,int n, int k, int* w);
long long minimum(int n,int k,int* w);

int main(void){
    int n,k;
    scanf("%d %d",&n,&k);
    int* w = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&(w[i]));
    }
    printf("%lld\n",minimum(n,k,w));
    return 0;
}

int able(int p,int n,int k,int* w){
    int truck=1;
    long weight=0;
    for(int i=0;i<n;i++){
        if(w[i]>p){
            return 0;
        }
        if(weight+w[i]>p){
            truck+=1;
            weight=0;
        }
        weight+=w[i];
    }
    if(truck>k){
        return 0;
    }
    else{
        return 1;
    }
}

long long minimum(int n,int k,int* w){
    long long min,max,mid;
    min=0;
    max=1000000010;
    while(min+1<max){
        mid=(min+max)/2;
        if(able(mid,n,k,w)){
            max=mid;
        }
        else{
            min=mid;
        }
    }
    for(long long i=min;i<=max;i++){
        if(able(i,n,k,w)){
            return i;
        }
    }
}
