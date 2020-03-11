#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int squareSearching(int** table,int W,int H);

struct rect{
  int w;
  int h;
  bool operator<(const rect &another) const{
    return w*10000+h<another.w*10000+another.h;//w,h<1000
  };
  bool operator==(const rect &another) const{
    return w==another.w and h==another.h;
  };
};


int main(void){
  int n;
  char s[1020];
  while(1){
    cin>>n;
    if(n==0)break;
    int** table;
    table=(int **)malloc(sizeof(int*)*(n+2));
    for(int i=0;i<n+2;i++){
      table[i]=(int*)malloc(sizeof(int)*(n+2));
    }
    for(int i=0;i<n+2;i++){
      table[i][0]=0;
      table[i][n+1]=0;
    }
    for(int j=0;j<n+2;j++){
      table[0][j]=0;
      table[n-1][j]=0;
    }

    for(int i=0;i<n;i++){
      scanf("%s",s);
      for(int j=0;j<n;j++){
        if(s[j]=='*'){
          table[i+1][j+1]=0;
        }
        else{
          table[i+1][j+1]=1;
        }
      }
    }
    cout<<squareSearching(table,n,n)<<endl;

  }
  return 0;
}

int squareSearching(int** table,int W,int H){
  vector<rect> dp[H][W];
  int retval=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(table[i+1][j+1]==0){
        continue;
      }

      if(table[i+1][j]==0 and table[i][j+1]==0){
        rect r;
        r.h=1;
        r.w=1;
        dp[i][j].push_back(r);
      }
      else if(table[i+1][j]==0 and table[i][j+1]==1){
        int height=0;
        vector<rect> v;
        v=dp[i-1][j];
        rect tmp;
        for(int k=0;k<v.size();k++){
          tmp=v[k];
          height=max(height,tmp.h);
        }
        if(v.empty()==false){
          height++;
        }
        rect r;
        r.h=height;
        r.w=1;
        dp[i][j].push_back(r);
      }
      else if(table[i+1][j]==1 and table[i][j+1]==0){
        int width=0;
        vector<rect> v;
        v=dp[i][j-1];
        rect tmp;
        for(int k=0;k<v.size();k++){
          tmp=v[k];
          width=max(width,tmp.w);
        }
        if(v.empty()==false){
          width++;
        }


        rect r;
        r.h=1;
        r.w=width;
        dp[i][j].push_back(r);
      }
      else{
        int width=0;
        vector<rect> v;
        rect tmp2;
        v=dp[i][j-1];
        for(int k=0;k<v.size();k++){
          tmp2=v[k];
          width=max(width,tmp2.w);
        }
        if(v.empty()==false){
          width++;
        }

        int height=0;
        v=dp[i-1][j];
        for(int k=0;k<v.size();k++){
          tmp2=v[k];
          height=max(height,tmp2.h);
        }
        if(v.empty()==false){
          height++;
        }

        vector<rect> tmp;
        for(int k=0;k<dp[i][j-1].size();k++){
          rect r;
          int h=min(dp[i][j-1][k].h,height);
          int w=dp[i][j-1][k].w+1;
          r.h=h;
          r.w=w;
          tmp.push_back(r);
        }
        for(int k=0;k<dp[i-1][j].size();k++){
          rect r;
          int h=dp[i-1][j][k].h+1;
          int w=min(dp[i-1][j][k].w,width);
          r.h=h;
          r.w=w;
          tmp.push_back(r);
        }
        sort(tmp.begin(),tmp.end());
        tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());

        dp[i][j]=tmp;
      }
      vector<rect> v=dp[i][j];
      for(int k=0;k<v.size();k++){
        retval=max(min((int)v[k].h,(int)v[k].w),retval);
      }

    }
  }

  return retval;
}
