#include <iostream>
using namespace std;

int main(void) {
    int H, W;
    cin>>H>>W;
    int** A = new int*[H];
    for(int h=0;h<H;h++){
        A[h] = new int[W];
        for(int w=0;w<W;w++){
            cin>>A[h][w];
        }
    }
    int* sum_h = new int[H];
    int* sum_w = new int[W];
    for(int h=0;h<H;h++){
        sum_h[h] = 0;
        for(int w=0;w<W;w++){
            sum_h[h] +=A[h][w];
        }
    }

    for(int w=0;w<W;w++){
        sum_w[w] = 0;
        for(int h=0;h<H;h++){
            sum_w[w] +=A[h][w];
        }
    }
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            int B = sum_h[h]+sum_w[w]-A[h][w];
            cout<<B;
            if(w<W-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;   
}