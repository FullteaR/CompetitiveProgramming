#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){
        char s[1210];
        char count[28]={0};
        while(scanf("%s",s,stdin)!=EOF) {
                int i=0;
                while(s[i]) {
                        if('a'<=s[i] and s[i]<='z') {
                                count[s[i]-'a']+=1;
                        }
                        else if('A'<=s[i] and s[i]<='Z') {
                                count[s[i]-'A']+=1;
                        }
                        i++;
                }
        }
        for(int i=0; i<26; i++) {
                printf("%c : %d\n",i+'a',count[i]);
        }
        return 0;

}
