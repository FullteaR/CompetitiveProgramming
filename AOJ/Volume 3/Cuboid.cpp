#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(void){
    vector<pair<int, int> > v;
    v.clear();
    for(int i=0;i<6;i++){
        int h,w;
        cin>>h>>w;
        v.push_back(make_pair(min(h,w),max(h,w)));
    }

    map<pair<int, int>, int> mp;
    for(pair<int, int> _v : v){
        mp[_v] = 0;
    }
    for(pair<int, int> _v : v){
        mp[_v] += 1;
    }
    for(pair<int, int> _v : v){
        if(mp[_v]%2!=0){
            cout<<"no"<<endl;
            return 0;
        }
    }

    if(mp.size()==1){
        int length = v[0].first;
        for(int i=0;i<6;i++){
            if(v[i].first != length or v[i].second!=length){
                cout<<"no"<<endl;
                return 0;
            }
        }
        cout<<"yes"<<endl;
        return 0;
    }
    else if(mp.size()==2){
        set<pair<int, int> > areas;
        areas.clear();
        for(pair<int, int> _v : v){
            areas.insert(_v);
        }
        int square_length=-1;
        for(pair<int, int> a : areas){
            if(mp[a]==2){
                int h = a.first;
                int w = a.second;
                if(h!=w){
                    cout<<"no"<<endl;
                    return 0;
                }
                square_length = h;
                break;
            }
        }
        for(pair<int, int> a : areas){
            if(mp[a]==4){
                int h = a.first;
                int w = a.second;
                if(h!=square_length and w!=square_length){
                    cout<<"no"<<endl;
                    return 0;
                }
            }
        }
        cout<<"yes"<<endl;
        return 0;
    }
    else if(mp.size()==3){
        map<int, int> counts;
        set<int> lines;
        lines.clear();
        for(pair<int, int> _v : v){
            int h = _v.first;
            int w = _v.second;
            if(h==w){
                cout<<"no"<<endl;
                return 0;
            }
            lines.insert(h);
            lines.insert(w);
            counts[h] = 0;
            counts[w] = 0;
        }
        for(pair<int, int> _v : v){
            int h = _v.first;
            int w = _v.second;
            counts[h] += 1;
            counts[w] += 1;
        }
        if(lines.size()!=3){
            cout<<"no"<<endl;
            return 0;
        }
        for(int l:lines){
            if(counts[l]!=4){
                cout<<"no"<<endl;
                return 0;
            }
        }
        cout<<"yes"<<endl;
        return 0;
    }
    else{
        cout<<"no"<<endl;
        return 0;
    }


    return 0;
}