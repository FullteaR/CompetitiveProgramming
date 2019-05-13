#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){
        int H,W;
        while(1) {
                cin>>H>>W;
                if (H==0 and W==0) {
                        return 0;
                }
                for(int i=0; i<H; i++) {
                        for(int j=0; j<W; j++) {
                                if((i+j)%2==0) {
                                        printf("#");
                                }
                                else{
                                        printf(".");
                                }
                        }
                        printf("\n");
                }
                printf("\n");
        }
}
