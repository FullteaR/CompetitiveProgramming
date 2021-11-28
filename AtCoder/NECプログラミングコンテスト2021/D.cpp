#include <iostream>
#include <vector>
using namespace std;

bool isAble(long length, long K, vector<long>* mul);
long solve(long K, vector<long>* mul);


int main(void){
    string S;
    cin>>S;
    long K;
    cin>>K;
    vector<long> mul;
    mul.clear();
    mul.push_back(0);
    for(long i=0;i<S.size();i++){
        if(S[i]=='.'){
            mul.push_back(mul[i]+1);
        }
        else{
            mul.push_back(mul[i]);
        }
    }

    cout<<solve(K, &mul)<<endl;


    return 0;
}

bool isAble(long length, long K, vector<long>* mul){
    if(length<=0){
        return true;
    }
    else if(length>mul->size()-1){
        return false;
    }

    for(long i=length;i<mul->size();i++){
        if((*mul)[i] - (*mul)[i-length]<=K){
            return true;
        }
    }
    return false;
}

long solve(long K, vector<long>* mul){
    long m = 0;
    long M = mul->size();
    while(M-m>1){
        long mid = (M+m)/2;
        if(isAble(mid, K, mul)){
            m = mid;
        }
        else{
            M = mid;
        }
    }
    if(isAble(M, K , mul)){
        return M;
    }
    else{
        return m;
    }
}