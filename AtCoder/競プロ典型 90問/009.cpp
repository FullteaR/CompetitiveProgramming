#include<iostream>
#include <vector>
using namespace std;

class Point{
    public:
        Point(long x, long y);
        long x;
        long y;
};

Point::Point(long x, long y) {
    this->x = x;
    this->y = y;
}

int main(void) {
    long N;
    cin>>N;
    vector<Point> v;
    v.clear();
    for(long i=0;i<N;i++){
        long x, y;
        cin>>x>>y;
        Point p = Point(x,y);
        v.push_back(p);
    }
}