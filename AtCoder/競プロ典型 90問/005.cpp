#include <iostream>
using namespace std;
#define MOD 1000000007

void mut(long** A, long** B, long N, long** ret);
void pow(long** A, long N, long m, long** ret);

int main(void){
    long N,B,K;
    cin>>N>>B>>K;
    long* c = new long[K];
    for(long i=0;i<K;i++){
        cin>>c[i];
    }

    long** conv = new long*[B];
    long** mat = new long*[B];
    for(long i=0;i<B;i++){
        conv[i] = new long[B];
        mat[i] = new long[B];
        for(long j=0;j<B;j++){
            conv[i][j] = 0;
            for(long k=0;k<K;k++){
                if((10*j+c[k])%B == i){
                    conv[i][j]+=1;
                }
            }
        }
    }

    pow(conv, B, N, mat);

    cout<<mat[0][0]<<endl;

    return 0;
}

void mut(long** A, long** B, long N, long** ret){
    for(long i=0;i<N;i++){
        for(long j=0;j<N;j++){
            ret[i][j] = 0;
            for(long k=0;k<N;k++){
                ret[i][j] += A[i][k]*B[k][j];
                ret[i][j] = ret[i][j] % MOD;
            }
        }
    }
}

void pow(long** A, long N, long m, long** ret){

    if(m==0){
        for(long i=0;i<N;i++){
            for(long j=0;j<N;j++){
                if(i==j){
                    ret[i][j] = 1;
                }
                else{
                    ret[i][j] = 0;
                }
            }
        }
        return;
    }

    long** P = new long*[N];
    for(long i=0;i<N;i++){
        P[i] = new long[N];
    }

    if(m%2==0){
        pow(A,N,m/2,P);
        mut(P,P,N,ret);
    }
    else{
        pow(A,N,m-1,P);
        mut(A,P,N,ret);
    }
    return;
}
