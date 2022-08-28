#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main(void){
    int N,Q;
    cin>>N>>Q;
    int* array = new int[N];
    map<int, int> d;
    d.clear();
    for(int i=0;i<N;i++){
        array[i] = i;
        d[i] = i;
    }

    for(int q=0;q<Q;q++){
        int x;
        cin>>x;
        x--;
        int index = d[x];
        int other_index = index+1;
        if(other_index==N){
            other_index = N-2;
        }

        int x1 = array[index];
        int x2 = array[other_index];
        d[x1] = other_index;
        d[x2] = index;
        array[index] = x2;
        array[other_index] = x1;
    }

    for(int i=0;i<N;i++){
        cout<<array[i]+1;
        if(i<N-1){
            cout<<" ";
        }
        else{
            cout<<endl;
        }
    }

    return 0;
}