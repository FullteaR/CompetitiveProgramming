#include <iostream>
using namespace std;

int main(void){
        int n,x;
        int i,j,k;//i+j+k=x
        int retval;
        while(1) {
                cin>>n>>x;
                retval=0;
                if(n==0 and x==0) {
                        return 0;
                }
                for(i=1;i<=n;i++){
                    for(j=i+1;j<=n;j++){
                        for(k=j+1;k<=n;k++){
                            if(i+j+k==x){
                                retval+=1;
                            }
                        }
                    }
                }
                cout<<retval<<endl;
        }

}
