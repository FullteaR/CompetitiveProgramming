#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int min(vector<int>* h);
int argmin(vector<int>* h);
int solve(vector<int>* h);

int main(void){
    int N;
    cin>>N;
    vector<int> h;
    h.clear();
    for(int i=0;i<N;i++){
        int _h;
        cin>>_h;
        h.push_back(_h);
    }
    cout<<solve(&h)<<endl;
    return 0; 
}

int min(vector<int>* h){
    assert(h->size()>0);
    int retval = (*h)[0];
    for(int i=1;i<h->size();i++){
        if((*h)[i]<retval){
            retval = (*h)[i];
        }
    }
    return retval;
}
int argmin(vector<int>* h){
    int m = min(h);
    for(int i=0;i<h->size();i++){
        if((*h)[i]==m){
            return i;
        }
    }
    return -1;
}
int solve(vector<int>* h){
    if(h->size()==0){
        return 0;
    }
    int min_index = argmin(h);
    int min_value = (*h)[min_index];
    vector<int> l,r;
    l.clear();
    r.clear();
    for(int i=0;i<min_index;i++){
        l.push_back((*h)[i]-min_value);
    }
    for(int i=min_index+1;i<h->size();i++){
        r.push_back((*h)[i]-min_value);
    }
    return min_value + solve(&l) + solve(&r);
}