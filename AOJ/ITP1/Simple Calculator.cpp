#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){
        char op;
        int a,b;
        int retval;
        while(1) {
                scanf("%d %c %d",&a,&op,&b);


                switch(op) {
                case '+':
                        retval=a+b;
                        break;
                case '-':
                        retval=a-b;
                        break;
                case '*':
                        retval=a*b;
                        break;
                case '/':
                        retval=a/b;
                        break;
                case '?':
                        return 0;
                }
                cout<<retval<<endl;
        }

}
