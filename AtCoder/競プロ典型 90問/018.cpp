#include <iostream>
#include <cmath>
using namespace std;

class Point{
    public:
        double x;
        double y;
        double z;
        Point(double x,double y,double z);
};

Point::Point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double angle(Point& p1, Point& p2);
Point ferris(double E, double T, double L);
double size(Point& p);

int main(void){
    long T;
    double L,X,Y;
    cin>>T;
    cin>>L>>X>>Y;
    long Q;
    cin>>Q;
    for(double q=0;q<Q;q++){
        double E;
        cin>>E;
        Point p = ferris(E,T,L);
        Point v1 = Point(p.x-X,p.y-Y,p.z);
        Point v2 = Point(p.x-X,p.y-Y,0);
        double retval = abs(angle(v1,v2));
        printf("%.16f\n", min(retval, 180-retval));
    }
    return 0;
}

Point ferris(double E, double T, double L) {
    double angle = -1*M_PI*2*E/T+3*M_PI/2;
    double x = 0;
    double y = L*cos(angle)/2;
    double z = L*sin(angle)/2+L/2;
    return Point(x,y,z);
}

double angle(Point& p1, Point& p2) {
    double cross = (p1.x*p2.x+p1.y*p2.y+p1.z*p2.z) / (size(p1)*size(p2));
    return acos(cross)*180/M_PI;
}

double size(Point& p){
    return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}