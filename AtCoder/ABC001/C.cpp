#include <iostream>
using namespace std;

int main(void){
        long double Deg,Dis;
        cin>>Deg>>Dis;

        int W=0;
        Dis=Dis/60.0;
        if(100*Dis-((int)(10*Dis))*10>=5){
          Dis+=0.1;
        }
        Dis=((double)(int)(10*Dis))/10.0;
        if (Dis<=0.2) {
                W=0;
        }
        else if(Dis<=1.5) {
                W=1;
        }
        else if(Dis<=3.3) {
                W=2;
        }
        else if(Dis<=5.4) {
                W=3;
        }
        else if(Dis<=7.9) {
                W=4;
        }
        else if(Dis<=10.7) {
                W=5;
        }
        else if(Dis<=13.8) {
                W=6;
        }
        else if(Dis<=17.1) {
                W=7;
        }
        else if(Dis<=20.7) {
                W=8;
        }
        else if(Dis<=24.4) {
                W=9;
        }
        else if(Dis<=28.4) {
                W=10;
        }
        else if(Dis<=32.6) {
                W=11;
        }
        else{
                W=12;
        }


        if(W==0) {
                cout<<"C 0"<<endl;
        }
        else{

                if (112.5<=Deg && Deg<337.5) {
                        cout << "NNE";
                }
                else if(Deg>=337.5 && Deg<562.5) {
                        cout << "NE";
                }
                else if(Deg>=562.5 && Deg<787.5) {
                        cout << "ENE";
                }
                else if(Deg>=787.5 && Deg<1012.5) {
                        cout << "E";
                }
                else if(Deg>=1012.5 && Deg<1237.5) {
                        cout << "ESE";
                }
                else if(Deg>=1237.5 && Deg<1462.5) {
                        cout << "SE";
                }
                else if(Deg>=1462.5 && Deg<1687.5) {
                        cout << "SSE";
                }
                else if(Deg>=1687.5 && Deg<1912.5) {
                        cout << "S";
                }
                else if(Deg>=1912.5 && Deg<2137.5) {
                        cout << "SSW";
                }
                else if(Deg>=2137.5 && Deg<2362.5) {
                        cout << "SW";
                }
                else if(Deg>=2362.5 && Deg<2587.5) {
                        cout << "WSW";
                }
                else if(Deg>=2587.5 && Deg<2812.5) {
                        cout << "W";
                }
                else if(Deg>=2812.5 && Deg<3037.5) {
                        cout << "WNW";
                }
                else if(Deg>=3037.5 && Deg<3262.5) {
                        cout << "NW";
                }
                else if(Deg>=3262.5 && Deg<3487.5) {
                        cout << "NNW";
                }
                else{
                        cout << "N";
                }

                cout << " "<<W<<endl;
        }
        return 0;
}
