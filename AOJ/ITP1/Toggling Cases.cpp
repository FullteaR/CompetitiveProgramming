#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
        char input[1300];
        scanf("%[^\n]",input,stdin);
        int i=0;
        char c;
        while(c=input[i++]) {
                if('a'<=c and c<='z') {
                        printf("%c",c-'a'+'A');
                }
                else if('A'<=c and c<='Z') {
                        printf("%c",c-'A'+'a');
                }
                else{
                        printf("%c",c);
                }
        }
        printf("\n");
        return 0;
}
