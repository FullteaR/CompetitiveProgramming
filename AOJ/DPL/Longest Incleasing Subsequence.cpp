#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

#include <map>
using namespace std;

int main(void){
        int n;
        cin>>n;


        vector<long> A;
        vector<long> _A_sort;
        vector<long> A_sort;
        long a;
        for(int i=0; i<n; i++) {
                cin>>a;
                A.push_back(a);
                _A_sort.push_back(a);
        }
        sort(_A_sort.begin(),_A_sort.end());

        A_sort.push_back(_A_sort[0]);

        for(int i=1; i<n; i++) {
                if(A_sort[A_sort.size()-1]!=_A_sort[i]) {
                        A_sort.push_back(_A_sort[i]);
                }
        }
        map<long,long> d;
        for(long i=0; i<A_sort.size(); i++) {
                d[A_sort[i]]=i+1;
        }
        for(int i=0; i<n; i++) {
                A[i]=d[A[i]];
        }

        int counter[n];
        for(int i=0; i<n; i++) {
                counter[i]=1;
        }

        for(int i=0; i<n; i++) {
                for(int j=i-1; j>=0; j--) {
                        if(A[j]<A[i]) {
                                counter[i]=max(counter[i],counter[j]+1);
                                if(A[j]+1==A[i]){
                                        break;
                                }
                        }
                        else if(A[j]==A[i]) {
                                counter[i]=max(counter[j],counter[i]);
                                break;
                        }
                        else if(A[j]>A[i] && counter[j]<=counter[i]) {
                                break;
                        }

                }
        }

        int retval=0;
        for(int i=0; i<n; i++) {
                retval=max(counter[i],retval);
        }
        cout<<retval<<endl;



        return 0;
}
