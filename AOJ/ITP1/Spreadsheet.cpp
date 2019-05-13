#include <iostream>
using namespace std;

int main(void){
        int r,c;
        int** sheet;
        int* row;
        cin>>r>>c;
        sheet= new int*[r+1];
        for(int i=0; i<r+1; i++) {
                row = new int[c+1];
                sheet[i]=row;
                if(i<r) {
                        for(int j=0; j<c; j++) {
                                cin>>sheet[i][j];
                        }
                        sheet[i][c]=0;
                }
                else{
                        for(int j=0; j<c+1; j++) {
                                sheet[i][j]=0;
                        }
                }
        }


        for(int j=0; j<c; j++) {
                for(int i=0; i<r; i++) {
                        sheet[r][j]+=sheet[i][j];
                }
        }

        for(int i=0; i<r+1; i++) {
                for(int j=0; j<c; j++) {
                        sheet[i][c]+=sheet[i][j];
                }
        }

        for(int i=0; i<r+1; i++) {
                for(int j=0; j<c+1; j++) {
                        if(j<c) {
                                cout<<sheet[i][j]<<" ";
                        }
                        else{
                                cout<<sheet[i][j]<<endl;
                        }
                }

        }
        return 0;
}
