#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void){
    vector<long> scores;
    scores.clear();
    map<long, long> students;
    students.clear();
    long N,K;
    cin>>N>>K;
    for(long i=0;i<N;i++){
        long P,P1,P2,P3;
        cin>>P1>>P2>>P3;
        P = P1+P2+P3;
        scores.push_back(P);
        students[i] = P;
    }
    sort(scores.begin(), scores.end());
    long th = scores[N-K];

    for(long i=0;i<N;i++){
        if(th-students[i]<=300){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }


    return 0;
}