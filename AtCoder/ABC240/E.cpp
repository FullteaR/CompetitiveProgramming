#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <utility>
using namespace std;

struct node{
    long id;
    node* parent;
    set<node*> children;
    long L;
    long R;
}typedef node;

pair<long,long>* result;
long increment ;

void plant(node* top, map<long, set<long> >& neighbors){
    for(long neighbor : neighbors[top->id]){
        if(neighbor==top->parent->id){
            continue;
        }
        node* leaf = new node();
        leaf->parent = top;
        leaf->id = neighbor;
        top->children.insert(leaf);
        plant(leaf, neighbors);
    }
}

void dig(node* top){
    top->L = increment;
    if((top->children).empty()){
        top->L = increment;
        top -> R = increment;
        increment++;
        result[top->id] = make_pair(top->L, top->R);
        return ;
    }
    for(node* leaf : top->children){
        dig(leaf);
    }
    top->R=increment-1;
    result[top->id] = make_pair(top->L, top->R);
}

int main(void){
    increment = 1;
    long N;
    cin>>N;
    map<long, set<long> > neighbors;
    result = new pair<long, long>[N];
    neighbors.clear();
    for(long i=0;i<N;i++){
        neighbors[i].clear();
    }
    for(long i=0;i<N-1;i++){
        long u,v;
        cin>>u>>v;
        u--;
        v--;
        neighbors[u].insert(v);
        neighbors[v].insert(u);
    }
    node* root = new node();
    root->parent = root;
    root->id = 0;
    root->children.clear();
    plant(root, neighbors);
    dig(root);
    for(long i=0;i<N;i++){
        cout<<result[i].first<<" "<<result[i].second<<endl;
    }
}