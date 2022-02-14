#include <iostream>
#include <vector>
#include <sstream>
#define INF 10000000100

using namespace std;

int main(void){
    long N;
    cin>>N;
    //A(i+2) = Si-Ai-A(i+1)
    //A0=a
    //A1=b
    //A2=S0-a-b
    //A3=S1-S0+a
    //A4=S2-S1+b
    //A5=S3-S2+S0-a-b
    //A6=S4-S3+S1-S0+a
    //A7=S5-S4+S2-S1+b
    //A8=S6-S5+S3-S2+S0-a-b
    //
    //xi=S0+S3+...+S3i
    //yi=S1+S4+...+S3i-2
    //zi=S2+S5+...+S3i-1として
    //A3i=yi-x(i-1)+a
    //A3i+1=zi-yi+b
    //A3i+2=xi-zi-a-b
    long* S = new long[N];
    for(int i=0;i<N;i++){
        cin>>S[i];
    }
    vector<long> x,y,z;
    x.clear();
    y.clear();
    z.clear();
    x.push_back(S[0]);
    y.push_back(0);
    z.push_back(0);
    for(int i=1;i<N;i++){
        if(i%3==0){
            x.push_back(x[x.size()-1]+S[i]);
        }
        else if(i%3==1){
            y.push_back(y[y.size()-1]+S[i]);
        }
        else if(i%3==2){
            z.push_back(z[z.size()-1]+S[i]);
        }
    }
    //a>=xi-y(i+1)
    //b>=yi-zi
    //a+b<=xi-zi
    long min_a=0;
    long min_b=0;

    for(long i=0;i<min(x.size(),y.size()-1);i++){
        if(x[i]-y[i+1]>min_a){
            min_a=x[i]-y[i+1];
        }
    }
    for(long i=0;i<min(y.size(),z.size());i++){
        if(y[i]-z[i]>min_b){
            min_b=y[i]-z[i];
        }
    }
    if(S[0]-min_a-min_b<0){
        cout<<"No"<<endl;
        return 0;
    }
    long Ai = min_a;
    long Ai1 = min_b;
    long Ai2 = S[0]-min_a-min_b;
    stringstream ss;
    ss.str("");
    ss<<min_a<<" "<<min_b<<" ";
    for(long i=0;i<N;i++){
        Ai2 = S[i]-Ai-Ai1;
        if(Ai2<0){
            cout<<"No"<<endl;
            return 0;
        }
        ss<<Ai2;
        if(i<N-1){
            ss<<" ";
        }
        Ai=Ai1;
        Ai1=Ai2;
    }
    cout<<"Yes"<<endl;
    cout<<ss.str()<<endl;;
    return 0;
}