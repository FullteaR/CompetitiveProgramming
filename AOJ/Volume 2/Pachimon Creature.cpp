#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
#define INF 1000010

pair<int,int> get(int W, int H, char** c);

struct Pachimon {
        int x;
        int y;
        int dist;
        bool operator==(const Pachimon &p) const {
                return x==p.x and y==p.y and dist==p.dist;
        }
        bool operator<(const Pachimon &p) const {
                if(x<p.x) return true;
                else if(x>p.x) return false;
                else if(y<p.y) return true;
                else if(y>p.y) return false;
                else return (dist<p.dist);
        }
} typedef Pachimon;

int distance(Pachimon p1, Pachimon p2);


int main(void){
        while(1) {
                int W,H;
                cin>>W>>H;
                if(W==0 and H==0) {break;}
                char** c=new char*[H];
                for(int i=0; i<H; i++) {
                        c[i]=new char[W];
                }
                for(int i=0; i<H; i++) {
                        for(int j=0; j<W; j++) {
                                cin>>c[i][j];
                        }
                }
                auto p=get(W,H,c);
                if(p.second==INF) {
                        cout<<"NA"<<endl;
                }
                else{
                        cout<<p.first+1<<" "<<p.second<<endl;
                }
                for(int i=0; i<H; i++) {
                        delete[] c[i];
                }
                delete[] c;
        }
        return 0;
}


pair<int,int> get(int W,int H, char** c){
        vector<Pachimon>* pachimons = new vector<Pachimon> [5];
        Pachimon S,G;
        for(int i=0; i<5; i++) {
                pachimons[i].clear();
        }

        for(int i=0; i<H; i++) {
                for(int j=0; j<W; j++) {
                        switch(c[i][j]) {
                                Pachimon p;
                        case '1':
                                p.x=i;
                                p.y=j;
                                p.dist=INF;
                                pachimons[0].push_back(p);
                                break;
                        case '2':
                                p.x=i;
                                p.y=j;
                                p.dist=INF;
                                pachimons[1].push_back(p);
                                break;
                        case '3':
                                p.x=i;
                                p.y=j;
                                p.dist=INF;
                                pachimons[2].push_back(p);
                                break;
                        case '4':
                                p.x=i;
                                p.y=j;
                                p.dist=INF;
                                pachimons[3].push_back(p);
                                break;
                        case '5':
                                p.x=i;
                                p.y=j;
                                p.dist=INF;
                                pachimons[4].push_back(p);
                                break;
                        case 'S':
                                S.x=i;
                                S.y=j;
                                S.dist=0;
                                break;
                        case 'G':
                                G.x=i;
                                G.y=j;
                                G.dist=INF;
                                break;
                        default:
                                ;
                        }
                }
        }

        int retval=INF;
        int min_first_select;
        for(int first_select=0; first_select<5; first_select++) {
                for(int i=0; i<5; i++) {
                        for(auto iter=pachimons[i].begin(); iter!=pachimons[i].end(); iter++) {
                                (*iter).dist=INF;
                        }
                }
                G.dist=INF;
                for(auto iter=pachimons[(first_select+1)%5].begin(); iter!=pachimons[(first_select+1)%5].end(); iter++) {
                        (*iter).dist=min((*iter).dist,distance(S,*iter));
                }
                for(int i=0; i<5; i++) {
                        for(auto iter=pachimons[(first_select+1+i)%5].begin(); iter!=pachimons[(first_select+1+i)%5].end(); iter++) {
                                for(auto iter2=pachimons[(first_select+1+i+1)%5].begin(); iter2!=pachimons[(first_select+1+i+1)%5].end(); iter2++) {
                                        (*iter2).dist=min((*iter2).dist,distance(*iter,*iter2));
                                }
                        }
                }
                for(auto iter=pachimons[(first_select+4)%5].begin(); iter!=pachimons[(first_select+4)%5].end(); iter++) {
                        G.dist=min(G.dist,distance(*iter,G));
                }
                if(G.dist<retval){
                  min_first_select=first_select;
                  retval=G.dist;
                }
        }

        return make_pair(min_first_select,retval);

};

int distance(Pachimon p1, Pachimon p2){
  return abs(p1.x - p2.x) + abs(p1.y - p2.y) + p1.dist;
}
