#include <iostream>
#include <vector>
#include <set>
#define INF 1000000010
using namespace std;

int main(void){
    long long N;
    cin>>N;
    long long* T = new long long[N];
    long long total=0;
    for(long long i=0;i<N;i++){
        cin>>T[i];
        total+=T[i];
    }
    set<long long> s;
    s.clear();
    s.insert(0);
    for(int i=0;i<N;i++){
        set <long long> tmp;
        tmp.clear();
        for(auto iter=s.begin();iter!=s.end();iter++){
            tmp.insert(*iter+T[i]);
        }
        for(auto iter=tmp.begin();iter!=tmp.end();iter++){
            s.insert(*iter);
        }
    }
    long long retval=INF;
    for(auto iter=s.begin();iter!=s.end();iter++){
        retval=min(retval, max(*iter, total-*iter));
    }
    cout<<retval<<endl;
    return 0;
}