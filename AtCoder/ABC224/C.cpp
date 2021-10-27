#include <iostream>
#include <utility>
using namespace std;

long area(pair<long, long> p1,pair<long, long> p2,pair<long, long> p3);

int main(void){
    int N;
    cin>>N;
    pair<long, long>* points = new pair<long, long> [N];
    for(int i=0;i<N;i++){
        long X,Y;
        cin>>X>>Y;
        points[i] = make_pair(X,Y);
    }
    long count=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=j+1;k<N;k++){
                if(area(points[i],points[j],points[k])>0){
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;
    return 0;
}

long area(pair<long, long> p1,pair<long, long> p2,pair<long, long> p3){
    //return area*2;
    long a,b,c,d;
    a = p2.first-p1.first;
    b = p2.second-p1.second;
    c = p3.first-p1.first;
    d = p3.second-p1.second;
    return abs(a*d - b*c);
}