#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

long lower(long A, long N);
long upper(long A, long N);
void solve(long r, long t);



int main(void){
    long N;
    cin>>N;
    for(long i=0;i<N;i++){
        long r,t;
        cin>>r>>t;
        solve(r,t);
    }
}

void solve(long r, long t){
    vector<long> s;
    s.clear();
    s.push_back(lower(t,30)*5+lower(r,100));
    s.push_back(lower(t,30)*5+upper(r,100));
    s.push_back(upper(t,30)*5+lower(r,100));
    s.push_back(upper(t,30)*5+upper(r,100));
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for(int i=0;i<s.size();i++){
        cout<<s[i];
        if(i<s.size()-1){
            cout<<" ";
        }
        else{
            cout<<endl;
        }
    }
}

long lower(long A, long N){
    return A/N;
}
long upper(long A, long N){
    if(A%N==0){
        return A/N;
    }
    return A/N+1;
}