# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
        long int n,l;
        cin>>n;
        long int m,M,s;
        M= (-1000000);
        m=1000000;
        s=0;
        for(int i=0; cin>>l; i++) {
                s+=l;
                m=min(m,l);
                M=max(M,l);
        }

        cout<<m<<" "<<M<<" "<<s<<endl;
        return 0;
}
