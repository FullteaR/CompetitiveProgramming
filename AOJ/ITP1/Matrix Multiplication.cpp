#include <iostream>
using namespace std;

int main(void){
        int n,m,l;
        cin>>n>>m>>l;
        long** A;
        long** B;
        long** C;
        long* rowA;
        long* rowB;
        long* rowC;
        A=new long*[n];
        B=new long*[m];
        C=new long*[n];
        for(int i=0; i<n; i++) {
                rowA =new long[m];
                A[i]=rowA;
                for(int j=0; j<m; j++) {
                        cin>>A[i][j];
                }
        }
        for(int i=0; i<m; i++) {
                rowB =new long[l];
                B[i]=rowB;
                for(int j=0; j<l; j++) {
                        cin>>B[i][j];
                }
        }
        for(int i=0; i<n; i++) {
                rowC =new long[l];
                C[i]=rowC;
                for(int j=0; j<l; j++) {
                        C[i][j]=0;
                }
        }

        for(int i=0; i<n; i++) {
                for(int j=0; j<l; j++) {
                        for(int k=0; k<m; k++) {
                                C[i][j]+=A[i][k]*B[k][j];
                        }
                }
        }


        for(int i=0; i<n; i++) {
                for(int j=0; j<l; j++) {
                        if(j<l-1) {
                                cout<<C[i][j]<<" ";
                        }
                        else{
                                cout<<C[i][j]<<endl;
                        }
                }
        }

        return 0;

}
