#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(void){
    int N;
    cin>>N;
    vector<pair<int,int> > v;
    v.clear();
    double t = 0;
    for(int i=0;i<N;i++){
        int A,B;
        cin>>A>>B;
        v.push_back(make_pair(A,B));
        t+=A*1.0/B;
    }
    double retval = 0;
    t = t/2;
    for(int i=0;i<N;i++){
        int A = v[i].first;
        int B = v[i].second;
        if(t>A*1.0/B){
            t-=A*1.0/B;
            retval+=A;
        }
        else{
            retval+=t*B;
            cout<<retval<<endl;
            return 0;
        }
    }
}