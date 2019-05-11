#include <iostream>
#include <stdio.h>
using namespace std;
int main(void){
        int a,b;
        cin>>a>>b;
        int d,r;
        double f;
        d=a/b;
        r=a%b;
        f=(double)a/(double)b;
        printf("%d %d %lf",d,r,f);
        return 0;
}
