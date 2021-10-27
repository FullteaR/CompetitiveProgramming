#include <iostream>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Point{
    long index, r, c, a, score;
}typedef Point;

int main(void){
    long H,W,N;
    cin>>H>>W>>N;

    Point* points = new Point[N];
    for(int i=0;i<N;i++){
        points[i].index=i;
        long r,c,a;
        cin>>r>>c>>a;
        points[i].r = r;
        points[i].c = c;
        points[i].a = a;
        points[i].score=0;
    }
    map<long, unordered_set<Point> > rs, cs;
    rs.clear();
    cs.clear();
    for(long r=1;r<=H;r++){
        rs[r].clear();
    }
    for(long c=1;c<=W;c++){
        cs[c].clear();
    }
    for(long i=0;i<N;i++){
        Point point = points[i];
        rs[point.r].insert(point);
        cs[point.c].insert(point);
    }
    sort(points, points+N, [](const Point& lp, const Point& rp){
        return lp.a<rp.a;
    });
    reverse(points, points+N);
}