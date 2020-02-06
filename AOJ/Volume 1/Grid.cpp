#include <iostream>
using namespace std;

int main(void){
  int n;
  string l;
  int retval;
  int r,d,ld,rd;
  while(1){
    cin>>n;
    if(n==0)break;
    int grid[n+2][n+2];
    for(int i=0;i<n+2;i++){
      grid[i][0]=0;
      grid[0][i]=0;
      grid[i][n+1]=0;
      grid[n+1][i]=0;
    }
    for(int i=1;i<n+1;i++){
      cin>>l;
      for(int j=1;j<n+1;j++){
        grid[i][j]=l[j-1];
      }
    }
    retval=0;
    for(int i=1;i<n+1;i++){
      for(int j=1;j<n+1;j++){
        if(grid[i][j]=='0')continue;

        d=0;
        while(1){
          if(grid[i+d][j]=='1'){
            d++;
          }
          else{
            break;
          }
        }
        retval=max(retval,d);
        r=0;
        while(1){
          if(grid[i][j+r]=='1'){
            r++;
          }
          else{
            break;
          }
        }
        retval=max(retval,r);

        ld=0;
        while(1){
          if(grid[i+ld][j-ld]=='1'){
            ld++;
          }
          else{
            break;
          }
        }
        retval=max(retval,ld);

        rd=0;
        while(1){
          if(grid[i+rd][j+rd]=='1'){
            rd++;
          }
          else{
            break;
          }
        }
        retval=max(retval,rd);
      }
    }
    cout<<retval<<endl;
  }
}
