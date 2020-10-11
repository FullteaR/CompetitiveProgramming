#include <stdlib.h>
#include <stdio.h>

struct Confectionery {
        int s;
        int p;
        int q;
        int r;
} typedef conf;

int main(void){
        while(1) {
                int n,P,Q,R,C,calorie;
                int NA=0;
                scanf("%d",&n);
                if(n==0) break;
                conf* confs = (conf*)malloc(n*sizeof(conf));
                for(int i=0; i<n; i++) {
                        int s,p,q,r;
                        scanf("%d %d %d %d",&s,&p,&q,&r);
                        confs[i].s=s;
                        confs[i].p=p;
                        confs[i].q=q;
                        confs[i].r=r;
                }
                scanf("%d %d %d %d",&P,&Q,&R,&C);
                for(int i=0; i<n; i++) {
                        calorie = confs[i].p*4+confs[i].q*9+confs[i].r*4;
                        if(calorie<=C && confs[i].p<=P && confs[i].q<=Q && confs[i].r<=R) {
                                NA=1;
                                printf("%d\n",confs[i].s);
                        }
                }
                if(NA==0) {
                        printf("NA\n");
                }
        }
        return 0;
}
