#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define INF 1000000010

class Node{
  private:
    int id;
    int parent;
    int depth;
    string getType();
  public:
    Node();
    void setId(int id);
    int getId();
    void setParent(int parent);
    int getParent();
    void print();
    void push_child(int c);
    void setDepth(int d);
    vector<int> c;
};

Node::Node(){
  id=0;
  parent=-1;
  depth=INF;
  c.clear();
};

string Node::getType(){
  if(parent==-1){
    return "root";
  }
  else if(c.empty()){
    return "leaf";
  }
  else{
    return "internal node";
  }
}

void Node::setId(int _id){
  id = _id;
}

int Node::getId(){
  return id;
}

void Node::setParent(int _parent){
  parent = _parent;
}


void Node::setDepth(int d){
  depth = d;
}

int Node::getParent(){
  return parent;
}

void Node::push_child(int _c){
  c.push_back(_c);
}

void Node::print(){
  string childs="";
  for(int i=0;i<(int)c.size();i++){
    childs+=to_string(c[i]);
    if(i<(int)c.size()-1){
      childs+=", ";
    }
  }
  printf("node %d: parent = %d, depth = %d, %s, [%s]\n",id,parent,depth,getType().c_str(),childs.c_str());
}

int main(void){
  int n;
  cin>>n;
  Node* tree = new Node[n];
  for(int i=0;i<n;i++){
    tree[i].setId(i);
  }
  for(int i=0;i<n;i++){
    int id,k;
    cin>>id>>k;
    for(int j=0;j<k;j++){
      int c;
      cin>>c;
      tree[id].push_child(c);
      tree[c].setParent(id);
    }
  }
  int root=0;
  for(int i=0;i<n;i++){
    if(tree[i].getParent()==-1){
      root=i;
      break;
    }
  }

  vector<int> childs = tree[root].c;
  int depth=0;
  tree[root].setDepth(depth);
  while(!childs.empty()){
    depth++;
    vector<int> _childs;
    _childs.clear();
    for(auto iter=childs.begin();iter!=childs.end();iter++){
      for(auto iter2=tree[*iter].c.begin();iter2!=tree[*iter].c.end();iter2++){
        _childs.push_back(*iter2);
      }
      tree[*iter].setDepth(depth);
    }
    childs.clear();
    for(auto iter=_childs.begin();iter!=_childs.end();iter++){
      childs.push_back(*iter);
    }
  }

  for(int i=0;i<n;i++){
    tree[i].print();
  }

  return 0;
}
