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
                for(int j=0; j<W; j++) {
                        printf("#");
                }
                printf("\n");
                for(int i=0; i<H-2; i++) {
                        printf("#");
                        for(int j=0; j<W-2; j++) {
                                printf(".");
                        }
                        printf("#\n");
                }
                for(int j=0; j<W; j++) {
                        printf("#");
                }
                printf("\n\n");
        }
}
