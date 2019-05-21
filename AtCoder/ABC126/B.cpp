#include <iostream>
using namespace std;

int main(void){
        int S;
        int zenhan,kouhan;
        bool YYMM,MMYY;
        cin>>S;
        zenhan=S/100;
        kouhan=S%100;
        if(1<=kouhan and kouhan<=12) YYMM=true;
        else YYMM=false;
        if(1<=zenhan and zenhan<=12) MMYY=true;
        else MMYY=false;
        if(MMYY and YYMM) cout<<"AMBIGUOUS"<<endl;
        else if(MMYY) cout<<"MMYY"<<endl;
        else if(YYMM) cout<<"YYMM"<<endl;
        else cout<<"NA"<<endl;
        return 0;
}
