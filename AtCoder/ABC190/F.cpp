#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
long merge_cnt(vector<long> &a);

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long N;
  cin>>N;
  long* a = new long[N];
  vector<long> aa;
  aa.clear();
  for(long i=0;i<N;i++){
    cin>>a[i];
    aa.push_back(a[i]);
  }
  /*
  vector<long> exist;
  exist.clear();
  long trans=0;
  for(long i=0;i<N;i++){
    long index=lower_bound(exist.begin(),exist.end(),a[i])-exist.begin();
    trans+=exist.size()-index;
    exist.insert(exist.begin()+index, a[i]);
  }
  */
  long trans = merge_cnt(aa);
  printf("%ld\n", trans);
  for(long i=0;i<N-1;i++){
    trans+=N-1-2*a[i];
    printf("%ld\n", trans);
  }
  return 0;
}

//https://kira000.hatenadiary.jp/entry/2019/02/23/053917
long merge_cnt(vector<long> &a) {
    long n = a.size();
    if (n <= 1) { return 0; }

    long cnt = 0;
    vector<long> b(a.begin(), a.begin()+n/2);
    vector<long> c(a.begin()+n/2, a.end());

    cnt += merge_cnt(b);
    cnt += merge_cnt(c);

    long ai = 0, bi = 0, ci = 0;
    // merge の処理
    while (ai < n) {
        if ( bi < b.size() && (ci == c.size() || b[bi] <= c[ci]) ) {
            a[ai++] = b[bi++];
        } else {
            cnt += n / 2 - bi;
            a[ai++] = c[ci++];
        }
    }
    return cnt;
}
