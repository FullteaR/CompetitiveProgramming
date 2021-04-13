#include <iostream>
#include <set>
#include <vector>
#include <regex>
using namespace std;

bool check(string S1, string S2, string S3, vector<int>* digits, vector<char>* chars);

int main(void){
  string S1,S2,S3;
  cin>>S1;
  cin>>S2;
  cin>>S3;
  set<char> charsets;
  for(const char& c : S1){
    charsets.insert(c);
  }
  for(const char& c : S2){
    charsets.insert(c);
  }
  for(const char& c : S3){
    charsets.insert(c);
  }
  if(charsets.size()>10){
    cout<<"UNSOLVABLE"<<endl;
    return 0;
  }
  vector<int> digits = {0,1,2,3,4,5,6,7,8,9};
  vector<char> charvecs(charsets.begin(), charsets.end());
  do {
    if(check(S1,S2,S3,&digits,&charvecs)){
      return 0;
    }
  } while(next_permutation(digits.begin(),digits.end()));
  cout<<"UNSOLVABLE"<<endl;
  return 0;
}


bool check(string S1, string S2, string S3, vector<int>* digits, vector<char>* chars){
  if(chars->size()>digits->size()){
    return false;
  }
  for(long i=0;i<(long)(chars->size());i++){
    int d = (*digits)[i];
    char c = (*chars)[i];
    string c_str = {c};
    char d_char = (char)(d+'0');
    while((long)S1.find(c_str)!=-1){
      S1[S1.find(c_str)]=d_char;
    }
    while((long)S2.find(c_str)!=-1){
      S2[S2.find(c_str)]=d_char;
    }
    while((long)S3.find(c_str)!=-1){
      S3[S3.find(c_str)]=d_char;
    }
  }

  if(S1[0]=='0' or S2[0]=='0' or S3[0]=='0'){
    return false;
  }
  if(stol(S1)+stol(S2)==stol(S3)){
    cout<<S1<<endl;
    cout<<S2<<endl;
    cout<<S3<<endl;
    return true;
  }
  return false;
}
