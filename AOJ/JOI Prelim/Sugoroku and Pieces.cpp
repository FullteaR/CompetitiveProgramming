#include <iostream>
using namespace std;

int place(int i,int* sugoroku);

int main(void){
    int sugoroku[2020]={0};
    int X;
    int A;
    int N,M;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>X;
        sugoroku[X]=1;
    }
    int p;
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>A;
        p=place(A,sugoroku);
        if(p==2019);
        else if(sugoroku[p+1]==0){
            sugoroku[p]=0;
            sugoroku[p+1]=1;
        }
    }
    for(int i=1;i<=N;i++){
        cout<<place(i,sugoroku)<<endl;
    }
    return 0;
}

int place(int i,int* sugoroku){
    int count=0;
    for(int j=0;j<2020;j++){
        count+=sugoroku[j];
        if(count==i){return j;}
    }
}
