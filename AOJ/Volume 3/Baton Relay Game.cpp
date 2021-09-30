#include <iostream>
#include <unordered_set>
#include <vector>
#include <cassert>
#include <numeric>
using namespace std;

class LinkedList{
    public:
        long number;
        LinkedList *before, *after;

        LinkedList(long n){
            before = 0x0;
            after = 0x0;
            number = n;
        }
        LinkedList(void){
            before = 0x0;
            after = 0x0;
            number = -1;
        }
        void connect(LinkedList* l){
            after = l;
            l -> before = this;
        }
        void set(long n){
            number = n;
        }

        void print(void){
            cout<<"before pointer:\t"<<before<<endl;
            cout<<"self pointer:\t"<<this<<endl;
            cout<<"after pointer:\t"<<after<<endl;
            cout<<"value\t"<<number<<endl;
        }
};


int main(void){
    long N,M,Q;
    cin>>N>>M>>Q;
    long * a = new long[M];
    for(long i=0;i<M;i++){
        cin>>a[i];
    }
    long * q = new long[Q];
    for(long i=0;i<Q;i++){
        cin>>q[i];
    }

    LinkedList * lists = new LinkedList[N];
    lists[0].set(0);
    for(int i=1;i<N;i++){
        lists[i] = LinkedList(i);
        lists[i-1].connect(&(lists[i]));
    }
    lists[N-1].connect(&(lists[0]));

    LinkedList* index = &(lists[0]);
    
    for(long i=0;i<M;i++){
        if(a[i]%2==0){
            for(int j=0;j<a[i];j++){
                index = index -> after;
            }
        }
        else{
            for(int j=0;j<a[i];j++){
                index = index -> before;
            }
        }
        index -> before -> after = index -> after;
        index -> after -> before = index -> before;

        index = index -> after; // メモリリークしていることに注意。まあ競技プログラミングなんで...。
    }
    unordered_set<long> last_students;
    last_students.clear();
    for(int i=0;i<N-M+1;i++){
        last_students.insert(index->number);
        index = index->after;
    }

    for(long i=0;i<Q;i++){
        if(last_students.find(q[i])!=last_students.end()){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }

    

    return 0;
}