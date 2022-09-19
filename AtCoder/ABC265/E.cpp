//dp[n][p][q] : n回のワープのうちワープ1をp回, ワープ2をq回行った移動経路の総数

#include <iostream>
#include <set>
#include <utility>
#include <cassert>
#define MOD 998244353
using namespace std;

bool find(set<pair<long,long> >& objects, long x, long y);

int main(void) {
    int N;
    long M;
    cin>>N>>M;
    long A,B,C,D,E,F;
    cin>>A>>B>>C>>D>>E>>F;
    set<pair<long,long> > objects;
    objects.clear();
    for(long i=0;i<M;i++) {
        long X,Y;
        cin>>X>>Y;
        objects.insert(make_pair(X,Y));
    }

    long*** dp = new long**[N+1];
    for(long n=0;n<=N;n++) {
        dp[n] = new long*[N+1];
        for(long p=0;p<=N;p++) {
            dp[n][p] = new long[N+1];
            for(long q=0;q<=N;q++) {
                dp[n][p][q] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    for(long n=0;n<N;n++) {
        for(long p=0;p<=N;p++){
            for(long q=0;p+q<=n;q++){
                long r = n - (p+q);
                assert(r>=0);
                long pos_x = A*p+C*q+E*r;
                long pos_y = B*p+D*q+F*r;
                if(!find(objects, pos_x+A, pos_y+B)) {
                    dp[n+1][p+1][q] += dp[n][p][q];
                    dp[n+1][p+1][q] = dp[n+1][p+1][q]%MOD;
                }
                if(!find(objects, pos_x+C, pos_y+D)) {
                    dp[n+1][p][q+1] += dp[n][p][q];
                    dp[n+1][p][q+1] = dp[n+1][p][q+1]%MOD;
                }
                if(!find(objects, pos_x+E, pos_y+F)) {
                    dp[n+1][p][q] += dp[n][p][q];
                    dp[n+1][p][q] = dp[n+1][p][q]%MOD;
                }
            }
        }
    }
    long retval = 0;
    for(long p=0;p<=N;p++) {
        for(long q=0;p+q<=N;q++) {
            retval += dp[N][p][q];
            retval = retval%MOD;
        }
    }
    cout<<retval<<endl;
}


bool find(set<pair<long,long> >& objects, long x, long y) {
    return objects.find(make_pair(x,y))!=objects.end();
}