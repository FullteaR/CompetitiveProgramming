//http://www.ipsj.or.jp/07editj/promenade/4304.pdfを参照

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rectangularSearching(short** table,int W,int H);

struct rect{
  unsigned short w;
  unsigned short h;
  bool operator<(const rect &another) const{
    return w*20000+h<another.w*20000+another.h;
  };
  bool operator==(const rect &another) const{
    return w==another.w and h==another.h;
  };
};


int main(void){
  int W,H;
  string s;
  while(1){
    cin>>H>>W;
    if(H==0 and W==0)break;
    short** table;
    table=(short **)malloc(sizeof(short*)*(H+2));
    for(int i=0;i<H+2;i++){
      table[i]=(short*)malloc(sizeof(short)*(W+2));
    }
    for(int i=0;i<H+2;i++){
      table[i][0]=0;
      table[i][W+1]=0;
    }
    for(int j=0;j<W+2;j++){
      table[0][j]=0;
      table[H-1][j]=0;
    }

    for(int i=0;i<H;i++){
      cin>>s;
      for(int j=0;j<W;j++){
        if(s[j]=='*'){
          table[i+1][j+1]=0;
        }
        else{
          table[i+1][j+1]=1;
        }
      }
    }
    cout<<rectangularSearching(table,W,H)<<endl;
    for(int i=0;i<H+2;i++){
      free(table[i]);
    }
    free(table);
  }
  return 0;
}

int rectangularSearching(short** table,int W,int H){
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
        unsigned short height=0;
        while(table[i+1-height][j+1]==1){
          height++;
        }
        rect r;
        r.h=height;
        r.w=1;
        dp[i][j].push_back(r);
      }
      else if(table[i+1][j]==1 and table[i][j+1]==0){
        unsigned short width=0;
        while(table[i+1][j+1-width]==1){
          width++;
        }
        rect r;
        r.h=1;
        r.w=width;
        dp[i][j].push_back(r);
      }
      else{
        unsigned short width=0;
        while(table[i+1][j-width+1]==1){
          width++;
        }
        unsigned short height=0;
        while(table[i-height+1][j+1]==1){
          height++;
        }

        vector<rect> tmp;
        tmp.clear();
        tmp.shrink_to_fit();
        for(unsigned short k=0;k<dp[i][j-1].size();k++){
          rect r;
          unsigned short h=min(dp[i][j-1][k].h,height);
          unsigned short w=dp[i][j-1][k].w+1;
          r.h=h;
          r.w=w;
          tmp.push_back(r);
        }
        for(int k=0;k<dp[i-1][j].size();k++){
          rect r;
          unsigned short h=dp[i-1][j][k].h+1;
          unsigned short w=min(dp[i-1][j][k].w,width);
          r.h=h;
          r.w=w;
          tmp.push_back(r);
        }
        /*
        rect r,r2;
        for(int k=0;k<tmp.size();k++){
          r=tmp[k];
          bool contain=true;
          for(int l=0;l<tmp.size();l++){
            if(k==l)continue;
            r2=tmp[l];
            if(r.w<r2.w and r.h<r2.h){
              contain=false;
              break;
            }
          }
          if(contain){
            dp[i][j].push_back(r);
          }
        }
        */
        sort(tmp.begin(),tmp.end());
        tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());

        dp[i][j]=tmp;
      }
      vector<rect> v=dp[i][j];
      for(int k=0;k<v.size();k++){
        retval=max((int)v[k].h*(int)v[k].w,retval);
      }
      if(i>=1){
        dp[i-1][j].clear();
        dp[i-1][j].shrink_to_fit();
      }
    }
  }

  return retval;
}
