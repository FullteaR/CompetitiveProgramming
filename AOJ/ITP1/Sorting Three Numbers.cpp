#include <iostream>
using namespace std;
int main(void){
        int a,b,c;
        cin>>a>>b>>c;
        int Min=0;
        int Mid=0;
        int Max=0;
        if(a<=b && b<=c){
            Min=a;
            Mid=b;
            Max=c;
        }
        else if(a<=c && c<=b){
            Min=a;
            Mid=c;
            Max=b;
        }
        else if(b<=a && a<=c){
            Min=b;
            Mid=a;
            Max=c;
        }
        else if(b<=c && c<=a){
            Min=b;
            Mid=c;
            Max=a;
        }
        else if(c<=a && a<=b){
            Min=c;
            Mid=a;
            Max=b;
        }
        else if(c<=b && b<=a){
            Min=c;
            Mid=b;
            Max=a;
        }
        cout<<Min<<" "<<Mid<<" "<<Max<<endl;
        return 0;
}
