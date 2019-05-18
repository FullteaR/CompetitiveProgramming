#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int island(int sea,vector<long long> A);

int main(void){
        int N;
        cin>>N;
        long long _A[100010];
        _A[0]=-1;
        for(int i=1; i<N+1; i++) {
                cin>>_A[i];
        }
        _A[N+1]=-1;


        vector<long long> A;
        A.push_back(-1);
        for(int i=1; i<N+1; i++) {
                if(_A[i-1]<_A[i] and _A[i]<_A[i+1]);
                else if(_A[i-1]>_A[i] and _A[i]>_A[i+1]);
                else if(_A[i-1]==_A[i] and _A[i]==_A[i+1]);
                else{A.push_back(_A[i]);}
        }

        A.push_back(-1);

        vector<long long> mountain;
        for(int i=0; i<A.size(); i++) {
                if(A[i]!=-1) {
                        mountain.push_back(A[i]);
                }
        }
        sort(mountain.begin(),mountain.end());
        mountain.erase(unique(mountain.begin(), mountain.end()), mountain.end());




        int retval=island(0,A);

        for(int i=0; i<mountain.size(); i++) {
                retval=max(retval,island(mountain[i],A));
        }
        cout<<retval<<endl;


        return 0;
}

int island(int sea,vector<long long> A){
        int island=0;
        int N=A.size();
        for(int i=0; i<N-1; i++) {
                if(A[i]<=sea and A[i+1]>sea) {
                        island++;
                }
        }
        return island;
}
