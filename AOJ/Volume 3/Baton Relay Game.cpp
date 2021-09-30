#include <iostream>
#include <set>
#include <vector>
#include <cassert>
using namespace std;

int main(void){
    int N,M,Q;
    cin>>N>>M>>Q;
    int * a = new int[M];
    for(int i=0;i<M;i++){
        cin>>a[i];
    }
    int * q = new int[Q];
    for(int i=0;i<Q;i++){
        cin>>q[i];
    }
    vector<int> students;
    students.clear();
    for(int i=0;i<N;i++){
        students.push_back(i);
    }
    int index = 0;

    for(int i=0;i<M;i++){
        if(a[i]%2==0){
            index -= a[i];
        }
        else{
            index += a[i];
        }
        index = index % students.size();
        if(index<0){
            index+=students.size();
        }
        assert(0<=index and index<students.size());
        students.erase(students.begin()+index);
    }
    set<int> last_students(students.begin(), students.end());
    for(int i=0;i<Q;i++){
        if(last_students.find(q[i])!=last_students.end()){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }

    return 0;
}