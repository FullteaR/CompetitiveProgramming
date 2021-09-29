#include <iostream>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#define INF 2000000010
using namespace std;

class Point;
long gcd(long a, long b);
long score_trapezium(pair<Point, Point> *p12, pair<Point, Point> *p34);
double get_arg_cos(Point *p1, Point *p2, Point *p3);

class Point{
    public:
        long x;
        long y;
        long C;
        Point(){
            ;
        }
        Point(long _x, long _y, long _C){
            x = _x;
            y = _y;
            C = _C;
        };

        bool operator == (const Point& b) const{
            return x==b.x and y==b.y;
        }
        bool operator < (const Point& b) const{
            if(x == b.x){
                return y < b.y;
            }
            else{
                return x < b.x;
            }
        }
};




int main(void){
    long N;
    cin>>N;
    Point *points = new Point[N];
    for(long i=0;i<N;i++){
        long x,y,C;
        cin>>x>>y>>C;
        points[i] = Point(x,y,C);
    }
    map<pair<long,long>, vector<pair<Point, Point> > >d ;
    for(long i=0;i<N;i++){
        for(long j=i+1;j<N;j++){
            Point p1 = points[i];
            Point p2 = points[j];
            long linear_up = p2.y-p1.y;
            long linear_down = p2.x-p1.x;
            if(linear_up<0){
                linear_up*=-1;
                linear_down*=-1;
            }
            long g = gcd(abs(linear_up), abs(linear_down));
            d[make_pair(linear_up/g, linear_down/g)].push_back(make_pair(p1, p2));
        }
    }

    long score = -1;
    for(auto iter : d){
        vector<pair<Point, Point> > value = iter.second;
        for(long i=0;i<value.size();i++){
            for(long j=i+1;j<value.size();j++){
                if(value[i].first == value[j].first or value[i].first == value[j].second or value[i].second == value[j].first or value[i].second == value[j].second){
                    continue;
                }
                score = max(score, score_trapezium(&(value[i]), &(value[j])));
            }
        }
    }
    cout<<score<<endl;
    return 0;
}

long gcd(long a, long b){
    if(min(a,b)==0){return max(a,b);}
    return gcd(min(a,b), max(a,b)%min(a,b));
}

long score_trapezium(pair<Point, Point> *p12, pair<Point, Point> *p34){
    Point p1 = p12->first;
    Point p2 = p12->second;
    Point p3 = p34->first;
    Point p4 = p34->second;
    double th1 = get_arg_cos(&p1,&p2,&p3);
    double th2 = get_arg_cos(&p2,&p1,&p4);
    if(abs(th1-th2)<0.00000001 and abs(th1)<0.999999999){
        return p1.C+p2.C+p3.C+p4.C;
    }
    return -1;
}

double get_arg_cos(Point *p1, Point *p2, Point *p3){
    long x1 = p1->x - p2->x;
    long y1 = p1->y - p2->y;
    long x2 = p3->x - p2->x;
    long y2 = p3->y - p2->y;
    return (x1*x2+y1*y2)*1.0/sqrt((x1*x1+y1*y1)*(x2*x2+y2*y2));
}