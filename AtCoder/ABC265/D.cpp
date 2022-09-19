#include <iostream>
#include <cassert>
using namespace std;

bool check(long* A, const long left, const long P, const long Q);

int main(void) {
    long N,P,Q,R;
    cin>>N>>P>>Q>>R;
    N+=2;
    long* A = new long[N];
    A[0] = 0;
    A[N-1] = 0;
    for(long i=1;i<N-1;i++){
        cin>>A[i];
    }
    long s = 0;
    long left = 0;
    long right = 0;
    bool success = false;
    cout<<endl;
    while(left<N-1) {
        if(right==N-1) {
            s-=A[left];
            left++;
        }
        else {
            if(s>P+R+Q) {
                s-=A[left];
                left++;
            }
            else {
                right++;
                s+=A[right];
            }
        }
        if(s==P+Q+R) {
            success = success || check(A,left,P,Q);
            if(success) {
                break;
            }
        }
    }
    if(success) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }

}

bool check(long* A, const long left, const long P, const long Q) {
    long p=0;
    long q=0;
    long i=left;
    while(p<P) {
        p+=A[i];
        i++;
    }
    if(p!=P) {
        return false;
    }
    while(q<Q) {
        q+=A[i];
        i++;
    }
    if(q!=Q) {
        return false;
    }
    return true;
}