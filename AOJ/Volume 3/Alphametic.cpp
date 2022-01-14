#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int given[9];
    for(int i=0;i<9;i++){
        cin>>given[i];
    }
    long long count = 0;
    do {
        bool ok = true;
        for(int i=0;i<9;i++){
            if(given[i]!=-1 and given[i]!=v[i]){
                ok = false;
            }
        }
        if(ok){
            if(v[0]+v[1]*10+v[2]+v[3]*100+v[4]*10+v[5] == v[6]*100+v[7]*10+v[8]){
                count++;
            }
        }
    } while (next_permutation(v.begin(), v.end()));

    cout<<count<<endl;

    return 0;
}