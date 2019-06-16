#include <iostream>
#include <math.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2);

int main(void){
        int n;
        cin>>n;
        double xa,ya,ra,xb,yb,rb;
        double d;
        for(int i=0; i<n; i++) {
                cin>>xa>>ya>>ra>>xb>>yb>>rb;
                d=dist(xa,ya,xb,yb);
                if(d>ra+rb) {
                        cout<<0<<endl;
                }
                else if(d+rb<ra) {
                        cout<<2<<endl;
                }
                else if(d+ra<rb) {
                        cout<< -2<<endl;
                }
                else{
                        cout<<1<<endl;
                }
        }
        return 0;
}

double dist(double x1, double y1, double x2, double y2){
        return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
