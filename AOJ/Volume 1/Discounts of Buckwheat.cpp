#include <iostream>
using namespace std;



int main(void){
        int n;
        int price;
        while(1) {
                cin>>n;
                if(n==0) return 0;
                double price=1000000;


                for(int a=0; a<=(5000/200)+1; a++) {
                        for(int b=0; b<=(5000/300)+1; b++) {
                                for(int c=0; c<=(5000/500)+1; c++) {
                                        if(a*200+b*300+c*500 !=n) continue;

                                        price=min(price,(a%5)*380+(a/5)*5*380*0.8+(b%4)*550+(b/4)*4*550*0.85+(c%3)*850+(c/3)*3*850*0.88);

                                }
                        }
                }
                cout<<price<<endl;

        }
}
