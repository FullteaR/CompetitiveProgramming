#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
        int counter=0;
        string W;
        string T;
        cin>>W;
        int len_W=(int)W.length();
        int len_T;
        while(1) {
                cin>>T;
                len_T=(int)T.length();
                if(T=="END_OF_TEXT") {
                        cout<<(int)counter<<endl;
                        return 0;
                }
                transform(T.begin(),T.end(),T.begin(),::tolower);
                if(T==W){
                    counter+=1;
                }
        }
}
