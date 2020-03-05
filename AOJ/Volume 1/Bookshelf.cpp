#include <iostream>
using namespace std;

bool check(int* books, int width, int m,int n);

int main(void){
  int m,n;
  while(1){
    cin>>m>>n;
    if(m==0 and n==0)break;
    int books[n];
    for(int i=0;i<n;i++){
      cin>>books[i];
    }
    int min=0;
    int max=1500000;
    int mid;
    while(max-min>5){
      mid=(min+max)/2;
      if(check(books,mid,m,n)){
        max=mid;
      }
      else{
        min=mid;
      }
    }
    int retval;
    for(int i=max;i>=min;i--){
      if(check(books,i,m,n)){
        retval=i;
      }
    }
    cout<<retval<<endl;
  }
  return 0;
}


bool check(int* books, int width, int m, int n){
  int row=1;
  int w=0;
  for(int i=0;i<n;i++){
    if(books[i]>width)return false;
    if(w+books[i]<=width){
      w+=books[i];
    }
    else{
      row+=1;
      w=books[i];
    }
  }
  return row<=m;
}
