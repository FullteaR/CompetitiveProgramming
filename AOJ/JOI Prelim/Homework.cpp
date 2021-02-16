#include <iostream>
using namespace std;

int days(int pages, int max_pages);

int main(void){
  int L,A,B,C,D;
  cin>>L;
  cin>>A;
  cin>>B;
  cin>>C;
  cin>>D;
  cout<<L-max(days(A,C),days(B,D))<<endl;
}

int days(int pages, int max_pages){
  if(pages%max_pages==0){
    return pages/max_pages;
  }
  else{
    return pages/max_pages + 1;
  }
}
