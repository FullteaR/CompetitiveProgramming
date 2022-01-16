#include <iostream>
#include <set>
using namespace std;

int main(void){
    int N;
    cin>>N;
    set<set<int> > s;
    s.clear();
    for(int i=0;i<N;i++){
        set<int> _s;
        _s.clear();
        int p1,p2,p3;
        cin>>p1>>p2>>p3;
        _s.insert(p1);
        _s.insert(p2);
        _s.insert(p3);
        s.insert(_s);
    }
    cout<<N-s.size()<<endl;
    return 0;
}