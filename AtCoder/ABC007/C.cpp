#include <iostream>
#include <set>
#include <utility>
using namespace std;
#define INF 1000000010

int main(void) {
    long R,C;
    cin>>R>>C;
    long sy, sx, gy, gx;
    cin>>sy>>sx;
    cin>>gy>>gx;
    sy--;
    sx--;
    gy--;
    gx--;
    char** maze = new char*[R];
    long** dist = new long*[R];
    for(int i=0;i<R;i++){
        maze[i] = new char[C];
        dist[i] = new long[C];
        for(int j=0;j<C;j++){
            cin>>maze[i][j];
            dist[i][j] = INF;
        }
    }
    set<pair<int, int> > edges;
    edges.clear();
    edges.insert(make_pair(sx, sy));
    dist[sy][sx] = 0;
    while(edges.size()!=0){
        set<pair<int, int> > nexts;
        nexts.clear();
        for(pair<int, int> edge : edges) {
            long distance_now = dist[edge.second][edge.first];
            long x,y;
            x=edge.first;
            y=edge.second-1;
            if(maze[y][x]=='.' and dist[y][x]>distance_now+1) {
                dist[y][x] = distance_now+1;
                nexts.insert(make_pair(x,y));
            }

            x=edge.first;
            y=edge.second+1;
            if(maze[y][x]=='.' and dist[y][x]>distance_now+1) {
                dist[y][x] = distance_now+1;
                nexts.insert(make_pair(x,y));
            }

            x=edge.first-1;
            y=edge.second;
            if(maze[y][x]=='.' and dist[y][x]>distance_now+1) {
                dist[y][x] = distance_now+1;
                nexts.insert(make_pair(x,y));
            }

            x=edge.first+1;
            y=edge.second;
            if(maze[y][x]=='.' and dist[y][x]>distance_now+1) {
                dist[y][x] = distance_now+1;
                nexts.insert(make_pair(x,y));
            }
        }
        edges.clear();
        for(pair<int,int> next : nexts) {
            edges.insert(next);
        }
    }

    cout<<dist[gy][gx]<<endl;
    return 0;
}