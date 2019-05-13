#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){
        int buildings[4][3][10]={0};
        int n;
        cin>>n;
        int b,f,r,v;
        for(int i=0; i<n; i++) {
                cin>>b>>f>>r>>v;
                buildings[b-1][f-1][r-1]+=v;
        }
        for(int i=0; i<4; i++) {
                for(int j=0; j<3; j++) {
                        for(int k=0; k<10; k++) {
                                printf(" %d",buildings[i][j][k]);
                        }
                        printf("\n");
                }
                if(i!=3) {
                        printf("####################\n");
                }
        }
        return 0;

}
