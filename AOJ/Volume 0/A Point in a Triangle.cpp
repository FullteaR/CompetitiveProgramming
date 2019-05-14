#include <iostream>
using namespace std;

bool f(double x1,double y1,double x2,double y2,double x,double y);



int main(void){
        double x1,y1,x2,y2,x3,y3,xp,yp;
        double xm,ym;
        while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>xp>>yp) {
                xm=(x1+x2+x3)/3;
                ym=(y1+y2+y3)/3;
                if(f(x1,y1,x2,y2,xp,yp)==f(x1,y1,x2,y2,xm,ym) and f(x1,y1,x3,y3,xp,yp)==f(x1,y1,x3,y3,xm,ym) and f(x3,y3,x2,y2,xp,yp)==f(x3,y3,x2,y2,xm,ym)) {
                        cout<<"YES"<<endl;
                }
                else{
                        cout<<"NO"<<endl;
                }

        }
        return 0;
}

bool f(double x1,double y1,double x2,double y2,double x,double y){
        return (y2-y1)*x-(x2-x1)*y-x1*y2+x2*y1 > 0;
}
