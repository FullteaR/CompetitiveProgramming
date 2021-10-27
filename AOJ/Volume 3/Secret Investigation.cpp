#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void){
    set<int> a,b,c;
    a.clear();
    b.clear();
    c.clear();
    int N,X,Y,Z;
    cin>>N;
    cin>>X;
    for(int i=0;i<X;i++){
        int _a;
        cin>>_a;
        a.insert(_a);
    }
    cin>>Y;
    for(int i=0;i<Y;i++){
        int _b;
        cin>>_b;
        b.insert(_b);
    }

    cin>>Z;
    for(int i=0;i<Z;i++){
        int _c;
        cin>>_c;
        c.insert(_c);
    }

    set<int> c_minus_a;
    set_difference(c.begin(), c.end(), a.begin(), a.end(), inserter(c_minus_a, c_minus_a.end()));
    set<int> b_plus_c;
    set_intersection(c.begin(), c.end(), b.begin(), b.end(), inserter(b_plus_c, b_plus_c.end()));
    set<int> retval;
    set_union(b_plus_c.begin(), b_plus_c.end(), c_minus_a.begin(), c_minus_a.end(), inserter(retval, retval.end()));
    cout<<retval.size()<<endl;
    return 0;
}