#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
        vector<int> mountain;
        int tmp;
        for(int i=0; i<10; i++) {
                cin>>tmp;
                mountain.push_back(tmp);
        }
        sort(mountain.begin(),mountain.end(),greater<int>());
        for(int i=0; i<3; i++) {
                cout<<mountain[i]<<endl;
        }
        return 0;
}
