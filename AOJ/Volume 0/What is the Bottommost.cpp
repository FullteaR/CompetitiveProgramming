#include <iostream>
#include <vector>
using namespace std;

int main(void){
  string s;
  while(cin>>s){
    vector<int> row;
    for(int i=0;i<10;i++){
      row.push_back(s[i]-'0');
    }

    while(row.size()>1){
      vector<int> under;
      for(int i=0;i<row.size()-1;i++){
        under.push_back(row[i]+row[i+1]);
      }
      row=under;
    }
    cout<<row[0]%10<<endl;

  }
  return 0;
}
