#include <iostream>
#include <unordered_set>
#include <map>
#include <cassert>
using namespace std;

long max(unordered_set<long> *S);
long min(unordered_set<long> *S);

int main(void){
    long N;
    cin>>N;
    long long* d = new long long[N];
    for(long i=0;i<N;i++){
        cin>>d[i];
    }
    long long* accumurate = new long long[N+1];
    accumurate[0] = 0;
    for(long i=0;i<N;i++){
        accumurate[i+1] = accumurate[i] + d[i];
    }
    //accumurate[j+1]==accumurate[i] のときの j-iの最大値が知りたい

    map<long long, unordered_set<long> > count;
    assert(count.empty());
    for(long i=0;i<=N;i++){
        count[accumurate[i]].clear();
    }
    for(long i=0;i<=N;i++){
        count[accumurate[i]].insert(i);
    }

    long retval = 0;
    for(auto item : count){
        long long key = item.first;
        unordered_set<long> value = item.second;
        retval = max(retval, max(&value)-min(&value));
    }
    cout<<retval<<endl;
    return 0;
}


long max(unordered_set<long> *S){
    long M = -1000000010;
    for(long s:*S){
        if(M<s){
            M = s;
        }
    }
    return M;
}

long min(unordered_set<long> *S){
    long m = 1000000010;
    for(long s:*S){
        if(m>s){
            m = s;
        }
    }
    return m;
}