#include <iostream>
using namespace std;

int main(void){
        int d,w,h;
        int size;
        int n,r;
        while(1) {
                cin>>d>>w>>h;
                if(d==0 and w==0 and h==0) return 0;
                cin>>n;
                size=min(d*d+w*w,min(d*d+h*h,w*w+h*h));
                for(int i=0; i<n; i++) {
                        cin>>r;
                        if(size<4*r*r) {//size**0.5<2*r;
                                cout<<"OK"<<endl;
                        }
                        else{
                                cout<<"NA"<<endl;
                        }
                }
        }

}
